#include<iostream>
using namespace std;

#define n 100


class queue
{
    int *array;
    int front;
    int back;

    public:
    queue()
    {
        array=new int[n];
        front=-1;
        back=-1;
    }

    void enqueue(int x)
    {
        if(back==n-1)
        {
            cout<<"Queue is oveflow";
            return;
        }
        if(front==-1){
            front++;
        }
        back++;
        array[back]=x;
    }

    int dequeue()
    {
        if(front==-1|| front>back)
        {
            cout<<"NO elemnt in queue";
            return-1;
        }
        int x = array[front];
        front++;
        return x;
    }

    int peek()
    {
        if(front==-1|| front>back)
        {
            cout<<"NO elemnt in queue";
            return-1;
        }
        return array[front];

    }
    bool empty()
    {
        if(front==-1|| front>back)
        {
            return true;
        }
        return false;
    }
    void display()
    {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i=front;i<=back;i++)
        {
            cout<<array[i]<<" ";
        }
    }

};

int main()
{
    queue q;
    int array1[7]={13,7,4,1,6,8,10};
    for (int i=0;i<7;i++)
    {
        q.enqueue(array1[i]);
    }
    int checkout[7]={0};

    cout<<"Checkouts made on the basis of first in first out!"<<endl;
    for (int i=0;i<7;i++)
    {
        checkout[i]=q.dequeue();
        cout<<checkout[i]<<" ";

    }
    
}
