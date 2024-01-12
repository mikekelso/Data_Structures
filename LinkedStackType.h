#ifndef STACK_H
#define STACK_H
class FullStack{};
class EmptyStack{};


typedef int ItemType;

struct NodeType
{
  ItemType info;
  NodeType* next;
};




class StackType{
	public:
		StackType();
		~StackType();
		//StackType stackCopier(StackType& stackToCopy);
		NodeType* GetTop() const ;
		void MoveNext() ;
		void PrintRec(NodeType* top);
		void Print();

		void Push(ItemType);
		void Pop();
		ItemType Top() const;
		bool IsEmpty() const;
		bool IsFull() const;
	private:
		NodeType* topPtr;
};
#endif
