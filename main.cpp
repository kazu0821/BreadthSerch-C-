#include <iostream>
#include "Lab5.h";

using namespace std;
int main() {
    Node *r = makeTree(7);
    printTree(r);
    bool quit = false;
    do {
        cout << endl << "Enter new value (or -1 to quit): ";
        int v;
        cin >> v;
        if (v != -1) {
            cout << "Before insertion, contains(r," << v << ") = " << contains(r, v) << "." << endl;
            insertValue(r, v);
            cout << "After  insertion, contains(r," << v << ") = " << contains(r, v) << "." << endl;
            cout << "Updated tree = " << endl;
            printTree(r);
        } else quit = true;

    } while (!quit);
    cout << endl << "inorder traversal = { ";
    inorder(r);
    cout << "}" << endl;
    while (r != nullptr) {
        cout << "removing " << getSmallest(r) << endl;
        r = removeSmallest(r);
        printTree(r);
    }
    cout << endl << "DONE" << endl;


    return 0;
}