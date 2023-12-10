#include <iostream>
#include <list>
#include <unordered_set>


using namespace std;

class hash_table
{
    int capacity;
    list<int> *table;

public:
    hash_table(int size);
    void insert(int key);
    void remove(int key);
    int for_prime(int n);
    int getPrime(int n);

    int hashFunction(int key)
    {
        return (key % capacity);
    }
    void display();
    bool search(int key);
    bool trpl_check(int arr[], int n);
};
hash_table::hash_table(int size)
{
    int primeSize = getPrime(size);
    this->capacity = primeSize;
    table = new list<int>[capacity];
}

void hash_table::insert(int key)
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

bool hash_table::search(int key)
{
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
        {
            // Element found
            return true;
        }
    }
    // Element not found
    return false;
}

bool hash_table::trpl_check(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        unordered_set<int> s;

        for (int j = i + 1; j < n; ++j)
        {
            int target = -(arr[i] + arr[j]);

            if (s.find(target) != s.end())
            {
                return true; 
            }
            s.insert(arr[j]);
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    hash_table h(2 * n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        h.insert(arr[i]);
    }

    cout << "Result: " << h.trpl_check(arr, n) << endl;

    return 0;
}
