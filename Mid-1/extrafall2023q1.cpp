#include <iostream>

using namespace std;

void encryptionWithSafetyCheck(char arr[], char key[], int sizeofArr)
{
    char *encrypted = new char[sizeofArr];

    for (int i = 0; i < sizeofArr; i++)
    {
        char c = arr[i];
        if (c >= 'a' && c <= 'z')
        {
            c = c + 'A' - 'a';
        }
        else if (c < 'A' || c > 'Z')
        {
            continue;
        }
        char enc_char = (c + key[i] - 2 * 'A') % 26 + 'a';
        encrypted[i] = enc_char;
        cout << encrypted[i] << " ";
    }

    delete[] encrypted; // Free the allocated memory
}

int main()
{
    int size, i;
    char *arr;
    char *arr1;

    cout << "Enter the length of the message to be encrypted" << endl;
    cin >> size;

    arr = new char[size];
    arr1 = new char[size]; // Update to use 'size' for the key size

    cout << "Enter the message to be encrypted" << endl;
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter Key" << endl;
    for (i = 0; i < size; i++) // Use 'size' for the key size
    {
        cin >> arr1[i];
    }

    cout << "The message to be encrypted is" << endl;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "Key is" << endl;
    for (i = 0; i < size; i++) // Use 'size' for the key size
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Encrypted message is" << endl;
    encryptionWithSafetyCheck(arr, arr1, size); // Update the function call

    delete[] arr;  // Free the allocated memory
    delete[] arr1; // Free the allocated memory

    return 0;
}
