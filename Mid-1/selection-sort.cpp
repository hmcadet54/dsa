#include<iostream>
using namespace std;
int main()
{
    int array[5]={56,89,71,2,1};
    int min=0;
    for (int i=0;i<5;i++)
    {
        min=i;
        for (int j=i+1;j<5;j++)
        {
            if(array[j]<array[min])
            {
                min=j;
            }
            if(min!=i)
            {
                swap(array[min],array[i]);
            }
        }
    }
    for (int k=0; k<5; k++)
    {
        cout<<array[k]<<" ";
    }

}