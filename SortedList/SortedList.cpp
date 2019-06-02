

#include "SortedList.h"
#include <iostream>
using namespace std;


SortedList::SortedList() {

        headPtr = nullptr;


};



bool SortedList::isEmpty()    {

        return (headPtr == nullptr);

};





void SortedList::removeSmallest() {  // THIS PART


        Node *current = headPtr;



        if (headPtr == nullptr) {
            cout << " List is nothing";

            return ;

        }


    else  {

            headPtr = current->next;

            delete current;



    }

    return ;

};


void SortedList::remove(int d) {   // THIS PART


    Node *current = headPtr;
    Node *previous = current;


    if (headPtr == nullptr) {
        cout << " List is Empty";
        return;


    }

//    if(current->data == d){
//
//    }



    while (current != nullptr && current->data != d) {


        previous = current;
        current = current->next;


        if (current) {
            previous->next = current->next;

            delete current;

        }


    }



};


    void SortedList::insert(int d) {


        Node *current = new Node();

        current->data = d;
        current->next = nullptr;

        if (isEmpty()) {

            headPtr = current;

        } else {
            Node *temp = headPtr;

            while (d < temp->next->data && temp->next != nullptr) {

                temp = temp->next;
                current->next = temp->next;

            }
            temp->next = headPtr;

        }

    };


    void SortedList::print() const {
        Node *current = headPtr;


        cout << " { ";


        while (current != nullptr) {
            cout << current->data;
            current = current->next;


            cout << " } ";
        };

    };

    void SortedList::clear() {// this part

        if (isEmpty() != true) {

            Node *cut;
            while (headPtr->next != nullptr) {

                cut = headPtr;

                headPtr = headPtr->next;
                delete cut;
            }

            headPtr = nullptr;

        }; // clear the list

    };





