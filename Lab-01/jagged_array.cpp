#include <iostream>
using namespace std;
#include <iostream>

using namespace std;

int main() {
    int **jaggedArray = new int*[5];  
    int sizes[5] = {10, 10, 10, 10, 10};  
    int i, j;


    for (i = 0; i < 5; i++) {
        jaggedArray[i] = new int[sizes[i]];
    }



    for (i = 0; i < 5; i++) {
        cout << "Enter data for row " << i + 1 << ":" << endl;
        for (j = 0; j < sizes[i]; j++) {
            cout << "Element " << j + 1 << ": ";
            cin >> jaggedArray[i][j];
        }
    }

    for (i = 0; i < 5; i++) {
        cout << "Row " << i + 1 << " elements: ";
        for (j = 0; j < sizes[i]; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    for (i = 0; i < 5; i++) {
        delete[] jaggedArray[i];
    }

    delete[] jaggedArray;

    return 0;
}

