#include <iostream>
using namespace std;

// ============================ Node ============================
class Node
{
public:
    int data;
    Node *link;

    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};

// ============================ Queue ============================
class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // ============================ EnQueue ============================
    void enqueue(int data)
    {
        Node *temp = new Node(data);
        if (!temp)
        {
            cout << "\nQueue Overflow";
            exit(1);
        }

        if (rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->link = temp;
            rear = temp;
        }
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    // ============================ DeQueue ============================
    void dequeue()
    {
        Node *temp;
        if (isEmpty())
        {
            cout << "\nQueue Underflow" << endl;
            exit(1);
        }
        else
        {
            temp = front;
            front = front->link;
            free(temp);
        }
    }

    // ============================ Peek ============================
    int peek()
    {
        if (!isEmpty())
            cout << "\nPeek: " << front->data;
        else
        {
            cout << "Queue is empty." << endl;
            exit(1);
        }
    }

    // ============================ Display ============================
    void display()
    {
        Node *temp;
        if (isEmpty())
        {
            cout << "\nQueue is empty.";
        }
        else
        {
            temp = front;
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

// ============================ Main ============================
int main()
{
    int choice, data;
    Queue q;
    do
    {
        cout << "\n============================================\n";
        cout << "Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data : ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Exit";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// ========================================================