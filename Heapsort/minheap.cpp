#include "minheap.hpp"
#include <stdio.h>
#include <iostream>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

MinHeap::MinHeap(int size)
{
  heap_size = 0;
  capacity = size;
  harr = new int[size];
}
MinHeap::~MinHeap() {}

int MinHeap::left(int parent)
{
  int i = parent * 2 + 1;
  return (i < heap_size) ? i : -1;
}

int MinHeap::right(int parent)
{
  int i = parent * 2 + 2;
  return (i < heap_size) ? i : -1;
}

int MinHeap::parent(int child)
{
  if (child != 0)
  {
    int i = (child - 1) >> 1;
    return i;
  }
  return -1;
}

int MinHeap::size() { return heap_size; }

void MinHeap::insert(int element)
{

  if (heap_size == capacity)
  {
    cout << "Heap overflow: Cannot insert more elements" << endl;
    return;
  }

  heap_size++;
  int i = heap_size - 1;
  harr[i] = element;

  while (i != 0 && harr[parent(i)] > harr[i])
  {
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}

int MinHeap::extractMin()
{
  if (heap_size <= 0)
  {
    cout << "Heap underflow: No elements to extract" << endl;
    return 1;
  }
  if (heap_size == 1)
  {
    heap_size--;
    return harr[0];
  }

  // Store the minimum value and remove it
  int root = harr[0];
  harr[0] = harr[heap_size - 1];
  heap_size--;

  // Restore heap property
  MinHeapify(0);

  return root;
}

void MinHeap::MinHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smallest = i;

  if (l != -1 && l < heap_size && harr[l] < harr[i])
    smallest = l;
  if (r != -1 && r < heap_size && harr[r] < harr[smallest])
    smallest = r;

  if (smallest != i)
  {
    swap(&harr[i], &harr[smallest]);
    MinHeapify(smallest);
  }
}

void MinHeap::display()
{
  cout << "MinHeap:- ";
  cout << heap_size << endl;
  for (int i = 0; i < heap_size; i++)
  {
    cout << harr[i] << " ";
  }
  cout << endl;
}

void MinHeap::heapsort(vector<int> &A, int n)
{
  MinHeap heap(n);

  for (int i = 0; i < n; i++)
  {
    heap.insert(A[i]);
  }

  for (int i = 0; i < n; i++)
  {
    A[i] = heap.extractMin();
  }
}
