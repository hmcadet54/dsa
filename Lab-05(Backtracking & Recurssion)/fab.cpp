#include<iostream>

using namespace std;

int main()
{
    int i=0,t1=0,t2=1,next=0;

    // cout<<t1<<" ";
    // cout<<t2<<" ";
    for(i=0;i<10;i++)
    {
        cout<<t1<<" ";
        next=t1+t2;
        t1=t2;
        t2=next;
        // cout<<next<<" ";
    }
}