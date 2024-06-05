/*
Name: Kemari Solomon
Project: Programming Assignment 6
Purpose:To ensure that students can create a basic data structure in preparation for making more complex data structures in COP4530
*/ 
#include "quickQueue.h"
#include <iostream>
#include <string>
using namespace std;

int main()
//set up a Quick Queue
{
    //creation of two different queues of 2 types
    QuickQueue<int> numQueue;
    QuickQueue<string> strQueue;

    numQueue.Enqueue(1);
    numQueue.Enqueue(2);
    numQueue.Enqueue(3);
    numQueue.Enqueue(4);
    numQueue.Enqueue(5);
    numQueue.Enqueue(6);
    numQueue.Enqueue(7);
    numQueue.Enqueue(8);
    numQueue.Enqueue(9);
    numQueue.Enqueue(10);

    cout << "Dequeing Intergers " << endl;
    cout << "------------------"<<endl;
    int *nextInt = numQueue.Dequeue();
    int counter = 0;
    while(counter != 5)
    {
        cout << "The following integer has been Dequed: "<<*nextInt << endl;
        nextInt = numQueue.Dequeue();
        counter++;
    }


    strQueue.Enqueue("one");
    strQueue.Enqueue("two");
    strQueue.Enqueue("three");
    strQueue.Enqueue("four");
    strQueue.Enqueue("five");
    strQueue.Enqueue("six");
    strQueue.Enqueue("seven");
    strQueue.Enqueue("eight");
    strQueue.Enqueue("nine");
    strQueue.Enqueue("ten"); 

    cout << "Dequeing Strings " << endl;
    cout << "----------------"<<endl;
    string *nextStr = strQueue.Dequeue();
    int strCounter = 0;
    while(strCounter != 5)
    {
        cout << "The following string has been Dequed: "<<*nextStr << endl;
     
        nextStr = strQueue.Dequeue();
        strCounter++;
    }
    
    while(nextStr != nullptr)
    {
        nextStr = strQueue.Dequeue();
    }
    while(nextInt != nullptr)
    {
        nextInt = numQueue.Dequeue();
    }
    
    
}
