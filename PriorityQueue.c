#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int heap[MAX_SIZE];
    int size;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct PriorityQueue *pq, int index) {
    if (index == 0) {
        return;
    }
    int parent = (index - 1) / 2;
    if (pq->heap[parent] > pq->heap[index]) {
        swap(&pq->heap[parent], &pq->heap[index]);
        heapifyUp(pq, parent);
    }
}

void insert(struct PriorityQueue *pq, int value) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority queue is full. Cannot insert %d\n", value);
        return;
    }
    pq->heap[pq->size] = value;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

void heapifyDown(struct PriorityQueue *pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < pq->size && pq->heap[left] < pq->heap[smallest]) {
        smallest = left;
    }
    if (right < pq->size && pq->heap[right] < pq->heap[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}

int deleteMin(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty. Cannot delete minimum element.\n");
        return -1;
    }
    int minValue = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return minValue;
}

int main() {
    struct PriorityQueue pq;
    pq.size = 0;

    insert(&pq, 10);
    insert(&pq, 20);
    insert(&pq, 15);
    insert(&pq, 40);
    insert(&pq, 50);

    printf("Minimum element in the priority queue: %d\n", deleteMin(&pq));
    printf("Minimum element in the priority queue: %d\n", deleteMin(&pq));

    return 0;
}
