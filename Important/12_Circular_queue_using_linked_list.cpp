#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

// Circular Queue Using Linked List

Node *front = nullptr;
Node *rear = nullptr;

// ============================= EnQueue =============================
void enqueue()
{
    int val;
    cout << "Enter the value : ";
    cin >> val;

    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (front == nullptr)
    {
        front = newNode;
        rear = newNode;
        rear->next = front; // Making it circular
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Making it circular
    }
}

// ============================= DeQueue =============================
void dequeue()
{
    if (front == nullptr)
    {
        cout << "Queue Underflow";
        return;
    }

    cout << "Deleted element : " << front->data;

    if (front == rear)
    {
        delete front;
        front = nullptr;
        rear = nullptr;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        rear->next = front; // Adjusting rear to maintain circularity
        delete temp;
    }
}

// ============================= Display =============================
void display()
{
    if (front == nullptr)
    {
        cout << "Queue is Empty";
        return;
    }

    Node *temp = front;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
}

// ============================= Main =============================
int main()
{
    int ch;

    do
    {
        cout << "\n1 Insert\n";
        cout << "2 Delete\n";
        cout << "3 Display\n";
        cout << "4 Exit\n";
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Wrong Choice";
        }
    } while (ch != 4);

    return 0;
}
