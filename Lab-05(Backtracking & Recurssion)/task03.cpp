#include <iostream>
using namespace std;


void funct(int i, int j, int arr[])
{
    if(j>6)
    { 
        return;
    }
    else 
    {
        if(arr[i]>arr[j])
        {
            swap(arr[i],arr[j]);
        }
        j++;
        funct(i,j,arr);
        i++;
    }
    funct(i,j,arr);
}
int main()
{
    int temp=0;
    int arr[6]= {12,11, 13, 5, 6, 7};
    int i=0;
    int j=i+1;
    funct(i,j,arr);

    for (int i=0; i<=6;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}