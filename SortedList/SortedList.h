#ifndef SORTEDLIST_H
#define SORTEDLIST_H

using namespace std;
// represents a list of values sorted in ascending order


class SortedList {
private:
    struct Node {
        int data;
        Node *next;


    };
    Node *headPtr;


public:

    SortedList();




    //SortedList(const SortedList & other);  // copy constructor

    //~SortedList(); // destructor




    bool isEmpty();

    // return ( headPtr == nullptr);



    void removeSmallest();


    void insert(int d);

//        Node *current = new Node();
//
//        current->data = d;
//        current->next = nullptr;
//
//        if( isEmpty()){
//
//            headPtr = current;
//
//        }
//
//        else{
//        Node *temp = headPtr;
//         while(d < temp->next->data  && temp-> next!= nullptr){
//
//             temp =temp->next;
//             current-> next = temp->next;
//
//         }
//            temp->next = headPtr;
//
//        }

    // insert d in the correct position to maintain order



    void remove(int d);

//        Node *current = head;
//
//        if (head == null){
//            return ;
//
//        }
//
//        while(current-> next != null){
//
//            if (current->data == current->next->data)
//            {
//                Node* nextNext = current->next->next;
//                (current->next);
//                current->next = nextNext;
//            }
//            else {
//                current = current->next; // only advance if no deletion
//            }
//        }

    // remove one occurence of d in the list, if there is one

    void print() const;

//        cout << " { ";
//
//    Node *headPtr, *tailPtr;
//
//    while(headPtr != nullptr){
//    cout << headPtr-> data;
//    headPtr = headPtr-> next;
//
//
//    cout << " } ";
//    }

    // print the list with braces and a space between each two values.


    void clear();

//        if (isEmpty() != true) {
//            Node* delete;
//            while (headPtr->next != nullptr) {
//                delete = headPtr;
//                headPtr = headPtr->next; //GETTING ERRORS IN HERE.
//                delete headPtr;
//            }
//
//            headPtr = nullptr;
//
//    }; // clear the list


};

#endif;
