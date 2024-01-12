//============================================================================
// Name        : linkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <iostream>
using namespace std;


struct Node {
    Node * next;
    int info;
};

class LinkedList {

private:
Node* head;
int length;


public:
    LinkedList() {
        head = new Node;
        length = 1;

    }

//    int get(int index) {
//
//    }
    Node* getHead() {
    	return head;
    }
    void insertHead(int val) {
        Node* tempNode;
        tempNode = new Node;
        tempNode->info = val;
        tempNode->next = head;
        head = tempNode;

    }

    void insertTail(int val) {
        Node* tempNode = head;
        while (tempNode!=nullptr){
            tempNode = tempNode->next;
        }
        tempNode->next = nullptr;
        tempNode->info = val;
    }

    bool remove(int index) {
        Node * tempNode1 = head;
        Node * tempNode2 = head;
        int count = 0;
        while (count!=index){
            if (tempNode1->next == nullptr){
                return false;
            }
            tempNode2 = tempNode1;
            tempNode1 = tempNode1->next;
            count++;
        }
        if (tempNode1->next != nullptr){
            tempNode2 = tempNode1->next;
        }

        return true;


    }

    vector<int> getValues() {
        vector<int> vect;
        Node * tempNode = head;
        while (tempNode != nullptr){
            vect.push_back(tempNode->info);
            tempNode = tempNode->next;
        }
        return vect;
    }
};
int main() {
	LinkedList link1;
	link1.insertHead(3);
	link1.insertHead(5);
	Node *tempNode = link1.getHead();
	while (tempNode!= nullptr){
		cout << tempNode ->info << endl;
		tempNode = tempNode->next;

	}
	return 0;
}
