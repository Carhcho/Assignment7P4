#include "PQMinHeap.h"

PQMinHeap::PQMinHeap(int cap)
{
    size = 0;
    capacity = cap;
    heap = new int[cap];
}

int PQMinHeap::parent(int i)
{
    return (i - 1) / 2;
}

int PQMinHeap::left(int i)
{
    return (2 * i + 1);
}

int PQMinHeap::right(int i)
{
    return (2 * i + 2);
}

int PQMinHeap::getMin()
{
    return heap[0];
}

void PQMinHeap::enqueue(int k)
{
    if (size == capacity) {
        cout << "Min Heap capacity at full, cannot add new elements" << endl;
        return;
    }

    // First insert the new key at the end
    size++;
    int i = size - 1;
    heap[i] = k;
    number++;
    // Fix the min heap property if it is violated
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
        number++;
    }
}


int PQMinHeap::dequeue()
{
    if (size <= 0) {
        cout << "The Min Heap is empty." << endl;
        return INT_MAX;
    }else if (size == 1) {
        size--;
        return heap[0];
        number++;
    }
    else
    {
        // Store the minimum value, and remove it from heap
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        MinHeapify(0);
        return root;
        number++;
    }
}

void PQMinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if ((l < size) && (heap[l] < heap[smallest])) {
        smallest = l;
        number++;
    }
    if ((r < size) && (heap[r] < heap[smallest])) {
        smallest = r;
        number++;
    }
        
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        MinHeapify(smallest);
        number++;
    }
}

void PQMinHeap::printArray()
{
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int PQMinHeap::count()
{
    return number;
}
