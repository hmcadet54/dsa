#include<iostream>
using namespace std;

void countsort(int array[],int n)
{
    int k=array[0];
    for (int i=0;i<n;i++)//loop for getting max element
    {
        k=max(k,array[i]);
    }
    // cout<<k;
    int count[n]={0}; // initilizing count array to n(9)

    for (int i=0;i<n;i++) // array to get repeted elemnet's indexes
    {
        count[array[i]]++;
    }

    for (int i=1;i<=k;i++) // loop to sum the indexes to get the positions of elemnts
    {
        count[i]+=count[i-1];
    }
    int sortedarray[n];

    for (int i=n-1;i>=0;i--) // loop to store the sorted elemnts from last of (n)
    {
        sortedarray[--count[array[i]]]=array[i];
    }

    for (int j=0;j<n;j++)
    {
        // cout<<"I am running;";
        cout<<" "<<sortedarray[j];
    }

}

int main()
{
    int array[9]={1,3,2,3,4,6,5,6,7};

    countsort(array,9);

    // for (int i=0;i<9;i++)
    // {
    //     cout<<array[i];
    // }
}