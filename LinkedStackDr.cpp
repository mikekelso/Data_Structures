
#include <fstream>
#include "LinkedStackType.h"

#include <iostream>
using namespace std;
//Implement ReplaceItem and Identical here in the driver file.
void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem){
//Function: Replaces all occurrences of oldItem with newItem.
//Precondition: stack has been initialized.
//Postcondition: Each occurrence of oldItem in stack has been replaced by newItem.



	StackType stackCopy;



	int i = 0;



	//copy stack to stackcopy, pop all elements of stack, i is element count
	do {

		stackCopy.Push(stack.Top());
		stack.Pop();
		i++;
	} while (!(stack.IsEmpty()));






	//repopulate stack but make substitutions

	for (int j = 0; j < i; j++){

		if (stackCopy.Top() == oldItem)
		{
			stack.Push(newItem);
		}
		else {
			stack.Push(stackCopy.Top());
		}
		stackCopy.MoveNext();
	}

}

bool Identical(const StackType& stack1, const StackType& stack2){
//Function: Determines if two stacks are identical.
//Preconditions: stack1 and stack2 have been initialized.
//Postconditions: stack1 and stack2 are unchanged.
// Function return value = stack1 and stack2 are identical


NodeType* top1 = stack1.GetTop();
NodeType* top2 = stack2.GetTop();

while ( top1 != nullptr && top2 != nullptr){
	if ( top1->info != top2->info){
		return false;
	}

	top1= top1->next;
	top2= top2->next;

}
//different lengths not identical
if ((top1 && !top2) || (!top1 && top2)){
	return false;
}

return true;
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
