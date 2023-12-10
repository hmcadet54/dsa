#include <iostream>
using namespace std;

class Task
{
public:
    int id;
    int Exctime;
    int cpu;
    int mmr;
    int storage;
    int data;
    Task *next;
    Task(int id, int Exctime, int cpu, int mmr, int storage)
    {
        this->id = id;
        this->Exctime = Exctime;
        this->cpu = cpu;
        this->mmr = mmr;
        this->storage = storage;
        next = NULL;
    }
};

class VM
{
public:
    int cpu;
    int mmr;
    int storage;
    VM *next;
    VM(int cpu, int mmr, int storage)
    {
        this->cpu = cpu;
        this->mmr = mmr;
        this->storage = storage;
        next = NULL;
    }
};

class queue
{
public:
    Task *front;
    Task *back;

    queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int id, int Exctime, int cpu, int mmr, int storage)
    {
        Task *n = new Task(id, Exctime, cpu, mmr, storage);
        if (front == NULL)
        {
            back = front = n;
            return;
        }

        back->next = n;
        back = n;
    }

    Task *dequeue()
    {
        if (!front)
        {
            return nullptr;
        }
        Task *temp = front;
        front = front->next;
        if (!front)
        {
            back = nullptr;
        }
        return temp;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue is underflow" << endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        Task *temp = front;
        while (temp != NULL)
        {
            cout << temp->id << " " << temp->Exctime << " " << temp->cpu << " " << temp->mmr << " " << temp->storage << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    queue q;
    q.enqueue(1, 20, 30, 512, 2);
    q.enqueue(2, 15, 20, 256, 1);
    q.enqueue(3, 25, 40, 768, 3);
    q.enqueue(4, 18, 25, 384, 2);
    q.display();
    
    VM *v = new VM(60, 1024, 5);
    VM *v1 = new VM(60, 1024, 5);
    VM *v2 = new VM(60, 1024, 5);
    v->next = v1;   
    v1->next = v2;
    v2->next = NULL;


       while (!q.empty()) {
        Task* currentTask = q.front;
        Task* bestTask = currentTask;
        while (currentTask) {
            if (currentTask->Exctime < bestTask->Exctime) {
                bestTask = currentTask;
            }
            currentTask = currentTask->next;
        }

        VM* bestVM = v;
        VM* currentVM = v;
        while (currentVM) {
            if (currentVM->cpu >= bestTask->cpu &&
                currentVM->mmr >= bestTask->mmr &&
                currentVM->storage >= bestTask->storage &&
                currentVM->cpu > bestVM->cpu) {
                bestVM = currentVM;
            }
            currentVM = currentVM->next;
        }

        cout << "task: " << bestTask->id << ": is executed on VM with cpu value of = " << bestVM->cpu <<endl;
        bestVM->cpu -= bestTask->cpu;
        bestVM->mmr -= bestTask->mmr;
        bestVM->storage -= bestTask->storage;

        if (bestTask == q.front) {
            q.dequeue();
        } else {
            currentTask = q.front;
            while (currentTask->next != bestTask) {
                currentTask = currentTask->next;
            }
            currentTask->next = bestTask->next;
        }
    }
}
