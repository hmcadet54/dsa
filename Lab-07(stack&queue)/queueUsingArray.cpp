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

    void dequeue()
    {
        if(front==-1|| front>back)
        {
            cout<<"NO elemnt in queue";
            return;
        }
        front++;
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
    }
    void display()
    {
        int m=back-front;
        for (int i=0;i<=m;i++)
        {
            cout<<array[i]<<" ";
        }
    }

};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    cout<<q.peek();
    q.dequeue();
    cout<<q.peek();
    q.display();
}
