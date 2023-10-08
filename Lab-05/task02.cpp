#include <iostream>
using namespace std;
void Funct(int lastvalue,int n, int sum);
int MainFunction(int n)
{
    if(n<1)
    {
        return 0;
    }
    else 
    {
        Funct(0,10,0);
        n--;
    }
}
void Funct(int lastvalue,int n, int sum)
{
    if (lastvalue==10)
    {
        return;
    }
    else
    {
        sum=sum+lastvalue+1;
        lastvalue++;
        cout<<sum<<" ";
      //Funct(serves as "i", number of terms, sum in which value stores )
        Funct(lastvalue,n,sum);
        MainFunction(0);

    }
}

int main()
{
    MainFunction(1);
}