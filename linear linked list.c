#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create and insert a node at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a node after a given node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;
    
    // If the node to be deleted is the head
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        printf("Node with data %d not found\n", key);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with a given key
int searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1;  // Key found
        }
        current = current->next;
    }
    return 0;  // Key not found
}

// Function to display the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function demonstrating all operations
int main() {
    struct Node* head = NULL;

    // Inserting elements into the linked list
    insertAtEnd(&head, 1);    // List: 1
    insertAtBeginning(&head, 2);  // List: 2 -> 1
    insertAtBeginning(&head, 3);  // List: 3 -> 2 -> 1
    insertAtEnd(&head, 4);    // List: 3 -> 2 -> 1 -> 4
    insertAfter(head->next, 5);  // List: 3 -> 2 -> 5 -> 1 -> 4

    printf("Linked List: ");
    printList(head);

    // Deleting a node
    deleteNode(&head, 3);  // List after deleting 3: 2 -> 5 -> 1 -> 4
    printf("After Deletion: ");
    printList(head);

    // Searching for an element
    int item_to_find = 3;
    if (searchNode(head, item_to_find)) {
        printf("%d is found in the list.\n", item_to_find);
    } else {
        printf("%d is not found in the list.\n", item_to_find);
    }

    return 0;
}
