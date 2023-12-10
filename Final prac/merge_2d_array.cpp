#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void merge(T array[][2], int left, int mid, int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    T temp[right-left+1][2];
    while (i<=mid && j<=right)
    {
        if (array[i][0]<array[j][0])
        {
            temp[k][0]=array[i][0];
            temp[k][1]=array[i][1];
            i++;
            k++;
        }
        else
        {
            temp[k][0]=array[j][0];
            temp[k][1]=array[j][1];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        temp[k][0]=array[i][0];
        temp[k][1]=array[i][1];
        i++;
        k++;
    }
    while (j<=right)
    {
        temp[k][0]=array[j][0];
        temp[k][1]=array[j][1];
        j++;
        k++;
    }
    for (int i=left;i<=right;i++)
    {
        array[i][0]=temp[i][0];
        array[i][1]=temp[i][1];
    }
}

template <typename T>
void mergesort(T array[][2], int left, int right)
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
    string array[3][2]={{"banana","20"},{"apple","10"},{"cherry","30"}};
    mergesort(array,0,2);
    for (int i=0;i<3;i++)
    {
        cout<<"("<<array[i][0]<<","<<array[i][1]<<")";
    }
    return 0;
}
