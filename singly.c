#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head = NULL;

void addNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void printList() {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}

int main() {
  addNode(10);
  addNode(20);
  addNode(30);

  printList();

  return 0;
}
