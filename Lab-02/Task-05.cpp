#include<iostream>
using namespace std;

int main()
{
    //the best sorting algorithm to be used to impliment th current given situation is insertion sort, 
    //This makes it a good choice for situations where the cost of comparing elements 
    //is low relative to the cost of moving elements.


    // so taking random unsorted array of numbers

    int arr[]={5,2,4,6,1,3};
    int lenght=sizeof(arr)/sizeof(arr[0]);


    //taking i=1; bcz we have to start comapring from 2nd elemnt of an array
    for (int i=1; i<lenght; i++)
    {
        int current=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>current)
        {
            arr[j+1]=arr[j];
            j=j-1;//j--;
        }
        arr[j+1]=current;
    }

    //printing the sorted array
    for (int i=0; i<lenght; i++)
    {
        cout<<arr[i]<<" ";
    }
}