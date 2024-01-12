#ifndef STACK_TYPE_H
#define STACK_TYPE_H
#include "ItemType.h"

//   The user of this file must provied a file "ItemType.h" that defines:
//       ItemType : the class definition of the objects on the stack.
//       MAX_ITEMS: the maximum number of items on the stack.

//   Class specification for Stack ADT in file Stack1.h
//Edit: Ivan Temesvari 2/11/2019

class FullStack {};
// Exception class thrown by Push when stack is full.

class EmptyStack {};
// Exception class thrown by Pop and Top when stack is emtpy.

class StackType {
	public:
		ItemType GetValue(int i) const;
		int GetTopIndex();
		void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem);
		//Function: Replaces all occurrences of oldItem with newItem.
		//Precondition: stack has been initialized.
		//Postcondition: Each occurrence of oldItem in stack has been replaced by newItem


		friend bool Identical(const StackType& stack1, const StackType& stack2);

		StackType(int max); // max is stack size

		StackType();  // Default size is 500.
		// Rest of the prototypes go here.
		bool IsFull() const;
		// Function: Determines whether the stack is full.
		// Pre:  Stack has been initialized.
		// Post: Function value = (stack is full)
		bool IsEmpty() const;
		// Function: Determines whether the stack is empty.
		// Pre:  Stack has been initialized.
		// Post: Function value = (stack is empty)
		void Push(ItemType item);
		// Function: Adds newItem to the top of the stack.
		// Pre:  Stack has been initialized.
		// Post: If (stack is full), FullStack exception is thrown;
		//     otherwise, newItem is at the top of the stack.
		void Pop();
		// Function: Removes top item from the stack.
		// Pre:  Stack has been initialized.
		// Post: If (stack is empty), EmptyStack exception is thrown;
		//     otherwise, top element has been removed from stack.
		ItemType Top();
		// Function: Returns a copy of top item on the stack.
		// Pre:  Stack has been initialized.
		// Post: If (stack is empty), EmptyStack exception is thrown;
		//     otherwise, top element has been removed from stack.
		~StackType();
		//Destructor. Reallocate the memory reserved for ItemType* items.
		void Print();
		//Print the stack

	private:
		int top;
		int maxStack; // Maximum number of stack items.
		ItemType* items;  // Pointer to dynamically allocated memory.
};
#endif
