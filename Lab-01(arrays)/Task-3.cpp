#include<iostream>

using namespace std;

class Bank_Account
{
    double balance;

public:
    
    Bank_Account()
    {
        this->balance=200;
    }

    Bank_Account(double balance_in_account)
    {
        balance=balance_in_account;
    }
    Bank_Account(const Bank_Account& other)
    {
        balance=other.balance;
    }
    void deduct(double amount)
    {
        if (amount<=balance)
        {
            balance-=amount;
        }
        else
        {
            cout<<"Insufficient balance!"<<endl;
        }
    }
    int get_balance()
    {
        return balance;
    }
};
int main()
{
    Bank_Account account1;
    cout<<"Balance of account1: $"<<account1.get_balance()<<endl;

    Bank_Account account2(10000);
    cout<<"Balance of account2: $"<<account2.get_balance()<<endl;

    Bank_Account account3=account2;
    account3.deduct(2000);

    cout<<"Balance of account3 after deduction: $"<<account3.get_balance()<<endl;
    cout<<"Balance of account2 after transaction: $"<<account2.get_balance()<<endl;

    return 0;
}

