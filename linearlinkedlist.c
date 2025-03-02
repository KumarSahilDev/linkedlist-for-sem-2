#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Position should be >= 1.\n");
        return;
    }
    struct Node *newNode = createNode(data);
    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position is greater than the number of nodes.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the beginning
void deleteAtBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node **head, int position)
{
    if (position < 1 || *head == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1)
    {
        deleteAtBeginning(head);
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position is greater than the number of nodes.\n");
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Function to search for a value in the linked list
void search(struct Node *head, int data)
{
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Element %d found at position %d.\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", data);
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    do
    {
        printf("\nLinked List Operations:\n");
        printf("1. Create node\n");
        printf("2. Display list\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert at position\n");
        printf("6. Delete from beginning\n");
        printf("7. Delete from end\n");
        printf("8. Delete at position\n");
        printf("9. Search element\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 4:
            printf("Enter value to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 5:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
        case 6:
            deleteAtBeginning(&head);
            break;
        case 7:
            deleteAtEnd(&head);
            break;
        case 8:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 9:
            printf("Enter value to search: ");
            scanf("%d", &data);
            search(head, data);
            break;
        }
    } while (choice <= 9);

    return 0;
}
