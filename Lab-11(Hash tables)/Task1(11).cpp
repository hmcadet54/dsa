#include <iostream>
#include <list>
#include <string>

using namespace std;

class hash_table
{
    int capacity;
    list<int> *table;

public:
    hash_table(int size);
    void insert(int key, int data);
    void remove(int key);
    int for_prime(int n);
    int getPrime(int n);

    int hashFunction(int key)
    {
        return (key % capacity);
    }
    void display();
    void search(int key);
};
hash_table::hash_table(int size)
{
    int primeSize = getPrime(size);
    this->capacity = primeSize;
    table = new list<int>[capacity];
}

void hash_table::insert(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void hash_table::remove(int key)
{
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }
    if (i != table[index].end())
        table[index].erase(i);
}

int hash_table::for_prime(int n)
{
    int i;
    if (n == 1 || n == 0)
        return 0;
    for (i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int hash_table::getPrime(int n)
{
    if (n % 2 == 0)
        n++;
    while (!for_prime(n))
        n += 2;
    return n;
}

void hash_table::display()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]: ";
        if (table[i].empty())
        {
            cout << "Empty";
        }
        else
        {
            for (auto x : table[i])
                cout << x << " ";
        }
        cout << endl;
    }
}

void hash_table::search(int key)
{
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
        {
            cout << "Element found at index " << index << " and key " << key << endl;
            break;
        }
    }
    if (i == table[index].end())
        cout << "Element not found" << endl;
}

int main()
{
    int keys[] = {20, 34, 45, 70, 56, 76, 84};
    int n = sizeof(keys) / sizeof(keys[0]);
    hash_table h(7);
    for (int i = 0; i < n; i++)
    {
        h.insert(keys[i], i + 1);
    }

    h.display();
    cout << endl;
    cout << "After removing 84" << endl;
    h.remove(84);
    h.display();
    cout << endl;
    cout << "After adding 90" << endl;
    h.insert(90,4);
    h.display();

}
