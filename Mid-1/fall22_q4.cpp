// Write a function that takes a NxN 2D array and its dimension N as parameters and sort the given
// array such that after sorting the values in the array are in column-wise ascending order.
// Example:
// Before sorting:
// 2 3 2 8
// 9 4 54 5
// 1 7 4 11
// 6 1 9 2


// // After sorting:
// 1 2 5 9
// 1 3 6 9
// 2 4 7 11
// 2 4 8 54

// ***********************************Good Luck ********************






#include<iostream>
using namespace std;
#define n 4

void sort123(int array [n][n])
{
    int temp[n*n];
    int i=0,k=0,j=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            temp[k]=array[i][j];
            k++;
        }
    }
    for (i=0;i<n*n;i++)
    {
        for (j=i;j<n*n;j++)
        {
            if(temp[i]>temp[j])
            {
                swap(temp[i],temp[j]);
            }
        }
    }
    k=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            array[j][i]=temp[k];
            k++;
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<array[i][j]<<" ";
        
        }
        cout<<endl;
    }
}









int main()
{
    int arr[n][n] = {{2, 3, 2, 8},
                     {9, 4, 54, 5},
                     {1, 7, 4, 11},
                     {6, 1, 9, 2}};

    sort123(arr);
    
}