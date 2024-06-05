/*
Name: Kemari Solomon
Project: Programming Assignment 6
Purpose:To ensure that students can create a basic data structure in preparation for making more complex data structures in COP4530
*/ 
#include <iostream>

template <class T>
class QuickQueue
 {
    private:
    T** storage; 
    int capacity;
    int size;
    int beginning;
    int end;

     
    public:
        //default constructor
        QuickQueue();
        //Deconstructor
        ~QuickQueue();
        //deep copy assignment operator overload
        QuickQueue<T>& operator=(const QuickQueue<T>& q);
        //ENQUEUE--adds an element to the queue
        void Enqueue(const T& item); 
        //Dequeue-- removes an element from the quee and returns it to the caller
        T* Dequeue();

};


