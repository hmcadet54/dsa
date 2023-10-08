#include<iostream>
using namespace std;


void encription(char mes[],char key[], int len)
{
    int *mesege=new int[len];
    int *keys=new int[len];
    for (int i=0;i<len;i++)
    {
        mesege[i]=mes[i];
        keys[i]=key[i];
    }
    // for (int i=0;i<len;i++)
    // {
    //     cout<<"Messege: "<<mesege[i]<<endl;
    //     cout<<"key: "<<keys[i]<<endl;
    // }
    char *encrypted=new char[len];
    for (int i=0;i<len;i++)
    {
        encrypted[i]=(mes[i] + key[i] -2 * 'A')%26 + 'a';
    }
    for (int i=0;i<len;i++)
    {
        cout<<encrypted[i]<<" ";
    }

}

int main()
{
    int len;
    cout<<"enter len of mes: ";
    cin>>len;

    char *mes=new char[len];
    char *key=new char[len];

    cout<<"Enter Message ";
    for (int i=0;i<len;i++)
    {
        cin>>mes[i];
    }
    cout<<endl;
    cout<<"Enter key ";
    for (int i=0;i<len;i++)
    {
        cin>>key[i];
    }

    encription(mes,key,len);

}




