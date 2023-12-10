#include <iostream>
using namespace std;
int main()
{
    int array[10] = {5, 1, 3, 6, 2, 9, 7, 4, 8, 10};
    int length = sizeof(array) / sizeof(array[0]);

    int temp;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout << "Sorted Array: ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}