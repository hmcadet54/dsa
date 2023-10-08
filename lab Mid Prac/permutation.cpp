#include<iostream>
using namespace std;


void permutation(string&a, int start, int end)
{
    if(start==end)
    {
        cout<<a<<endl;
    }
    else{
        for (int i=start;i<=end;i++)
        {
            swap(a[start],a[i]);
            permutation(a,start+1,end);
            swap(a[start],a[i]);
        }
    }
}

int main()
{
    string a="ABCA";
    int n=a.size();
    permutation(a,0,n-1);
    return 0;
}