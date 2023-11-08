#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the circular linked list
void insert(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty, make the new node the head and point its next to itself
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        // Find the last node in the list
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        // Insert the new node at the beginning and update the next pointers
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
}

// Function to reverse the nodes in the circular linked list
void reverse(struct Node** head) {
    if (*head == NULL)
        return;

    // Initialize three pointers to keep track of the current, previous, and next nodes
    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    // Traverse the list and reverse the next pointers of each node
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    // Update the head pointer to point to the last node
    *head = prev;
}

// Function to print the circular linked list
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

    // Insert nodes into the circular linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original circular linked list: ");
    display(head);

    // Reverse the nodes in the circular linked list
    reverse(&head);

    printf("Reversed circular linked list: ");
    display(head);

    return 0;
}
