#include <iostream>
using namespace std;

class Heap
{
public:
    int array[100];
    int size;

    Heap()
    {
        array[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        array[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (array[parent] < array[index])
            {
                swap(array[parent], array[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << array[i] << " ";
        }
    }
};
void MinHeapify(int array[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && array[largest] < array[left])
    {
        largest = left;
    }
    if (right < n && array[largest] < array[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(array[largest], array[i]);
        MinHeapify(array, n, largest);
    }
}
void MaxHeapify(int array[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && array[smallest] > array[left])
    {
        smallest = left;
    }
    if (right < n && array[smallest] > array[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(array[smallest], array[i]);
        MaxHeapify(array, n, smallest);
    }
}

int main()
{
    Heap heap;
    int array[9] = {-1, 7,1,6,2,5,9,10,2};
    int size = 9;
    cout<<"The Miximum Heap: ";
    for (int i = size / 2; i > 0; i--)
    {
        MinHeapify(array, size, i);
    }
    for (int i = 1; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout<<"The Minimum Heap: ";
     for (int i = size / 2; i > 0; i--)
    {
        MaxHeapify(array, size, i);
    }
    for (int i = 1; i < size; i++)
    {
        cout << array[i] << " ";
    }
}