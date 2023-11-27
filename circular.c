#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
}

void reverse(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    *head = prev;
}

void display(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original circular linked list: ");
    display(head);

    reverse(&head);

    printf("Reversed circular linked list: ");
    display(head);

    return 0;
}
