#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// ========================== Create Node ==========================
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// ======================= Insert At Beginning =======================
Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == nullptr)
    {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// ============================= Insert At End =============================
Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == nullptr)
    {
        return newNode;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// ============================= Insert At Index =============================
Node *insertAtIndex(Node *head, int data, int index)
{
    if (index < 0)
    {
        cout << "Invalid index. Please enter a non-negative index." << endl;
        return head;
    }

    if (index == 0)
    {
        return insertAtBeginning(head, data);
    }

    Node *newNode = createNode(data);
    Node *current = head;
    int currentIndex = 0;
    while (current != nullptr && currentIndex < index - 1)
    {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr)
    {
        cout << "Invalid index. Index exceeds the length of the list." << endl;
        return head;
    }

    newNode->next = current->next;
    if (current->next != nullptr)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// ============================= Delete Front =============================
Node *deleteFront(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete from the front." << endl;
        return nullptr;
    }

    Node *temp = head->next;
    if (temp != nullptr)
    {
        temp->prev = nullptr;
    }

    delete head;
    return temp;
}

// ============================= Delete End =============================
Node *deleteEnd(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete from the end." << endl;
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
    return head;
}

// ============================= Delete at Index =============================
Node *deleteAtIndex(Node *head, int index)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete at index." << endl;
        return nullptr;
    }

    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }

    Node *current = head;
    int count = 0;

    while (current != nullptr && count < index)
    {
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        cout << "Index out of bounds. Cannot delete." << endl;
        return head;
    }

    if (current->prev != nullptr)
    {
        current->prev->next = current->next;
    }

    if (current->next != nullptr)
    {
        current->next->prev = current->prev;
    }

    delete current;
    return head;
}

// ============================= Find Length =============================
int findLength(Node *head)
{
    int length = 0;
    Node *current = head;
    while (current != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}

// ============================= Search =============================
bool searchValue(Node *head, int data)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// ============================= Display Forward =============================
void displayForward(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// ============================= Display Backward =============================
void displayBackward(Node *head)
{
    Node *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        current = current->next;
    }

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

// ============================= Main Function =============================
int main()
{
    Node *head = nullptr;
    int choice, data, index;

    do
    {
        cout << "\n============================================\n";
        cout << "Menu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at index\n";
        cout << "4. Delete from front\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete at index\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Find length\n";
        cout << "10. Search value\n";
        cout << "11. Quit\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at the beginning: ";
            cin >> data;
            head = insertAtBeginning(head, data);
            break;
        case 2:
            cout << "Enter data to insert at the end: ";
            cin >> data;
            head = insertAtEnd(head, data);
            break;
        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter index: ";
            cin >> index;
            head = insertAtIndex(head, data, index);
            break;
        case 4:
            head = deleteFront(head);
            break;
        case 5:
            head = deleteEnd(head);
            break;
        case 6:
            cout << "Enter index to delete: ";
            cin >> index;
            head = deleteAtIndex(head, index);
            break;
        case 7:
            cout << "Doubly Linked List (Forward): ";
            displayForward(head);
            break;
        case 8:
            cout << "Doubly Linked List (Backward): ";
            displayBackward(head);
            break;
        case 9:
            cout << "Length of the Linked List: " << findLength(head) << endl;
            break;
        case 10:
            cout << "Enter value to search: ";
            cin >> data;
            if (searchValue(head, data))
            {
                cout << "Value found in the list." << endl;
            }
            else
            {
                cout << "Value not found in the list." << endl;
            }
            break;
        case 11:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);

    return 0;
}
