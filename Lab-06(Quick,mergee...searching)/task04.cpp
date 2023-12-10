#include<iostream>
using namespace std;

int binary(int array[], int size, int key)
{
    int start=0;
    int end=size;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(array[mid]==key)
        {
            return mid+1;
        }
        else if(array[mid]<key){
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        return -1;
    }
}

int main()
{
    int array[10]={78,34,67,21,4,89,98,33,12,9};
    int key=89; //22k-4489
    cout<<"The given key is present at: "<<binary(array, 10, 89);
}