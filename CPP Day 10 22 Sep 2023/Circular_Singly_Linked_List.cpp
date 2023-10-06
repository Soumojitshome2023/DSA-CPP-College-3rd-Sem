#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// ============================= Create Node =============================
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// ============================= Insert At Beginning ============================= 
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        newNode->next = newNode; // Make it circular
        return newNode;
    }
    newNode->next = head;
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode; // Update last node's next
    return newNode; // Return the new head
}

// ============================= Insert At End =============================
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        newNode->next = newNode; // Make it circular
        return newNode;
    }
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode; // Update last node's next
    newNode->next = head; // Make it circular
    return head;
}

// ============================= Insert At Index =============================
Node* insertAtIndex(Node* head, int data, int index) {
    if (index < 0) {
        cout << "Invalid index. Please enter a non-negative index." << endl;
        return head;
    }

    if (index == 0) {
        return insertAtBeginning(head, data);
    }

    Node* newNode = createNode(data);
    Node* current = head;
    int currentIndex = 0;
    while (current != nullptr && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        cout << "Invalid index. Index exceeds the length of the list." << endl;
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// ============================= Delete Front =============================
Node* deleteFront(Node* head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from the front." << endl;
        return nullptr;
    }

    Node* temp = head->next;
    if (temp == head) { // Only one node in the list
        delete head;
        return nullptr;
    }

    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = temp;
    delete head;
    return temp;
}

// ============================= Delete End =============================
Node* deleteEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from the end." << endl;
        return nullptr;
    }

    if (head->next == head) { // Only one node in the list
        delete head;
        return nullptr;
    }

    Node* current = head;
    Node* previous = nullptr;
    while (current->next != head) {
        previous = current;
        current = current->next;
    }

    previous->next = head;
    delete current;
    return head;
}

// ============================= Delete At Index =============================
Node* deleteAtIndex(Node* head, int index) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return nullptr;
    }

    if (index < 0) {
        cout << "Invalid index. Please enter a non-negative index." << endl;
        return head;
    }

    if (index == 0) {
        Node* temp = head->next;
        if (temp == head) { // Only one node in the list
            delete head;
            return nullptr;
        }

        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = temp;
        delete head;
        return temp;
    }

    Node* current = head;
    int currentIndex = 0;
    Node* previous = nullptr;

    while (current != nullptr && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        cout << "Invalid index. Index exceeds the length of the list." << endl;
        return head;
    }

    previous->next = current->next;
    delete current;
    return head;
}


// ============================= Find Length =============================
int findLength(Node* head) {
    if (head == nullptr) {
        return 0;
    }

    int length = 0;
    Node* current = head;
    do {
        length++;
        current = current->next;
    } while (current != head);

    return length;
}

// ============================= Search =============================
bool searchValue(Node* head, int data) {
    if (head == nullptr) {
        return false;
    }

    Node* current = head;
    do {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    } while (current != head);

    return false;
}


// ============================= Display =============================
void display(Node* head) {
    if (head == nullptr) {
        cout << "Empty Circular Linked List" << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << current->data << " ";

    cout << endl;
}

// ============================= Main Function =============================
int main() {
    Node* head = nullptr;
    int choice, data, index;

    do {

        cout << "\n===================Menu:===================\n";
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
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
                if (searchValue(head, data)) {
                    cout << "Value found in the list." << endl;
                } else {
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
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        if (next == head) {
            break;
        }
        current = next;
    }

    return 0;
}
// ======================================================================