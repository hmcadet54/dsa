#include <iostream>
using namespace std;


void func2(int i, int n);

void func1(int i,int n)
{
    if(i>7)  // change the value to print as much as you want;
    {
        return ;
    }
    else{
        cout<<n<<" ";
        func2(i,n);
    }
}
void func2(int i, int n)
{
    n=n+i+1;
        i++;
        func1(i,n);
}


int main()
{
    func1(1,1);
}