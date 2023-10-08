#include <iostream>
using namespace std;
void Funct(int lastvalue, int n, int sum)
{
    if (lastvalue == 10)
    {
        return;
    }
    else
    {
        sum = sum + lastvalue + 1;
        lastvalue++;
        cout << sum << " ";
        Funct(lastvalue, n, sum);
    }
}

int main()
{
    // Funct(serves as "i", number of terms, sum in which value stores )
    Funct(0, 10, 0);
}