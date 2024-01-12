//============================================================================
// Name        : DynamicArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class DynamicArray {
public:

    DynamicArray(int capacity) {
        array = new int[capacity];
        arrayCapacity = capacity;
        size = 0;
    }

    int get(int i) {
        int counter = 0;

    	return array[i];
    }

    void set(int i, int n) {
        if ( array[i] == 0){
            size++;
        }
        array[i] = n;
    }

    void pushback(int n) {
        if ( size == arrayCapacity){
            resize();
        }

        while (array[arrayCapacity - 1] != 0){


            int j = arrayCapacity - 1;


            while (array[j]!= 0){
                j--;
            }
            array[j] = array[j+1];
            array[j+1] = 0;
        }

        array[arrayCapacity - 1] = n;
        size++;



    }

    int popback() {
    	int lastElement = array[arrayCapacity - 1];
        arrayCapacity--;
    	size--;
    	reHell yeah!
    void resize() {
    	int newCapacity = arrayCapacity * 2;
    	int *new_arr = new int[newCapacity];
    	for(int i = 0; i <arrayCapacity; i++){
    		new_arr[i] = array[i];
    	}
    	delete[] array;
    	array = new_arr;
    	arrayCapacity = newCapacity;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return arrayCapacity;
    }
private:
    int arrayCapacity;
    int size;
    int *array;
};

int main() {
	DynamicArray DynArray(3);
	DynArray.pushback(1);
	DynArray.pushback(2);
	DynArray.pushback(3);
	DynArray.get(0);
	DynArray.get(1);
	DynArray.get(2);

	for (int i = 0; i < DynArray.getCapacity(); i++){

		cout << DynArray.get(i) << endl;
	}
	return 0;
}

