

#include "LinkedQueueType.h"

#include <iostream>

#include <utility>

using namespace std;

struct NodeType

{

	ItemType info;

	NodeType* next;

};

LinkedQueueType::LinkedQueueType(const LinkedQueueType& qt)

// Copy constructor ---- qt is being copied

{

	//length is 0
	if (qt.length == 0){
		length= 0;
		rear = NULL;
		return;
	}
	//length is 1
	else if (qt.length == 1 ){
		rear = new NodeType;
		rear->info = qt.rear->info;

		rear->next = rear;
		length = 1;

	}
	//length is greater than 1
	else {


		NodeType *temp = qt.rear->next; //leading pointer, starts at first element of qt
		//NodeType *temp2 = NULL; //trailing pointer, builds copy



		length = 0;
		rear = NULL;


		do {

			ItemType copiedItem(temp->info);
			this->Enqueue(copiedItem);
			temp = temp->next;


		} while (length != qt.length);


	}


}

LinkedQueueType::LinkedQueueType() // Default class constructor

{

	length = 0;

	rear = NULL;

}

LinkedQueueType& LinkedQueueType::operator=(const LinkedQueueType& rhs)

{

	length = rhs.length;

	rear = rhs.rear;

	return *this;

}

LinkedQueueType::~LinkedQueueType() // Class destructor

{

	if(IsEmpty()){ // early return. Nothing to do here.
		return;
	}


	NodeType* tempPtr = rear->next;
	rear->next = NULL; // uncirculating the list

	while (tempPtr != NULL) // traversing the list
	{
		rear = tempPtr; // rear is now the node to be deleted
		tempPtr = tempPtr->next; // moving to next node
		delete rear; // deleting the node
	}

}

void LinkedQueueType::MakeEmpty()

// Post: front and rear have been reset to the empty state.

{

	NodeType* tempPtr;

	while (rear != NULL)

	{

		tempPtr = rear;

		rear = rear->next;

		delete tempPtr;

	}

	length = 0;

}

bool LinkedQueueType::IsEmpty() const

// Returns true if the queue is empty; false otherwise.

{

	return (length == 0);

}

bool LinkedQueueType::IsFull() const

// Returns true if the queue is full; false otherwise.

{

	NodeType* location;

try

{

	location = new NodeType;

	delete location;

	return false;

}

	catch (std::bad_alloc&)

	{

		return true;

	}

}

void LinkedQueueType::Enqueue(ItemType newItem)

// Post: If (queue is not full) newItem is at the rear of the queue;

// otherwise a FullQueue exception is thrown.

{

if (IsFull())

	throw FullQueue();

else

{

	NodeType* location; // Declare a pointer to a node

	location = new NodeType; // Get a new node

	location->info = newItem; // Store the item in the node

	if (length == 0)

	{

		rear = location;

		rear->next = rear; //beautiful link, last to first.

	}

	else

	{

		location->next = rear->next;

		rear->next = location;

		rear = location;

// Store address of new node into

// external pointer

}

length++; // Increment length of the list

}

}

void LinkedQueueType::Dequeue(ItemType& item)

// Post: If (queue is not empty) the front of the queue has been

// removed and a copy returned in item;

// othersiwe a EmptyQueue exception has been thrown.

{

if (IsEmpty())

	throw EmptyQueue();

else

{

	item = rear->next->info;

	rear->next = rear->next->next;

	length--;

}

}

void LinkedQueueType::Print()

{

struct NodeType *p;

// If list is empty, return.

if (rear == NULL)
{

	cout << "Circular linked List is empty." << endl;
	return;

}

p = rear -> next; // Point to the first Node in the list.

// Traverse the list starting from first node until first node is visited again

do {

	cout << p->info << " ";

	p = p->next;

} while(p != rear->next);

if(p == rear->next)

	cout<<endl;

}


