// Assignment7.cpp : Cesar Roncancio
//
#include "PQMinHeap.h"
#include "PQLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    //created randArray to be the random 50 elements that are going to be included in the priority lists
    int randArray[50];
    for (int i = 0; i < 50; i++)
        randArray[i] = rand()% 100;  //Generate number between 0 to 99
    cout << "\nElements of the array:" << endl;
    for (int i = 0; i < 50; i++)
        cout << randArray[i] << ", ";
    cout << endl;

    //This is the PQ Mean Heap object
    PQMinHeap PriorityQueue1(50);
    cout << "Enqueueing elements in Priority Queue Min Heap..." << endl;
    for (int i = 0; i < 50; i++) {
        PriorityQueue1.enqueue(randArray[i]);
    }
    cout << "Displaying elements by priority(smallest to largest)" << endl;
    PriorityQueue1.printArray();
    cout << "Displaying number of elements accessed by all operations done so far: " << PriorityQueue1.count() << endl;
    cout << "Dequeuing the highest priority element..." << endl;
    PriorityQueue1.dequeue();
    cout << "Displaying elements by priority(smallest to largest)" << endl;
    PriorityQueue1.printArray();
    cout << "Displaying number of elements accessed by all operations done so far: " << PriorityQueue1.count() << endl;

    //This is the PQ Linked List object
    PQLinkedList PriorityQueue2;
    cout << "Enqueueing elements in Priority Queue Linked List..." << endl;
    for (int i = 0; i < 50; i++) {
        PriorityQueue2.enqueue(randArray[i]);
    }
    cout << "Displaying elements by priority(smallest to largest)" << endl;
    PriorityQueue2.displayList(); cout << endl;
    cout << "Displaying number of elements accessed by all operations done so far: " << PriorityQueue2.count() << endl;
    cout << "Dequeuing the highest priority element..." << endl;
    PriorityQueue2.dequeue();
    cout << "Displaying elements by priority(smallest to largest)" << endl;
    PriorityQueue2.displayList(); cout << endl;
    cout << "Displaying number of elements accessed by all operations done so far: " << PriorityQueue2.count() << endl;
    
}


