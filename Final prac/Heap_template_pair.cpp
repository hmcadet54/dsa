#include <iostream>
using namespace std;

template <class T1, class T2>
void MinHeapify(pair<T1, T2> array[], int n, int i)
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
template <class T1, class T2>
void MaxHeapify(pair<T1, T2> array[], int n, int i)
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
template <class T1, class T2>
void Delete(pair<T1, T2> array[], int size)
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

template <class T1, class T2>
void heapsort(pair<T1, T2> array[], int size)
{
    while (size > 1)
    {
        swap(array[size], array[1]);
        size--;
        MinHeapify(array, size, 1);
    }
}

template <class T1, class T2>
class Heap
{
public:
    pair<T1, T2> array[100];
    int size;

    Heap()
    {
        array[0] = make_pair(-1, "0");
        size = 0;
    }

    void insert(pair<T1, T2> val)
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
            cout << "(" << array[i].first << ", " << array[i].second << ") ";
        }
    }
};

int main()
{
    Heap<int, string> heap;
    pair<int, string> array[6] = {make_pair(1, "abdullah"), make_pair(2, "haroon"), make_pair(3, "shafiq"), make_pair(4, "zaffar"), make_pair(5, "malik"), make_pair(6, "taha")};
    int size = 6;
    for (int i = (size / 2) - 1; i > 0; i--)
    {
        MinHeapify<int, string>(array, size, i);
    }
    for (int i = 0; i < size; i++)
    {
        cout << "(" << array[i].first << ", " << array[i].second << ") ";
    }
    heapsort(array,size);
        for (int i = 0; i < size; i++)
    {
        cout << "(" << array[i].first << ", " << array[i].second << ") ";
    }
    cout << endl;
}
