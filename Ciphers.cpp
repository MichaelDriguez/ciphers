#include <iostream>
#include <string>
using namespace std;

void caesar();
void vigenere();

int main()
{
    system("cls");
    int input;

    cout << "O-----------O" << endl;
    cout << "|  Ciphers  |" << endl;
    cout << "O-----------O" << endl << endl;

    cout << "--Type 100 to end program--" << endl << endl;

    cout << "Which cipher would you like to use? " << endl;
    cout << "Please enter the corresponding number." << endl << endl;

    cout << "1. Caesar Cipher" << endl;
    cout << "2. Vigenere Cipher" << endl;

    do
    {
        
        cout << "\nInput: ";
        cin >> input;
        cin.ignore();

        switch (input)
        {
            case 1:
                caesar();
                break;

            case 2:
                vigenere();
                break;
            
            case 100:
                exit(EXIT_SUCCESS);
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }
    } while (input != 100);
    
    return 0;
}

void caesar()
{
    string words, word1;
    int shift;
    char question;

    system("cls");

    while (true)
    {
        cout << "Encryption or Decryption? (E/D): ";
        cin >> question;
        cin.ignore();

        switch (question)
        {
            case 'E':
            case 'e':
                word1 = "encrypt";
                break;
            
            case 'D':
            case 'd':
                word1 = "decrypt";
                break;

            default:
                cout << "Invalid option." << endl;
                continue;
        }

        break;
    }

    system("cls");

    cout << "O-----------------------------O" << endl;
    cout << "|        Caesar Cipher        |" << endl;
    cout << "O-----------------------------O" << endl << endl;

    cout << "--Type $EXIT to return to menu--" << endl << endl;

    cout << "Please enter a word or sentence to " << word1 << ": ";
    getline(cin, words);

    if (words == "$EXIT")
    {
        main();
    }
    
    cout << "Please enter a shift (-25 to 25): ";
    cin >> shift;
    cin.ignore();

    int length = words.length();
    char *arr = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        arr[i] = words[i];
    }

    cout << "Your " << word1 << "ed message is: ";

    for (int i = 0; i < length; i++)
    {
        if (isalpha(arr[i]))
        {
            int cipher = toupper(static_cast<int>(arr[i])) + shift;
        
            if (cipher > 90)
            {
                cipher = 65 + (cipher - 91);
                cout << static_cast<char>(cipher);
            }

            else if (cipher < 65)
            {
                cipher = 90 + (cipher - 64);
                cout << static_cast<char>(cipher);
            }

            else cout << static_cast<char>(cipher);
        }

        else cout << arr[i];
    }

    char choice;
    cout << "\nWant to do another message? (Y/N) ";
    cin >> choice;
    cin.ignore();

    if (choice == 'Y' || choice == 'y')
    {
        delete [] arr;
        caesar();
    }

    else if (choice == 'N' || choice == 'n')
    {
        delete [] arr;
        main();
    }

    else
    {
        delete [] arr;
        main();
    }

}

void vigenere()
{
    string words, word1, key;
    char question;
    int size = 0;

    system("cls");

    while (true)
    {
        cout << "Encryption or Decryption? (E/D): ";
        cin >> question;
        cin.ignore();

        switch (question)
        {
            case 'E':
            case 'e':
                word1 = "encrypt";
                break;
            
            case 'D':
            case 'd':
                word1 = "decrypt";
                break;

            default:
                cout << "Invalid option." << endl;
                continue;
        }

        break;
    }

    system("cls");

    cout << "O-----------------------------O" << endl;
    cout << "|       Vigenere Cipher       |" << endl;
    cout << "O-----------------------------O" << endl << endl;

    cout << "--Type $EXIT to return to menu--" << endl << endl;

    cout << "Please enter a word to use as your key: ";
    cin >> key;
    cin.ignore();

    cout << "Please enter a word or sentence to " << word1 << ": ";
    getline(cin, words);

    if (words == "$EXIT")
    {
        main();
    }

    int length = words.length(), *keyInt = new int [key.length() + 1];
    char *arr = new char[length + 1], *keyArr = new char [key.length() + 1];

    for (int i = 0; i < length; i++)
    {
        arr[i] = words[i];
    }

    for (int i = 0; i < key.length(); i++)
    {
        if (isalpha(key[i]))
        {
            keyArr[i] = toupper(key[i]);
            size++;
        }
    }

    for (int i = 0; i < key.length(); i++)
    {
        keyInt[i] = keyArr[i] - 65;
    }

    cout << "Your " << word1 << "ed message is: ";

    int index = 0;
    char shift;

    for (int i = 0; i < length; i++)
    {
        if (index >= size)
        {
            index = 0;
        }

        if (isalpha(arr[i]))
        {
            int cipher = toupper(static_cast<int>(arr[i])) + keyInt[index];

            //cout << "\nKEY: " << keyInt[index] << endl;
        
            if (cipher > 90)
            {
                cipher = 65 + (cipher - 91);
                cout << static_cast<char>(cipher);
            }

            else if (cipher < 65)
            {
                cipher = 90 + (cipher - 64);
                cout << static_cast<char>(cipher);
            }

            else cout << static_cast<char>(cipher);

            index++;
        }

        else cout << arr[i];
    }

    char choice;
    cout << "\nWant to do another message? (Y/N) ";
    cin >> choice;
    cin.ignore();

    if (choice == 'Y' || choice == 'y')
    {
        delete [] arr;
        vigenere();
    }

    else if (choice == 'N' || choice == 'n')
    {
        delete [] arr;
        main();
    }

    else
    {
        delete [] arr;
        main();
    }

}