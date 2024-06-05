/*
Name: Kemari Solomon
Project: Programming Assignment 6
Purpose:To ensure that students can create a basic data structure in preparation for making more complex data structures in COP4530
*/ 
#include "quickQueue.h"
#include "iostream"
using namespace std;
template <class T>

//default constructor definition
QuickQueue<T>::QuickQueue()
{
    size = 0;
    capacity = 12; //
    storage = new T*[capacity];
    beginning = 0;
    end = -1;
};

//Deep copy assignment 
template <class T>
QuickQueue<T>& QuickQueue<T>::operator=(const QuickQueue<T>& q) {
	// Check for self-assignment
	if(this != &q) {
		// Copy the size, capacity, beginning, and end from the source queue
		size = q.size;
		capacity = q.capacity;
        beginning = q.beginning;
        end = q.end;
		
		// Delete the existing storage to avoid memory leaks
		delete [] storage;
		// Allocate new storage with the same capacity as the source queue
		storage = new T*[capacity];
		// Copy elements from the source queue to the new storage
		for(int i = 0; i < size; i++) {
			storage[i] = q.storage[i];
		}
	}
	
	// Return a reference to the current object
	return *this;
}
//deconstructor definition
template <class T>
QuickQueue<T>::~QuickQueue() 
{
	for(int i = 0; i < size; i++) 
    {
		delete storage[i];
	}
	
	delete [] storage;
}
//enque definition
template <class T>
void QuickQueue<T>::Enqueue(const T& item)
{
    if(size == capacity){
        capacity += 5;
        T** temp = new T*[capacity];

        // Copy elements from the current storage to the new storage
        for(int i = 0; i < size; i++)
        {
            temp[i] = storage[(beginning + i) % capacity];
        }
        //memory deallocation
        delete [] storage;
        storage = temp;

        // Reset beginning index
        beginning = 0;
        end = size - 1;
    }

    end = (end + 1) % capacity;
    storage[end] = new T(item);
    size++;
}


template <class T>
T* QuickQueue<T>::Dequeue()
{
    // Check if the queue is empty
    if (size == 0)
    {
        // If the queue is empty, print a message and return nullptr
        cout << "Queue is empty" << endl;
        return nullptr;
    }
    
    // Retrieve the item at the beginning of the queue
    T* beginningItem = storage[beginning];
    // Set the slot at the beginning to nullptr to release the memory
    storage[beginning] = nullptr;
    // Update the beginning index to the next slot
    beginning = (beginning + 1) % capacity;
    // Decrease the size of the queue since an item is removed
    size--;
    // Return the item that was dequeued
    return beginningItem;
}

template class QuickQueue<int>;
template class QuickQueue<string>;