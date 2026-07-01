//adding row at first and last position in linked list.
//searching maximum and minimum element in linked list.
// deleting from first and last position in linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertFirst(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertLast(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}

// Delete from beginning
void deleteFirst()
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted.\n");
}

// Delete from end
void deleteLast()
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Last node deleted.\n");
}

// Find maximum
void findMaximum()
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    int max = head->data;
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;

        temp = temp->next;
    }

    printf("Maximum element = %d\n", max);
}

// Find minimum
void findMinimum()
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    int min = head->data;
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data < min)
            min = temp->data;

        temp = temp->next;
    }

    printf("Minimum element = %d\n", min);
}

// Display list
void display()
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Find Maximum\n");
        printf("6. Find Minimum\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFirst(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertLast(value);
            break;

        case 3:
            deleteFirst();
            break;

        case 4:
            deleteLast();
            break;

        case 5:
            findMaximum();
            break;

        case 6:
            findMinimum();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}