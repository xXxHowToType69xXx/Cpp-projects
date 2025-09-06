#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <cstdlib>

using std::cout, std::cin, std::endl, std::string;

void encrypt();
void decrypt(string &cipherText);
void run();

int main(){
    run();

    return 0;
}

const string SYMBOLS = "!@#$%^&*()<>?/|{}[]:;";
std::map<char, char> encryptMap;
std::map<char, char> decryptMap;

void encrypt(){
    cout << "=======================" << endl;
    cout << "^      Encryption     ^" << endl;
    cout << "=======================" << endl;
    cout << "Enter your message: ";
    cin.ignore();
    string text;
    getline(cin, text);

    srand(time(0));

    string cipherText = "";
    std::map<char, char> originalText;

    for(int i = 0; i < text.size(); i++)
    {
        char chrt = text[i];

        if(originalText.find(chrt) == originalText.end())
        {
            char replacement;
        
            if(isalpha(chrt))
            {
                bool upper = rand() % 2;
                replacement = upper ? 'A' + rand() % 26 : 'a' + rand() % 26;
            }
            else if(isdigit(chrt))
            {
                replacement = '0' + rand() % 10;
            }
            else
            {
                replacement = SYMBOLS[rand() % SYMBOLS.size()];
            }
            encryptMap[chrt] = replacement;
            decryptMap[replacement] = chrt;
        }
        cipherText += encryptMap[chrt];
    }
    cout << "---------------------------------" << endl;
    cout << "Orignal message: " << text << endl;
    cout << "Encrypted message: " << cipherText << endl;
    cout << endl;
}

void decrypt(string &cipherText){
    cout << "=======================" << endl;
    cout << "^      Decryption     ^" << endl;
    cout << "=======================" << endl;
    cout << "Enter a message to decrypt: ";
    cin.ignore();
    getline(cin, cipherText);

    string plainText;

    for(char c : cipherText)
    {
        if(decryptMap.find(c) != decryptMap.end())
        {
            plainText += decryptMap[c];
        }
        else
        {
            plainText += c;
        }
    }
    cout << "---------------------------------" << endl;
    cout << "Encrypted message: " << cipherText << endl;
    cout << "Original message: " << plainText;
    cout << endl;
}

void run(){
    while(true)
    {
        cout << "=======================" << endl;
        cout << "  Encrypt and Decrypt  " << endl;
        cout << "=======================" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        string cipherText;
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << endl;
                encrypt();
                break;
            case 2:
                cout << endl;
                decrypt(cipherText);
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << endl;
    }
}