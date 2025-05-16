#include "heap.h"
#include <climits>

MinHeap::MinHeap(int cap) : capacity(cap), size(0) {

    heapArray = new int[cap];
    keyArray = new int[cap];
    position = new int[cap];
    for (int i = 0; i < cap; i++) {
        heapArray[i] = -1;     // not used yet
        keyArray[i] = INT_MAX;
        position[i] = -1;      // not in heap yet
    }

}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

bool MinHeap::isInMinHeap(int v) {
    return position[v] < size;
}

void MinHeap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void MinHeap::minHeapify(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
        smallest = left;
    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
        smallest = right;
    if (smallest != index) {
        int smallestVertex = heapArray[smallest];
        int idxVertex = heapArray[index];

        position[smallestVertex] = index;
        position[idxVertex] = smallest;

        swap(heapArray[smallest], heapArray[index]);
        minHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if (isEmpty()) return -1;

    int root = heapArray[0];
    int lastNode = heapArray[size - 1];

    heapArray[0] = lastNode;
    position[lastNode] = 0;

    size--;
    minHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int v, int newKey) {
    int i = position[v];
    keyArray[v] = newKey;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        position[heapArray[i]] = (i - 1) / 2;
        position[heapArray[(i - 1) / 2]] = i;
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::insert(int vertex, int key) {
    if (size == capacity) return;

    keyArray[vertex] = key;
    heapArray[size] = vertex;
    position[vertex] = size;
    int i = size;
    size++;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        position[heapArray[i]] = (i - 1) / 2;
        position[heapArray[(i - 1) / 2]] = i;
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
