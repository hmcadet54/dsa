#include<iostream>
using namespace std;

int main()
{
    int date[5][3];
    int temp,temp1,temp2;


    //taking input from user as date(dd/mm/yyyy) as i asked from you!
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << i + 1 << " date: (dd/mm/yyyy)" << endl;
        for (int j = 0; j < 3; j++)
        {
            cin >> date[i][j];
        }
    }
    //sorting the dates using selection sort
    for (int i = 0; i < 5 - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 5; j++) {
            if (date[j][2] < date[minIndex][2]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = date[i][2];
            date[i][2] = date[minIndex][2];
            date[minIndex][2] = temp;

            temp1 = date[i][1];
            date[i][1] = date[minIndex][1];
            date[minIndex][1] = temp1;

            temp2 = date[i][0];
            date[i][0] = date[minIndex][0];
            date[minIndex][0] = temp2;
        }
    }
	
	//printing the sorted dates
	cout << "Sorted Dates: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << date[i][j] ;
			if(j!=2)
			{
				cout<<"/";
			}
        }
        cout << endl;
    }
}

