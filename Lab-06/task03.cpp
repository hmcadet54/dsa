#include <iostream>
using namespace std;


void merge( int array[], int left, int mid, int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    int temp[8];
    while (i<=mid && j<=right)
    {
        if (array[i]<array[j])
        {
            temp[k]=array[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=array[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        temp[k]=array[i];
        i++;
        k++;
    }
    while (j<=right)
    {
        temp[k]=array[j];
        j++;
        k++;
    }
    for (int i=left;i<=right;i++)
    {
        array[i]=temp[i];
    }
}

void mergesort(int array[], int left, int right)
{
    if (left<right)
    {
        int mid=(left+right)/2;
        mergesort(array,left,mid);
        mergesort(array,mid+1,right);

        merge(array,left,mid,right);
    }
}

int main()
{
    int array[8]={3,1,6,8,4,5,7,2};
    mergesort(array,0,7);
    for (int i=0;i<8;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;

}