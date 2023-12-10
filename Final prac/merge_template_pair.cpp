#include <iostream>
#include <algorithm>
using namespace std;

template<class T1,class T2>
void merge(pair<T1,T2> array[], int left, int mid, int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    pair<T1,T2> temp[3];
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
template<class T1,class T2>
void mergesort(pair<T1,T2> array[], int left, int right)
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

    pair<int,string>array[3]={make_pair(1,"abdullah"),make_pair(0,"haroon"),make_pair(6,"shafiq")};
    mergesort(array,0,2);
    for (int i=0;i<3;i++)
    {
        cout<<"("<<array[i].first<<","<<array[i].second<<")";
    }
    return 0;
}


