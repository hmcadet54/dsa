#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size = 10;
    vector<int> safeArray(size);

    try {
        for (int i = 0; i < size + 1; i++) {
            cout << "Enter the " << i + 1 << " element of array: ";
            cin >> safeArray.at(i);
        }
    } catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Array is full" << endl;
    }

    cout << "Array is: ";
    for (int i = 0; i < safeArray.size(); i++) {
        cout << safeArray[i] << " ";
    }
    
    return 0;
}
