#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

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

Node* deleteFront(Node* head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from the front." << endl;
        return nullptr;
    }

    Node* temp = head->next;
    delete head;
    return temp;
}

Node* deleteEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from the end." << endl;
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return head;
}

Node* deleteMiddle(Node* head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from the middle." << endl;
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* slowPtr = head;
    Node* fastPtr = head;
    Node* prev = nullptr;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    if (prev != nullptr) {
        prev->next = slowPtr->next;
        delete slowPtr;
    } else {
        head = deleteFront(head);
    }

    return head;
}

int findLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

bool searchValue(Node* head, int data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, data, index;

    do {
        cout<<"\n============================================\n";
        cout << "Menu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at index\n";
        cout << "4. Delete from front\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from middle\n";
        cout << "7. Display\n";
        cout << "8. Find length\n";
        cout << "9. Search value\n";
        cout << "10. Quit\n";
        cout<<"============================================\n";
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
                head = deleteMiddle(head);
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
        current = next;
    }

    return 0;
}