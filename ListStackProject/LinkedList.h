#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "List.h"
using namespace std;

// ---------------- Node class ------------------------//
class Node
{
public:
	Node(int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}

	int getData() const
	{
		return data;
	}

	void setData(int data)
	{
		this->data = data;
	}

	Node* getNext() const
	{
		return next;
	}

	void setNext(Node* next)
	{
		this->next = next;
	}

private:
	int data;
	Node* next;
};

//----------------- Linked List class ------------------//

class LinkedList : public List
{
public:
	LinkedList()
	{
		mNumElements = 0;
		mHead = nullptr;
	}

	virtual ~LinkedList()
	{
		makeEmpty();
	}

	void add(int newEntry)
	{
		Node* newNode = new Node(newEntry, mHead); // next = mHead
		mHead = newNode;

		mNumElements++;
	}

	void add(int newEntry, int position)
	{
		Node* newNode = new Node(newEntry, mHead);

		if (position >= mNumElements + 1 || position < 0)
		{
			cout << "Error: Cannot add at specified position" << endl;
			return;
		}

		if (position == 0)
		{
			newNode->setNext(mHead);
			mHead = newNode;
		}
		else
		{
			//not beginning
			Node* nodeBefore = mHead;
			Node* nodeAfter;

			for (int i = 0; i < position - 1; i++)
			{
				nodeBefore = nodeBefore->getNext();
			}

			nodeAfter = nodeBefore->getNext();
			newNode->setNext(nodeAfter);
			nodeBefore->setNext(newNode);
		}
		mNumElements++;
	}

	void set(int newEntry, int position)
	{
		Node* walker = mHead;
		int index = 0;

		if (position >= mNumElements || position < 0)
		{
			cout << "Error: Cannot set at specified position" << endl;
			return;
		}

		for (int i = 0; i < position; i++)
		{
			walker = walker->getNext();
		}

		walker->setData(newEntry);
	}

	bool contains(int entry) const
	{
		bool result = false;

		result = find(entry) != -1;
		return result;
	}

	int find(int entry) const
	{
		int foundIndex = -1;

		int indexCounter = 0;
		Node* walker = mHead;

		while (walker != nullptr)
		{
			if (walker->getData() == entry)
			{
				foundIndex = indexCounter;
				break;
			}
			walker = walker->getNext();
			indexCounter++;
		}
		return foundIndex;

		return foundIndex;
	}

	int remove(int position)
	{
		if (position >= mNumElements || position < 0)
		{
			cout << "Error: Cannot remove at specified posiiotn" << endl;
			return 0;
		}

		int dataToReturn = 0;

		if (position == 0)
		{
			Node* temp = mHead;
			dataToReturn = temp->getData();
			mHead = mHead->getNext();
			delete temp;
		}
		else
		{
			Node* nodeBefore = mHead;
			Node* nodeToRemove;
			Node* nodeAfter;

			for (int i = 0; i < position - 1; i++)
			{
				nodeBefore = nodeBefore->getNext();
			}

			nodeToRemove = nodeBefore->getNext();
			dataToReturn = nodeToRemove->getData();

			nodeAfter = nodeToRemove->getNext();

			nodeBefore->setNext(nodeAfter);

			delete nodeToRemove;
		}

		mNumElements--;

		return dataToReturn;
	}

	void makeEmpty()
	{
		Node* temp;
		while (mHead != nullptr)
		{
			temp = mHead;
			mHead = mHead->getNext();
			delete temp;
		}

		mNumElements = 0;
	}

	int size() const
	{
		return mNumElements;
	}

	bool isEmpty() const
	{
		return mNumElements == 0;
	}

	void printList() const
	{
		Node* walker = mHead;

		while (walker != nullptr)
		{
			cout << walker->getData() << endl;
			walker = walker->getNext();
		}
	}

private:
	Node* mHead;
	int mNumElements;
};

#endif
