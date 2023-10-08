//Quick sort


#include <iostream>
using namespace std;


int partition(int array[], int left, int right)
{
    int pivot=array[right];
    int i=left-1;
    for (int j=left;j<right;j++)
    {
        if (array[j]<pivot)
        {
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[right]);
    return i+1;
}

void quicksort(int array[], int left, int right)
{
    if (left<right)
    {
        int pivot=partition(array, left ,right);
        quicksort(array,left,pivot-1);
        quicksort(array,pivot+1,right);
    }
}

int main()
{
    int array[8]={5,6,2,-2,6,10,12,15};
    quicksort(array,0,7);
    for (int i=0;i<8;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}