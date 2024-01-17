#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

// ============================= Create Node =============================
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// ============================= Insert At Beginning =============================
Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = head;
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

    /*
Index=> 0      1     2     3      4   5     6     7
        head   1st   2nd   3rd        4th   5th   6th
        Node   Node  Node  Node       Node  Node  Node
                                  ^
                           let index =  4

        currentIndex < 3 , (4-1)
        current = head address (address of 0th node)
        currentIndex = 0

        loop start =>
        At the End of step 1 : current = address of 1st node, currentIndex = 1
        At the End of step 2 : current = address of 2nd node, currentIndex = 2
        At the End of step 3 : current = address of 3rd node, currentIndex = 3

        loop end => (so now current = address of 3rd node and currentIndex = 3)

Index=> 0   1   2   3     4   5   6
                    ^
                (currentIndex)


        newNode->next  = current->next(address of 4th node)
        current->next(address of 4th node) =  addres of new node

Index=> 0      1      2          3            4          5     6      7
        head   1st    2nd        3rd        newNode      4th    5th   6th
        Node   Node   Node       Node                    Node   Node  Node
                            (currentIndex)
                               (current)

    */
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
    current->next = newNode;
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

// ============================= Delete At Index =============================
Node *deleteAtIndex(Node *head, int index)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete at the given index." << endl;
        return nullptr;
    }

    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *current = head;
    Node *prev = nullptr;
    int count = 0;

    while (current != nullptr && count < index)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        cout << "Index out of bounds. Cannot delete at the given index." << endl;
        return head;
    }

    prev->next = current->next;
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

// ============================= Display =============================
void display(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
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
        cout << "7. Display\n";
        cout << "8. Find length\n";
        cout << "9. Search value\n";
        cout << "10. Quit\n";
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
            cout << "Linked List: ";
            display(head);
            break;
        case 8:
            cout << "Length of the Linked List: " << findLength(head) << endl;
            break;
        case 9:
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
        case 10:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    // Clean up memory by deleting nodes
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
// ======================================================================