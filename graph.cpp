#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>
using namespace std;

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j)
            if (i == j)
                adjMatrix[i][j] = 0;
            else
                adjMatrix[i][j] = INT_MAX;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    int* parent = new int[numVertices];
    int* key = new int[numVertices];
    MinHeap heap(numVertices);

    for (int v = 0; v < numVertices; ++v) {
        key[v] = INT_MAX;
        parent[v] = -1;
    }

    key[0] = 0;

    for (int i = 0; i < numVertices; ++i)
        heap.insert(i, key[i]);


    while (!heap.isEmpty()) {
        int u = heap.extractMin();

        for (int v = 0; v < numVertices; ++v) {
            int weight = adjMatrix[u][v];
            if (weight != INT_MAX && heap.isInMinHeap(v) && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                heap.decreaseKey(v, weight);
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << "-> " << i << " (" << adjMatrix[i][parent[i]] << ")\n";
        totalWeight += adjMatrix[i][parent[i]];
    }

    cout << "Total Cost: " << totalWeight;


}
