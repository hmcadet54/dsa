#include <iostream>
using namespace std;

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
void Delete(int array[], int size)
{
    if (size == 0)
    {
        cout << "NO data to delete!";
        return;
    }
    array[1] = array[size];
    size--;
    int i = 0;
    while (i < size)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left < size && array[i] < array[left])
        {
            swap(array[i], array[left]);
            i = left;
        }
        if (right < size && array[i] < array[right])
        {
            swap(array[i], array[right]);
            i = right;
        }
        else
        {
            return;
        }
    }
    for (int i = 0; i < size; i++)
    {
        MinHeapify(array, size, i);
    }
}

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
            if (array[parent] > array[index])
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

int main()
{
    Heap heap;
    // min =assending
    // max =dess
    // 35,33,42,10,14,19,27,44,26,31
    int array[11] = {-1, 35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int size = 11;
    for (int i = size / 2; i > 0; i--)
    {
        MaxHeapify(array, size, i);
    }
    for (int i = 1; i < size; i++)
    {
        cout << array[i] << " ";
    }
    Delete(array, 11);
    cout << endl;
    for (int i = size / 2; i > 0; i--)
    {
        MinHeapify(array, size, i);
    }
    for (int i = 1; i < size-1; i++)
    {
        cout << array[i] << " ";
    }
}
