// Implementation file for linked StackType
#include "LinkedStackType.h"
#include <iostream>
using namespace std;



NodeType* StackType::GetTop() const {
	return topPtr;
}
void StackType::MoveNext() {
	if(topPtr->next != nullptr)
		topPtr = topPtr->next;

}


/*
StackType StackType::stackCopier(StackType& stackToCopy)
{
	StackType stackCopy;

	int i = 0;

	//copy stack to stackcopy, pop all elements of stack, i is element count
	do {
		stackCopy.Push(stackToCopy.Top());
		stackToCopy.Pop();
		i++;
		} while (!(stackToCopy.IsEmpty()));

	return stackCopy;
}


*/
void StackType::PrintRec(NodeType* top){
    //Base Case
    if(top == nullptr)
    {

    	return;
    }
    //Recursive Case
    else{
        cout << top->info;;
        PrintRec(top->next);
    }
}

void StackType::Print(){

	PrintRec(topPtr);
}


void StackType::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Stack is bounded by size of memory.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.

{
  if (IsFull())
    throw FullStack();
  else
  {
    NodeType* location;
    location = new NodeType;
    location->info = newItem;
    //cout << "location info" <<  endl << location->info <<endl;
    location->next = topPtr;
    topPtr = location;
  }
}
void StackType::Pop()
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
  if (IsEmpty())
    throw EmptyStack();
  else
  {  
    NodeType* tempPtr;
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
}

ItemType StackType::Top() const
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
  if (IsEmpty())
    throw EmptyStack();
  else
    return topPtr->info;  
}

StackType::StackType()	// Class constructor.
{
  topPtr = nullptr;
}
bool StackType::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
    NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

StackType::~StackType()
// Post: stack is empty; all items have been deallocated.
{
  NodeType* tempPtr;

  while (topPtr != nullptr)
  {
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
}

bool StackType::IsEmpty() const
{
  return (topPtr == nullptr);
}  



