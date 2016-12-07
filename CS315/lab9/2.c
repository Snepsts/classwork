#include <stdio.h> //printf, scanf, etc
#include <stdlib.h> //malloc
#include <string.h> //strtok

/* (Binary Search Tree of Strings) Write a program based on the program of
Fig. 12.19 that inputs a line of text, tokenizes the sentence into separate
words, inserts the words in a binary search tree, and prints the inorder,
preorder, and postorder traversals of the tree.
[Hint: Read the line of text into an array. Use strtok to tokenize the text.
When a token is found, create a new node for the tree, assign the pointer
returned by strtok to member string of the new node, and insert the node in the
tree.] */

//binary tree node struct
struct treeNode{
	struct treeNode *leftPtr; //pointer to left subtree
	char *data; //node value
	struct treeNode *rightPtr; //pointer to right subtree
};

typedef struct treeNode TreeNode; //synonym for struct treeNode
typedef TreeNode *TreeNodePtr; //synonym for TreeNode*

//prototypes
void insertNode(TreeNodePtr *treePtr, char *value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(){
	char str[1000];
	const char delim[3] = " \n";
	char *token;
	TreeNodePtr rootPtr = NULL; //tree initially empty

	printf("Please enter a string with 999 characters or less\n");
	fgets(str, 1000, stdin);

	//first token in the str
	token = strtok(str, delim);

	while(token != NULL){
		insertNode(&rootPtr, token);

		token = strtok(NULL, delim);
	}

	//traverse the tree preOrder
	puts("\n\nThe preOrder traversal is:");
	preOrder(rootPtr);

	//traverse the tree inOrder
	puts("\n\nThe inOrder traversal is:");
	inOrder(rootPtr);

	//traverse the tree postOrder
	puts("\n\nThe postOrder traversal is:");
	postOrder(rootPtr);

	//final newline bc otherwise the terminal looks weird after execution
	printf("\n");

	return 0;
}

//insert node into tree
void insertNode(TreeNodePtr *treePtr, char *value){
	//if tree is empty
	if(*treePtr == NULL){
		*treePtr = malloc(sizeof(TreeNode));

		//if memory was allocated, then assign data
		if(*treePtr != NULL){
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		} //end if
		else{
			printf("%s not inserted. No memory available.\n", value);
		} //end else
	} //end if
	else{ //tree is not empty
		//data to insert is less than data in current node
		if(*value < *((*treePtr)->data)){
			insertNode( &((*treePtr)->leftPtr), value);
		} //end if

		//data to insert is either greater than or the same as data in current node
		else{ //in a conflict we will add it to the right anyway
			insertNode( &((*treePtr)->rightPtr), value);
		} //end else
	} //end else
} //end function insertNode

//begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr)
{
	//if tree is not empty, then traverse
	if(treePtr != NULL){
		inOrder(treePtr->leftPtr);
		printf("%s ", treePtr->data);
		inOrder(treePtr->rightPtr);
	} //end if
} //end function inOrder

//begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{
	//if tree is not empty, then traverse
	if(treePtr != NULL){
		printf("%s ", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	} //end if
} //end function preOrder

//begin postorder traversal of tree
void postOrder(TreeNodePtr treePtr)
{
	//if tree is not empty, then traverse
	if(treePtr != NULL){
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%s ", treePtr->data);
	} //end if
} //end function postOrde

/* Output:
Please enter a string with 999 characters or less
I do rather enjoy a good dolphin


The preOrder traversal is:
I do a rather enjoy dolphin good

The inOrder traversal is:
I a do dolphin enjoy good rather

The postOrder traversal is:
a dolphin good enjoy rather do I */
