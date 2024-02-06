#include <iostream>
using namespace std;
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// ======================== Create Node ========================
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

// ======================== Pre Order ========================
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// ======================== In Order ========================
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data;
        inOrder(root->right);
    }
}

// ======================== Post Order ========================
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data;
    }
}

// ======================== Main ========================
int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // ======================= Pre Order =======================
    // Pre Order :  Root -> Left SubTree -> Right SubTree
    // Ans : 4 1 5 2 6
    cout << "Pre-order Traversal:" << endl;
    preOrder(p);
    // ===========================================================

    // ======================= In Order =======================
    // In Order : Left SubTree -> Root ->  Right SubTree
    // Ans : 5 1 2 4 6
    cout << "\nIn-order Traversal:" << endl;
    inOrder(p);
    // ===========================================================

    // ======================= Post Order =======================
    // Post Order:  Left SubTree -> Right SubTree -> Root
    // Ans : 5 2 1 6 4
    cout << "\nPost-order Traversal:" << endl;
    postOrder(p);

    return 0;
}

// ========================================================