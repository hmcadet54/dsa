#include <iostream>
using namespace std;

int FabunacciInner(int n, int next, int t1, int t2)
{
    if (n<=1)
    {
        return 0;
    }
    else
    {
        cout<<t1<<" ";
        next=t1+t2;
        t1=t2;
        t2=next;
        n--;
        FabunacciInner(n, next, t1, t2);
    }
}
int FuncNestedOuter(int n)
{
    if (n<=1)
    {
        return 0;
    }
    else
    {
        FuncNestedOuter(FabunacciInner(n+1, 0,0,1));
        n=n-(n-1);
    }
}

int main()
{
    FuncNestedOuter(10);
}