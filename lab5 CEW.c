#include <stdio.h>
#include <stdlib.h>

// Node definition for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two sorted linked lists into one
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            insertAtEnd(&mergedList, list1->data);
            list1 = list1->next;
        } else {
            insertAtEnd(&mergedList, list2->data);
            list2 = list2->next;
        }
    }

    // Add remaining elements from list1, if any
    while (list1 != NULL) {
        insertAtEnd(&mergedList, list1->data);
        list1 = list1->next;
    }

    // Add remaining elements from list2, if any
    while (list2 != NULL) {
        insertAtEnd(&mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Free memory allocated for a linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Example lists
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    // Free memory
    freeList(list1);
    freeList(list2);
    freeList(mergedList);

    return 0;
}
