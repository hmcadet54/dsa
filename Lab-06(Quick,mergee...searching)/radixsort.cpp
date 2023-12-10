#include<iostream>
using namespace std;

void countsort(int array[],int n, int division)
{
    int count[n]={0};

    for (int i=0;i<n;i++) 
    {
        count[(array[i]/division)%10]++;
    }

    for (int i=1;i<=n;i++)
    {
        count[i]+=count[i-1];
    }
    int sortedarray[n];

    for (int i=n-1;i>=0;i--) 
    {
        sortedarray[count[(array[i]/division)%10]-1]=array[i];
        count[(array[i]/division)%10]--;

    }
    cout<< "Asc Order: ";    
    for (int j=0;j<n;j++)
    {
        cout<<" "<<sortedarray[j];
    }
    cout<<endl;
    cout<<"Des Order: ";
    for (int j=n-1;j>=0;j--)
    {
        cout<<" "<<sortedarray[j];
    }

}
void radixsort(int array[], int size)
{
    int maximum=0;
    for (int i=0;i<size;i++)
    {
        maximum=max(maximum,array[i]);
    }
    for (int i=1; maximum/i>0; i*=10)
    {
        countsort(array,size,i);
    }
}

int main()
{
    int array[9]={1,3,2,3,4,6,5,6,7};

    radixsort(array,9);

    
}