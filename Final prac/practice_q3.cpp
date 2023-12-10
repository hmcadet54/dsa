#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int array[4]={1,3,5,7};

    vector<int>n_array;
    n_array.push_back(array[0]);
    n_array.push_back(array[3]);
    int n=2;
    for (int i=1;i<3;i++)
    {
        n++;
        n_array.push_back(array[i]);
        n_array.push_back(array[n-1]);
        i++;
    }
    // cout<<n_array.size();
    for (int i=0;i<n_array.size();i++)
    {
        cout<<n_array[i]<<" "<<endl;
    }
}