#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head;

void addNode(int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if(head == NULL) {
    head = newNode;
    return; 
  }

  struct Node* current = head;
  while(current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

void printList() {
  struct Node* current = head;
  while(current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}

int main() {

  head = NULL;

  addNode(10);
  addNode(20);
  addNode(30);

  printList();

  return 0;
}
