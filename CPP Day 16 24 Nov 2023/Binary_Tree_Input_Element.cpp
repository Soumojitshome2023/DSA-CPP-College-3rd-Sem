#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// ========================== Create Node ==========================
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// ========================== Insert Data ==========================
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// ========================== Pre Order ==========================
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// ========================== In Order ==========================
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// ========================== Post Order ==========================
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    struct node *root = NULL;
    int inputValue;

    // Taking user input to build the binary tree
    cout << "Enter values to insert into the binary tree (enter -1 to stop):" << endl;
    while (true)
    {
        cin >> inputValue;
        if (inputValue == -1)
        {
            break;
        }
        root = insert(root, inputValue);
    }

    // Display the binary tree using different traversals
    cout << "Pre-order Traversal:" << endl;
    preOrder(root);

    cout << "\nIn-order Traversal:" << endl;
    inOrder(root);

    cout << "\nPost-order Traversal:" << endl;
    postOrder(root);

    return 0;
}

// ================================================================