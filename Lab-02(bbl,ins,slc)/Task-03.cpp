#include <iostream>
#include <vector>
using namespace std;



void MyinsertionSort(string arr[][2], int size)
{
    int j;
    for (int i = 1; i < size; i++)
    {
        string currentSeatNo = arr[i][1];
        string currentPosition = arr[i][0];
        j=i-1;

        while (j >= 0 && arr[j][1] > currentSeatNo)
        {
            arr[j+1][0]=arr[j][0];
            arr[j+1][1]=arr[j][1];
            j--;
        }
        arr[j + 1][1] = currentSeatNo;
        arr[j + 1][0] = currentPosition;
    }
}

int main()
{
    string arr[8][2] = {{"Emp", "6"},
                        {"CFO", "3"},
                        {"MGR", "5"},
                        {"Emp", "6"},
                        {"VP", "4"},
                        {"CTO", "2"},
                        {"MGR", "5"},
                        {"CEO", "1"}};

    MyinsertionSort(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
