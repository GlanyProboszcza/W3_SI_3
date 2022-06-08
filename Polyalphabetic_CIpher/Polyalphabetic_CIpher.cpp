#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::string mappedKey;
std::string message;

void messageAndKey()
{
    std::string msg;
    cout << "Enter message: ";
    getline(cin, msg);
    cin.ignore();

    // convert message to uppercase 
    for (int i = 0; i < msg.length(); i++)
    {
        msg[i] = toupper(msg[i]);
    }

    std::string key;
    cout << "Enter keyword: ";
    getline(cin, key);
    cin.ignore();

    // convert keyword to uppercase 
    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }

    // mapping keyword to message
    std::string keyMap = "";
    for (int i = 0, j = 0; i < msg.length(); i++)
    {
        if (msg[i] == 32)
        {
            keyMap += 32;
        }
        else
        {
            if(j<key.length())
            {
                keyMap += key[j];
                    j++;
            }
            else
            {
                j = 0;
                keyMap += key[j];
                j++;
            }
        }
    }
  //  cout << msg << "\n" << keyMap;
    message = msg;
    mappedKey = keyMap;

}

int tableArray[26][26];
void createVigenereTable()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++) {
            int temp;
            if ((i + 65) + j > 90)
            {
                temp = ((i + 65) + j) - 26;
                tableArray[i][j] = temp; // adding ASCII of alphabet letter in table index position
            }
            else {
                temp = ((i + 65) + j; // adding ASCII of alphabet letter in table index position
                tableArray[i][j] = temp;
            }
        }
    }

}

void cipherEncryption(std::string message, std::string mappedKey)
{
    createVigenereTable();
    std::string encryptedTxt = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == 32 && mappedKey[i] == 32)
        {
            encryptedTxt += " ";
        }
        else
        {
            int x = (int)message[i] - 65;
            int y = (int)mappedKey[i] - 65;
            encryptedTxt += (char)tableArray[x][y];
        }
    }
    cout << "Encrypted message: " << encryptedTxt << endl;
}

int intCount(int key, int msg)
{


}


void cipherDecryption(std::string message, std::string mappedKey)
{
    std::string decryptedTxt = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == 32 && mappedKey[i] == 32)
        {
            decryptedTxt += "";
        }
        else
        {
            int temp = intCount((int)mappedKey[i], (int)message[i]);
            decryptedTxt += (char)(65 + temp);
        }
    }
    cout << "Decrypted message: " << decryptedTxt << endl;
}

int main()
{
    int userChoice;
    cout << "Hello!\n";
    cout << "1. Encryption\n2. Decryption\n3. EXIT\n";
    cout << ">>  "; cin >> userChoice;
    cin.ignore(); // https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus

    if (userChoice == 1)
    {
        cout << "Encryption" << endl;
        messageAndKey();
        cipherEncryption(message, mappedKey);
    }
    else if (userChoice == 2)
    {
        cout << "Decryption" << endl;
        messageAndKey();
        cipherDecryption(message, mappedKey);
    }
    /*else if (userChoice == 3)
    {
        cout << "See you next time! Bye!" << endl;
            break;
    }
    */
    else 
    {
        cout << "\n Wrong choice!\n" << endl;
    }
}