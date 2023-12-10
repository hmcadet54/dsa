#include <iostream>

using namespace std;

int main()
{
    int row=5;
    int **jaggedArray= new int* [row];
    int sizes[]={10,10,10,10,10};

    for (int i=0; i<row; i++)
    {
        jaggedArray[i]=new int[sizes[i]];
    }
    
    for (int i=0; i<row; i++)
    {
        cout<<"Enter line"<<i+1<<"elements:"<<endl;
        for (int j=0; j<sizes[i]; j++)
        {
            cout<<"line["<<i+1<<"] ["<<j+1<<"] : ";
            cin>>jaggedArray[i][j];
        }
    }

    for (int i=0; i<row; i++)
    {
        cout<<"Row "<<i+1<<" elements: ";
        for (int j=0; j<sizes[i]; j++)
        {
            cout<<jaggedArray[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i=0; i<row; i++)
    {
        delete[] jaggedArray[i];
    }

}
