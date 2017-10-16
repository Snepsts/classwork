#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <stack>
#include <map>

using namespace std;

class BST
{
	struct node
	{
		int data;
		node* left;
		node* right;
		int height;

		bool isHeap()
		{
			bool retvar = true;

			if (right && right->data > data)
				retvar = false;

			if (left && left->data > data)
				retvar = false;

			if (retvar) {
				cout << "The node containing " << data << " is a heap.";
				if (right)
					cout << " Right Child = " << right->data << ".";
				if (left)
					cout << " Left Child = " << left->data << ".";
				cout << '\n';
			} else {
				cout << "The node containing " << data << " is NOT a heap.";
				if (right)
					cout << " Right Child = " << right->data << ".";
				if (left)
					cout << " Left Child = " << left->data << ".";
				cout << '\n';
			}

			return retvar;
		}

		void swap_right()
		{
			int temp; //for swapping data & height
			temp = right->data;
			right->data = data;
			data = temp;
			temp = right->height;
			right->height = height;
			height = temp;
		}

		void swap_left()
		{
			int temp; //for swapping data & height
			temp = left->data;
			left->data = data;
			data = temp;
			temp = left->height;
			left->height = height;
			height = temp;
		}

		void sift()
		{
			if (!left) { //if there is no left, upsift right
				swap_right();
			} else if (!right) { //if there is no right, upsift left
				swap_left();
			} else if (right->data > data && left->data > data) {
				if (right->data > left->data) { //swap right
					swap_right();
				} else { //swap left
					swap_left();
				}
			} else if (right->data > data) {
				swap_right();
			} else if (left->data > data) {
				swap_left();
			} else {
				//do nothing
			}
		}
	};

	node* root;

	void makeEmpty(node* t)
	{
		if(t == NULL)
			return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	node* insert(int x, node* t)
	{
		if(t == NULL) {
			t = new node;
			t->data = x;
			t->height = 0;
			t->left = t->right = NULL;
		} else if(x < t->data) {
			t->left = insert(x, t->left);
			if(height(t->left) - height(t->right) == 2)
			{
				if(x < t->left->data)
					t = singleRightRotate(t);
				else
					t = doubleRightRotate(t);
			}
		} else if(x > t->data) {
			t->right = insert(x, t->right);
			if(height(t->right) - height(t->left) == 2) {
				if(x > t->right->data)
					t = singleLeftRotate(t);
				else
					t = doubleLeftRotate(t);
			}
		}

		t->height = max(height(t->left), height(t->right))+1;
		return t;
	}

	node* singleRightRotate(node* &t)
	{
		node* u = t->left;
		t->left = u->right;
		u->right = t;
		t->height = max(height(t->left), height(t->right))+1;
		u->height = max(height(u->left), t->height)+1;
		return u;
	}

	node* singleLeftRotate(node* &t)
	{
		node* u = t->right;
		t->right = u->left;
		u->left = t;
		t->height = max(height(t->left), height(t->right))+1;
		u->height = max(height(t->right), t->height)+1 ;
		return u;
	}

	node* doubleLeftRotate(node* &t)
	{
		t->right = singleRightRotate(t->right);
		return singleLeftRotate(t);
	}

	node* doubleRightRotate(node* &t)
	{
		t->left = singleLeftRotate(t->left);
		return singleRightRotate(t);
	}

	node* findMin(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	node* remove(int x, node* t)
	{
		node* temp;

		// Element not found
		if (t == NULL) {
			cout << "\n\n\nERROR\n\n\n";
			return NULL;
		}

		// Searching for element
		else if (x < t->data)
			t->left = remove(x, t->left);
		else if (x > t->data)
			t->right = remove(x, t->right);

		// Element found with 2 children
		else if(t->left && t->right) {
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data, t->right);
		} else { // With one or zero child
			temp = t;
			if(t->left == NULL)
				t = t->right;
			else if(t->right == NULL)
				t = t->left;
			delete temp;
		}
		if(t == NULL)
			return t;

		t->height = max(height(t->left), height(t->right)) + 1;

		// If node is unbalanced
		// If left node is deleted, right case
		if (height(t->left) - height(t->right) == 2) {
			// right right case
			if (height(t->left->left) - height(t->left->right) == 1)
				return singleLeftRotate(t);
			// right left case
			else
				return doubleLeftRotate(t);
		} else if (height(t->right) - height(t->left) == 2) { // If right node is deleted, left case
			// left left case
			if (height(t->right->right) - height(t->right->left) == 1)
				return singleRightRotate(t);
			// left right case
			else
				return doubleRightRotate(t);
		}
		return t;
	}

	int height(node* t)
	{
		return (t == NULL ? -1 : t->height);
	}

	int getBalance(node* t)
	{
		if (t == NULL)
			return 0;
		else
			return height(t->left) - height(t->right);
	}

	void inorder(node* t)
	{
		if (t == NULL)
			return;
		inorder(t->left);
		cout << t->data << " ";
		inorder(t->right);
	}

	void private_heapify(node* heapNode)
	{
		//cout << "private_heapify\n";
		if (!heapNode) {
			//do nothing
		} else {
			if (!heapNode->isHeap()) {
				cout << "Sifting\n";
				heapNode->sift();
				cout << "Done sifting\n";
			}
			private_heapify(heapNode->left);
			private_heapify(heapNode->right);
		}
	}

	void setHeight_private(node* n, int h)
	{
		n->height = h;
		setHeight_private(n->left, h+1);
		setHeight_private(n->right, h+1);
	}

public:
	BST()
	{
		root = NULL;
	}

	void setHeight()
	{
		setHeight_private(root, 0);
	}

	void remove_heap()
	{
		node* heap_temp, *heap_temp_temp;

		if (root == NULL) {
			cout << "\n\n\nERROR\n\n\n";
		}

		bool isLeft;
		bool isDone = false;
		stack<node*> s;
		node* curr = root;
		int maxHeight = 0;

		while (!isDone) {
			if (curr) {//if it exists
				if (curr->right && curr->right->height > maxHeight) { //if it's the deepest height
					maxHeight = curr->right->height;
					heap_temp = curr;
					heap_temp_temp = curr->right;
					isLeft = false;
				}
				if (curr->left && curr->left->height > maxHeight) {
					maxHeight = curr->left->height;
					heap_temp = curr;
					heap_temp_temp = curr->left;
					isLeft = true;
				}
				s.push(curr);
				curr = curr->left;
			} else if (!s.empty()) {
				node* temp = s.top();
				s.pop();
				curr = temp->right;
			} else if (s.empty()) {
				isDone = true;
			}
		}

		root->data = heap_temp_temp->data;
		cout << "Deleting " << heap_temp_temp->data << " from heap\n";

		delete heap_temp_temp;

		if (isLeft)
			heap_temp->left = NULL;
		else
			heap_temp->right = NULL;
	}

	map<int, int> get_heap()
	{
		map<int, int> retvar;
		get_map_private(root, 0, retvar);

		return retvar;
	}

	void get_map_private(node* item, int index, map<int, int>& m)
	{
		if (!item) {
			//do nothing
		} else {
			//cout << "get_map_private, index = " <<  index << '\n';
			get_map_private(item->left, index*2+1, m);
			m.insert(pair<int, int>(index, item->data));
			get_map_private(item->right, index*2+2, m);
		}
	}

	void heapify()
	{
		while (!isHeap()) {
			private_heapify(root);
		}
	}

	bool isHeap()
	{
		bool isDone = false;
		stack<node*> s;
		node* curr = root;

		while (!isDone) {
			if (curr) {//if it exists
				if (!curr->isHeap()) //if it's not a heap
					return false;
				s.push(curr);
				curr = curr->left;
			} else if (!s.empty()) {
				node* temp = s.top();
				s.pop();
				curr = temp->right;
			} else if (s.empty()) {
				isDone = true;
			}
		}

		return true;
	}

	void insert(int x)
	{
		root = insert(x, root);
	}

	void remove(int x)
	{
		root = remove(x, root);
	}

	void display()
	{
		inorder(root);
		cout << endl;
	}
};

#endif //__BST_H__
