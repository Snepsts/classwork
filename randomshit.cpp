void stack::Display(ostream& out)
{
	for (int i = myTop; i >= 0; i--)
	{
		out << myArray[i] << " @ " << i + 1 << endl;
	}
}

void stack::Remove(int n)
{
	if (n > myTop)
		n == myTop; //If n is greater than the stack's amount then reduce it to the stack's amount so it doesn't pop more than possible
	for(int i = n; i > 0; i--)
		pop();
}

void ReverseStack(ostream& out, stack aStack)
{
	vector v;
	while (!aStack.empty())
	{
		v.push_back(aStack.top());
		aStack.pop();
	}

	while (!v.empty())
	{
		out << v.back() << endl;
		v.pop_back();
	}
}

void CountStack(stack aStack)
{
	int i;
	i = 0;
	while(!aStack.empty())
	{
		aStack.pop();
		i++;
	}

	cout << "The amount of items in the stack is " << i << " items." << endl;
}

void RemoveItem(stack<T>& aStack, T item)
{
	vector<T> v;

	while(!aStack.empty())
	{
		v.push_back(aStack.Top());
		aStack.pop();
	}

	if (v.back() == item)
	{
		v.pop_back();
	}

	else
	{
		aStack.push(v.back());
		v.pop_back();
	}
}

6. a. abfh

b. void stack::displayforward(ostream& out)
{
	n = myTop;

	for (int i = 0; i < myTop; i++)
		out << myArray[i];
}

c. string correctorder(string s1)
{
	string s;
	stack aStack, bStack;
	unsigned n, a;
	n = s1.length();

	for (unsigned i = 0; i < n; i++)
	{
		if (s1[i] == backspace character)
			aStack.pop();
		else
			aStack.push(s1[i];
	}

	while (!aStack.empty())
	{
		bStack.push(aStack.top());
		aStack.pop();
		a++;
	}

	s.resize(a);
	n = s.length();

	for (unsigned i = 0; i < n; i++)
	{
		s[i] = bStack.top();
		bStack.pop();
	}
}

7. for (each character in the string)
{
	if (the character is '{')
		stack.push({);
	if (the character is '}')
		if (stack.top() == '{')
			stack.pop();
		else
			return false;

	if (the character is '(')
		stack.push({);
	if (the character is ')')
		if (stack.top() == '(')
			stack.pop();
		else
			return false;

		if (the character is '{')
			stack.push({);
		if (the character is '}')
			if (stack.top() == '{')
				stack.pop();
			else
				return false;
}

if (stack is empty)
	return true;

11. a. 7 - 3 + 12 = 16
	b. 7 + (-5 * (3 - 12)) = 42
	c. ((7 + 3) - 12) + (-5 * 1) = -7

12. b. a b c d * / -
	d. a b c d e + f * - / /
	f. a b c d / / e + -
	h. a b c d * + e / -

3. 4 4 4

4. Q.enqueue(operator/paraenthesis)
	if (Q.back() == ")")
		Q.dequeue();
	while (Q.Front() != ")")
		add to the post fix group Q.front();
		Q.dequeue();
	Q.dequeue();

5. ItemType retBack(Queue object)
{
	Queue Temp;
	ItemType item;

	while (!object.empty())
		Temp.enqueue(object.front());
		item = object.front();
		object.dequeue();
	while (!Temp.empty())
		object.enqueue(Temp.front());
		Temp.dequeue();

	return item;
}

7. void display(Queue object)
{
	Queue Temp;
	while (!object.empty())
	{
		cout << object.front() << endl;
		Temp.enqueue(object.front());
		object.dequeue();
	}
	while (!Temp.empty())
	{
		object.enqueue(Temp.front());
		Temp.dequeue();
	}
}

9.
Purpose: To remove an item from the back.
Receives: N/A
Preconditions: Cannot be empty
Postconditions: Removes element from the back of Queue
void Queue::removefromback()
{
	(makesureisntempty)

	m_back = (m_back - 1) % CAPACITY;
}

Purpose: To add an item to the front.
Receives: N/A
Preconditions: Cannot be full
Postconditions: Adds element to the front of Queue
void Queue::addtofront(QueueType element)
{
	(makesureisntfull)

	m_front = (m_front - 1) % CAPACITY;
	m_array[m_front] = element;
}

10. string correctorder(string s1)
{
	string s;
	Queue Q;
	unsigned n, a;
	n = s1.length();

	for (unsigned i = 0; i < n; i++)
	{
		if (s1[i] == backspace character)
			Q.removefromback();
		else
			Q.enqueue(s1[i]);
	}

	while (!Q.empty())
	{
		s = s + Q.front();
		Q.dequeue();
	}

	return s;
}
