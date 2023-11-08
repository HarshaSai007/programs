#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayPolynomial(struct Node* poly) {
    struct Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* current1 = poly1;
    struct Node* current2 = poly2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            insertTerm(&result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            insertTerm(&result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            int sum = current1->coefficient + current2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, current1->exponent);
            }
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertTerm(&result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertTerm(&result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Insert terms into polynomial 1
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    // Insert terms into polynomial 2
    insertTerm(&poly2, 2, 3);
    insertTerm(&poly2, -1, 2);
    insertTerm(&poly2, 5, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Result: ");
    displayPolynomial(result);

    return 0;
}
