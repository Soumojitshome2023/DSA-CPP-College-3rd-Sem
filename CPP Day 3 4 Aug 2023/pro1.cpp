#include <iostream>
#include <cstdlib>

using namespace std;
#define max 10

int stack_s[max], stack_p[max], stack_q[max], top_s = -1, top_p = -1, top_q = -1;

//=============================== Push function ===============================
void push(int val, int stack_name[], int *top_name) {
    if (*top_name >= max - 1)
        cout << "Overflow";
    else
        stack_name[++(*top_name)] = val;
}

//================================= Pop function =================================
void pop(int stack_name[], int *top_name) {
    if (*top_name <= -1)
        cout << "Underflow";
    else {
        cout << "Popped element: " << stack_name[(*top_name)];
        (*top_name)--;
    }
}

//===================== Display function for a specific stack =====================
void display(int top_name, int stack_name[], const char* stack_name_str) {
    int i;
    if (top_name >= 0) {
        cout << "Stack elements in " << stack_name_str << " are: ";
        for (i = top_name; i >= 0; i--)
            cout << stack_name[i] << " ";
    } else
        cout << stack_name_str << " is empty";
}

//================================ Copy function ================================
int copy(int xnum, int stack_no) {
    int i;
    if (stack_no == 1) {
        for (i = top_s; i >= top_s - xnum + 1; i--) {
            if (i >= 0) {
                int val = stack_s[i];
                push(val, stack_p, &top_p);
            } else {
                cout << "Not enough elements in Stack S to copy." << endl;
                return 0;
            }
        }
        display(top_p, stack_p, "Stack P");
    } else if (stack_no == 2) {
        for (i = top_s; i >= top_s - xnum + 1; i--) {
            if (i >= 0) {
                int val = stack_s[i];
                push(val, stack_q, &top_q);
            } else {
                cout << "Not enough elements in Stack S to copy." << endl;
                return 0;
            }
        }
        display(top_q, stack_q, "Stack Q");
    }
}

// ======================================== Main ========================================
int main() {
    int ch, val, xnum, stack_no, i;

    do {
        cout << endl;
        cout << "==========================" << endl;
        cout << "1 Push" << endl;
        cout << "2 Pop" << endl;
        cout << "3 Display Stack" << endl;
        cout << "4 Copy Elements from Stack S" << endl;
        cout << "5 Exit" << endl;
        cout << "==========================" << endl;
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the value to be inserted in 'Stack_S': ";
                cin >> val;
                push(val, stack_s, &top_s);
                break;
            case 2:
                pop(stack_s, &top_s);
                break;
            case 3:
                cout << "Enter 1 for Stack S, 2 for Stack P, 3 for Stack Q: ";
                cin >> stack_no;
                if (stack_no == 1)
                    display(top_s, stack_s, "Stack S");
                else if (stack_no == 2)
                    display(top_p, stack_p, "Stack P");
                else if (stack_no == 3)
                    display(top_q, stack_q, "Stack Q");
                else
                    cout << "Invalid stack number." << endl;
                break;
            case 4:
                cout << "Enter number of elements you want to copy: ";
                cin >> xnum;
                cout << "Enter 1 for Stack P, 2 for Stack Q: ";
                cin >> stack_no;
                copy(xnum, stack_no);
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Wrong Choice";
        }

    } while (ch != 5);

    return 0;
}


// =====================================================================================