#include <iostream>
using namespace std;

// A Node type for binary trees
struct Node {
    int data;
    Node *left, *right;
};

// Return a new node with the given data, left and right subtrees.
Node * makeTree(int data, Node *left = nullptr, Node *right = nullptr) {
    Node * temp = new Node;
    temp->left = left;
    temp->right = right;
    temp->data = data;
    return temp;
}


// Return the smallest value in a nonempty BST with root r.
int getSmallest(Node * r) {
    // FILL IN MISSING CODE
    if(r == nullptr)
        return 0;


    else if(r->left == nullptr)
        return r->data;
    else
        return getSmallest(r->left);



    //return 0; // remove this line after filling in missing code
}

// Remove the node with smallest value from a nonempty BST
// and return a pointer to the updated tree.
// Usually return value will be r, unless smallest value is in r.
// In case smallest value is in r, return r->right.
// Make sure to call delete on the node that is removed.
Node * removeSmallest(Node * r) {

                                            //This part
    if (r->left == nullptr) {
        Node * temp = r;
        r = r->right;
        delete temp;
        return r;
    }
    // FILL IN MISSING CODE

    Node* parent = r, *child = r->left;


    while (child->left != nullptr) {
        parent = child;
        child = child->left;
    }
    parent->left = child->right;
    delete child;
    return r;



//
    }


    // Cut the parent relationship to the min,
    // and take the right child of the min.







// Return a pointer to the node that will be
// the parent of a new node containing v,
// or return nullptr if v is already in tree.
// This function is complete. There is no code to add.



// Return true if the BST contains v and false otherwise.
bool contains(Node * r, int v) {
    if (r == nullptr){
        return false;
    }
    // FILL IN MISSING CODE

    Node *nodeptr =r;

    while(nodeptr != nullptr){
        if(nodeptr->data == v) {
            return true;
        }
        else if (v < nodeptr->data) {


            return contains(nodeptr->left, v);
        }
        else {


            return contains(r->right, v);
        }

    }


    }


Node * findInsertionPoint(Node *r, int v) {
    if (r->data == v)
        return nullptr;


    if (v < r->data) {
        if (r->left == nullptr)
            return r;
        return findInsertionPoint(r->left, v);
    }
    else if(v > r->data){
        if (r->right == nullptr)
            return r;
        return findInsertionPoint(r->right, v);
    }
    else
        return nullptr;
}


// Insert v into a nonempty binary search tree.
// Call findInsertionPoint to get a pointer to
// the node below which v should be inserted.
// If findInsertionPoint returns nullptr, don't do anything
// since that means v is already in the tree.


void insertValue(Node * r, int v) {             // This part
    Node * p = findInsertionPoint(r, v);
    // FILL IN MISSING CODE

    if (p == nullptr){
        return;
    }

    if(v <= p->data){
        p->left =makeTree(v);

    }
    else{
        p->right = makeTree(v);
    }


    }



// Output the values in the BST using an inorder traversal.
void inorder(Node * r) {
    // FILL IN MISSING CODE

    if(r != nullptr){
        inorder( r->left);
        cout << r->data << " ";
        inorder(r->right);


    }

}

// Print the binary tree.
// This function is complete. There is no code to add.
void printTree(Node * r, int offset = 4) {
    char c = r == nullptr ? '.' : '-';
    for (int i = 0; i < offset - 4; i++)
        cout << ' ';
    for (int i = 0; i < 4; i++)
        cout << c;
    if (r != nullptr) {
        cout << r->data << endl;
        offset += 4;
        printTree(r->left, offset);
        printTree(r->right, offset);
    }
    else cout << '.' << endl;
}


// DON'T ALTER THE CODE BELOW UNLESS TO COMMENT OUT SOME TESTS

