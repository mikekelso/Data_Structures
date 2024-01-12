#include <iostream>
#include <fstream>
#include "ArrayStackType.h"
using namespace std;
//Implement ReplaceItem and Identical here in the driver file.
void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem){
//Function: Replaces all occurrences of oldItem with newItem.
//Precondition: stack has been initialized.
//Postcondition: Each occurrence of oldItem in stack has been replaced by newItem.

StackType stackCopy;

//get top value for stack
int topIndex = stack.GetTopIndex();

//create a copy of stack with desired replacements
for (int i = 0; i<= topIndex; i++){
	if (stack.GetValue(i) == oldItem)
	{
		stackCopy.Push(newItem);

	}
	else{
		stackCopy.Push(stack.GetValue(i));
	}
}

//empty stack
while (!stack.IsEmpty()) {
	stack.Pop();
}

//repopulate stack
for (int i = 0; i<= topIndex; i++){
	stack.Push(stackCopy.GetValue(i));
}


}
bool Identical(const StackType& stack1, const StackType& stack2){
//Function: Determines if two stacks are identical.
//Preconditions: stack1 and stack2 have been initialized.
//Postconditions: stack1 and stack2 are unchanged.
// Function return value = stack1 and stack2 are identical

if (stack1.top != stack2.top){
	return false;
}

for (int i = 0; i <= stack1.top; i++)
{
	if (stack1.items[i] != stack2.items[i]){
		return false;
	}
}
return true; //they are the same
}
int main()
{
try{
	//create Stack
	StackType stack;



	stack.Print();

	//Push 445434 to Stack
	stack.Push(4);
	stack.Push(4);
	stack.Push(5);
	stack.Push(4);
	stack.Push(3);
	stack.Push(4);

	//Print Stack 445434


	stack.Print();

	//replace all 4s with 8s

	ReplaceItem(stack, 4, 8);

	//print replacement stack, should be 885838

	stack.Print();


	//create new Stack
	StackType myStack;

	//print empty new stack
	myStack.Print();

	//push 445434 to myStack

	myStack.Push(4);
	myStack.Push(4);
	myStack.Push(5);
	myStack.Push(4);
	myStack.Push(3);
	myStack.Push(4);

	//print myStack

	myStack.Print();


	if(Identical(stack, myStack)){
		cout << "The stacks are identical." << endl;
	}
	else{
		cout << "The stacks are NOT identical." << endl;
	}

}
catch ( const FullStack& e )
{
	cout << "Stack is full!" << endl;
}
catch(const EmptyStack& e){
	cout << "Stack is empty!" << endl;
}
return 0;
}
