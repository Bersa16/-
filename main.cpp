#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main() {
    try {
        IntegerArray arr(5);
        cout << "Initial size: " << arr.getSize() << endl;
        arr.pushBack(10);
        arr.pushBack(20);
        arr.pushFront(5);
        cout << "Size after adding elements: " << arr.getSize() << endl;
        cout << "Element at index 0: " << arr[0] << endl;
        cout << "Element at index 1: " << arr[1] << endl;
        arr[1] = 15;
        cout << "The element with index 1 after the change: " << arr[1] << endl;
        arr.remove(1);
        cout << "Size after deleting an item: " << arr.getSize() << endl;
        int index = arr.find(10);
        if (index != -1) {
            cout << "Element 10 is found in position: " << index << endl;
        }
        else {
            cout << "Element 10 was not found" << endl;
        }
        cout << "An attempt to access a non-existent element: " << arr[10] << endl;
    }
    catch (const bad_range& e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (const bad_length& e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (const std::exception& e) {
        cout << "The standard exception: " << e.what() << endl;
    }

    return 0;
}