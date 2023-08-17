#pragma once
#ifndef MINHEAP_H
#define MINHEAP_H
#include<iostream>
#include<math.h>
using namespace std;

// A utility function to swap two elements
static void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

class PQMinHeap {
public:
    int* heap; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int size; // Current number of elements in min heap

    PQMinHeap(int cap);
    int parent(int i);
    int left(int i);
    int right(int i);
    int getMin();
    //This method is to add an element to the min heap and then organize it by MinHeapifying it
    void enqueue(int k);
    // Method to remove minimum element (or root) from min heap
    int dequeue();
    // This is a recursive method to MinHeapify a subtree with the root at given index
    void MinHeapify(int i);
    void printArray();
    int count(); // this operation counts the number of times elements are accessed during enqueue and dequeue operations using the counter number.
    int number = 0;
};


#endif