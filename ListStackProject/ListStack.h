#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <iostream>
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

class ListStack : public Stack
{
public:
	ListStack()
	{
		top = -1;
	}

	virtual ~ListStack()
	{
		makeEmpty();
		top = -1;
	}

	void push(int newEntry)
	{
		top++;

		linkedListStack.add(newEntry);
	}

	int pop()
	{
		int data = 0;

		if (!isEmpty())
		{
			data = linkedListStack.remove(top);
			top--;
		}
		else
		{
			cout << "Error: You cannot pop on an empty stack!" << endl;
		}
		return data;
	}

	int peek()
	{
		int data = 0;

		if (!isEmpty())
		{
			data = linkedListStack.remove(top);

			linkedListStack.add(data);
		}
		else
		{
			cout << "Error: You cannot peek on an empty stack!" << endl;
		}

		return data;
	}

	bool isEmpty() const
	{
		return linkedListStack.isEmpty();
	}

	void makeEmpty()
	{
		linkedListStack.makeEmpty();
	}

private:
	LinkedList linkedListStack;
	int top;
};

#endif