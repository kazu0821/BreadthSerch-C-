#include "SortedList.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Creating empty list" << endl;
    SortedList list1;
    list1.print();
    cout << "Calling isEmpty()" << endl;
    cout << list1.isEmpty() << endl;
    cout << "Inserting 0, 2, 4" << endl;
    for (int i = 0; i <= 4; i+=2)
        list1.insert(i);
    list1.print();
    cout << "Calling isEmpty()" << endl;
    cout << list1.isEmpty() << endl;
    cout << "Inserting -1, 1, 3" << endl;
    for (int i = -1; i <= 3; i += 2)
        list1.insert(i);
    list1.print();
    cout << "Inserting 3" << endl;
    list1.insert(3);
    list1.print();
    cout << "Removing smallest" << endl;
    list1.removeSmallest();
    list1.print();
    cout << "Calling remove(4)" << endl;
    list1.remove(4);
    list1.print();
    cout << "Calling remove(0)" << endl;
    list1.remove(0);
    list1.print();
    cout << "Calling remove(5)" << endl;
    list1.remove(5);
    list1.print();
    cout << "Calling remove(2)" << endl;
    list1.remove(2);
    list1.print();
    cout << "Calling remove(1)" << endl;
    list1.remove(1);
    list1.print();
    cout << "Calling remove(3)" << endl;
    list1.remove(3);
    list1.print();
    cout << "Calling remove(3)" << endl;
    list1.remove(3);
    list1.print();
    cout << "Calling remove(3)" << endl;
    list1.remove(3);
    list1.print();
    cout << "Calling insert(3)" << endl;
    list1.insert(3);
    list1.print();
    cout << "Calling insert(1)" << endl;
    list1.insert(1);
    list1.print();
    list1.clear();
    cout << "Calling clear()" << endl;
    list1.print();
    cout << "DONE" << endl;
    return 0;
}
