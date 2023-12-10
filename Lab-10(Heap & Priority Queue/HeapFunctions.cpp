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
void heapsort(int array[], int size)
{
    while (size > 1)
    {
        swap(array[size], array[1]);
        size--;
        MaxHeapify(array, size, 1);
    }
}

int main()
{
    Heap heap;
    heap.insert(45);
    heap.insert(55);
    heap.insert(65);
    heap.insert(75);
    heap.insert(85);
    heap.print();
    cout << endl;

    int array[6] = {-1, 54,53,55,52,50};
    int size = 6;
    for (int i = size / 2; i > 0; i--)
    {
        MinHeapify(array, size, i);
    }
    for (int i = 1; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
     for (int i = size / 2; i > 0; i--)
    {
        MaxHeapify(array, size, i);
    }
    heapsort(array,size);
    for (int i = 1; i <=size; i++)
    {
        cout << array[i] << " ";
    }
}