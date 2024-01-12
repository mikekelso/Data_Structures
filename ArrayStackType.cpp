// The function definitions for class StackType.
#include "ArrayStackType.h"
#include <iostream>
using namespace std;

StackType::StackType(int max)
{
  maxStack = max;
  top = -1;
  items = new ItemType[maxStack];
}


StackType::StackType()
{
  maxStack = 500;
  top = -1;
  items = new ItemType[maxStack];
}


ItemType StackType::GetValue(int i) const {
      return items[i] ;
}

int StackType::GetTopIndex(){
	return top;
}
bool StackType::IsEmpty() const
{
  return (top == -1);
}


bool StackType::IsFull() const
{
  return (top == maxStack-1);
}


void StackType::Push(ItemType newItem) 
{
  if (IsFull())
    throw FullStack();
  top++;
  items[top] = newItem;
}


void StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}


ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    


StackType::~StackType()
{
  delete [] items;
}

void StackType::Print(){
	if (IsEmpty())
		cout << "The stack is empty" << endl;
	for ( int i = top; i >= 0 ; i--) {
		cout << items[i];
	}
	cout <<endl;
}

