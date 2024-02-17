#include <stdio.h>
#include <stdlib.h>

// Define a Node struct for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node by value
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;

    // If the key is found at the head
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        if (*headRef != NULL)
            (*headRef)->prev = NULL;
        free(temp);
        return;
    }

    // Find the key to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    // Unlink the node from the linked list
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

// Function to display all nodes in the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Forward traversal: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Reverse traversal: ");
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the list
void freeList(struct Node** headRef) {
    struct Node* current = *headRef;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *headRef = NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Initial list:\n");
    displayList(head);

    // Delete node with value 20
    deleteNode(&head, 20);
    printf("List after deleting 20:\n");
    displayList(head);

    // Delete node with value 50 (not present in the list)
    deleteNode(&head, 50);

    // Free memory allocated for the list
    freeList(&head);

    return 0;
}