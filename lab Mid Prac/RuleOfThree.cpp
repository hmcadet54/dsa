#include <iostream>
using namespace std;

class books
{
    string title;

public:
    books(){};
    books(string title)
    {
        setTitle(title);
    }
    string getTitle()
    {
        return title;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
};
void shellSort(books b[], int n)
{
    int gap = n;
    string temp;

    while (gap != 1)
    {
        gap = gap / 2;
        if (gap < 1)
        {
            gap = 1;
        }
        for (int i=0;i<n-gap;i++)
        {
            if (b[i].getTitle()>b[i+gap].getTitle())
             {
                 temp=b[i].getTitle();
                 b[i].setTitle(b[i+gap].getTitle());
                 b[i+gap].setTitle(temp);
            
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<b[i].getTitle();
    }
}

int main()
{
    int n;
    cout<<"n :";
    cin >> n;
    books *b = new books[n];
    string title;
    for (int i = 0; i < n; i++)
    {
        cin >> title;
        b[i].setTitle(title);
    }
    cout<<"Before Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<b[i].getTitle();
    }
    shellSort(b, n);

}