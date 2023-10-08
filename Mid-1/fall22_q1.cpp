// Suppose A, B, C are arrays of integers of size M, N, and M + N respectively. The numbers in array
// A appear in ascending order while the numbers in array B appear in descending order. Write a user
// defined function to produce third array C by merging arrays A and B in ascending order. Use A, B
// and C as arguments in the function.
#include <iostream>
using namespace std;
#define N 4
#define M 4

void sort(int arrayA[], int arrayB[], int arrayC[])
{
    int i = 0, j = 0, k = 0;
    int temp = 0;

    for (i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            if (arrayB[i] > arrayB[j])
            {
                swap(arrayB[i], arrayB[j]);
            }
        }
    }
    // for (i=0;i<N;i++)
    // {
    //     cout<<arrayB[i]<<" ";
    // }
    for (i = 0; i < N; i++)
    {
        if (i <= N)
        {
            arrayC[i] = arrayA[i];
        }
    }
    for (i = 4, j = 0; i <N + N, j < N; i++, j++)
    {

        arrayC[i] = arrayB[j];
    }
    for (i = 0; i < N + N; i++)
    {
        cout << arrayC[i] << " ";
    }
}
int main()
{
    int arrayA[N] = {1, 2, 3, 4};
    int arrayB[N] = {8, 7, 6, 5};
    int arrayC[N + N];

    sort(arrayA, arrayB, arrayC);
}