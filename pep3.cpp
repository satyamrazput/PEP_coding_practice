#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert at end
void insert(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete duplicate nodes completely
Node* deleteDuplicates(Node *head)
{
    Node dummy;
    dummy.next = head;

    Node *prev = &dummy;
    Node *curr = head;

    while(curr != NULL)
    {
        if(curr->next != NULL && curr->data ==  curr->next->data)
        {
            int x = curr->data;

            while(curr != NULL && curr->data == x)
                curr = curr->next;

            prev->next = curr;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}

// Display linked list
void display(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        insert(head, value);
    }

    head = deleteDuplicates(head);

    cout << "Linked List after removing duplicates: ";
    display(head);

    return 0;
}