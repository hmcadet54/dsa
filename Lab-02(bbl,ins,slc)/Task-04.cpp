#include <iostream>
using namespace std;

void sorting_rec(int date[][3], int first, int second) {

    //this is a check to determine wether the array is sorted or not
    if (first >= second) {
        return;
    }

    int minimum_index = first;
    for (int j = first + 1; j <= second; j++) {
        if (date[j][2] < date[minimum_index][2]) {
            minimum_index = j;
        }
    }

    int temp[3];
    for (int k = 0; k < 3; k++) {
        temp[k] = date[first][k];
        date[first][k] = date[minimum_index][k];
        date[minimum_index][k] = temp[k];
    }
    sorting_rec(date, first + 1, second);
}

int main() {
    int date[5][3];
    int temp, temp1, temp2;

    // Taking input from the user as dates (dd/mm/yyyy)
    for (int i = 0; i < 5; i++) {
        cout << "Enter " << i + 1 << " date: (dd/mm/yyyy)" << endl;
        for (int j = 0; j < 3; j++) {
            cin >> date[i][j];
        }
    }

    // Sorting the dates using recursive selection sort
    sorting_rec(date, 0, 4); // sending data array, first index and last index i-e 0 and 4

    // Printing the sorted dates
    cout << "Sorted Dates: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            cout << date[i][j];
            if (j != 2) {
                cout << "/";
            }
        }
        cout << endl;
    }

    return 0;
}
