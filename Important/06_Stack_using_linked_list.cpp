// Implement a stack using singly linked list using class

#include <iostream>
using namespace std;

// ============================= Node =============================
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

// ============================= Stack =============================
class Stack
{
    Node *top;

public:
    Stack() { top = NULL; }

    // ============================ Push ============================
    void push(int data)
    {

        Node *temp = new Node(data);
        if (!temp)
        {
            cout << "\nStack Overflow";
            exit(1);
        }

        temp->data = data;
        temp->link = top;
        top = temp;
    }
    bool isEmpty()
    {
        return top == NULL;
    }

    // ============================ Peek ============================
    int peek()
    {
        if (!isEmpty())
            cout << "\nPeek : " << top->data;
        else
            exit(1);
    }

    // ============================ Pop ============================
    void pop()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else
        {
            temp = top;
            top = top->link;
            free(temp);
        }
    }

    // ============================ Display ============================
    void display()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "\nStack Underflow";
            exit(1);
        }
        else
        {
            temp = top;
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

// ============================= Main Function =============================
int main()
{
    int choice, data;
    Stack s;
    do
    {
        cout << "\n============================================\n";
        cout << "Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
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
            s.push(data);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exit";
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
// ======================================================================