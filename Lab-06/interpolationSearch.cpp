#include <iostream>
using namespace std;

void iterpolationsearch(int array[], int start, int end, int key)
{
    int possition = 0;
    if (start <= end && key > array[start] && key <= array[end])
    {
        possition = start + (((key-array[start]) * (end - start)) / (array[end] - array[start]));
    }
    if(array[possition]==key)
    {
        cout<<"The element present at: "<<possition;
    }
    if(array[possition]<key)
    {
        iterpolationsearch(array,possition+1,end,key);
    }
    if(array[possition]>key)
    {
        iterpolationsearch(array,start,possition-1,key);
    }
}

int main()
{
    int array[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int start = 0;
    int end = 9;
    int key = 13;

    iterpolationsearch(array, start, end, key);
}