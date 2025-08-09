#include<iostream>
#include <ctime>
#include <chrono>
#include <thread>
using std::cout, std::cin, std::endl, std::string;

void generatePassword(int alphabet);

int main(){
    int length;;
    cout << "----------------------------" << endl;
    cout << "     Password Generator       " << endl;
    cout << "----------------------------" << endl;

    do{
        cout << "Enter the length of your password (5-20): ";
        cin >> length;

        if(length < 5)
        {
            cout << "The chosen length for your password is too weak. Try again" << endl;
        }
        else if(length > 20)
        {
            cout << "The chosen length for your password is not in the program capability. Try again" << endl;
        }

    } while(length < 5 || length > 20);

    generatePassword(length);

    return 0;
}

void generatePassword(int length){
    const char alphabetNumbers[] = "0123456789"
                                   "~!@#$%^&*" 
                                   "abcdefghijklmnopqrstuvwxyz"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    srand(time(0));
    string password = "";
    int passwordLength = alphabetNumbers[length];

    for(int i = 0; i < length; i++)
    {
        int randomPassword = rand() % passwordLength; // generate a random index
        password = password + alphabetNumbers[randomPassword]; // pick a random character/number from that random index
    }

    cout << "Making a password..." << endl;
    for(int j = 1; j < 6; j++)
    {
        cout << j << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } cout << endl;

    cout << "Adding blessings..." << endl;
    for(int k = 1; k < 6; k++)
    {
        cout << k << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } cout << endl;

    cout << "Almost there..." << endl;
    for(int l = 1; l < 5; l++)
    {
        cout << l << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } cout << endl;

    cout << "Just kidding" << endl;
    for(int n = 1; n < 3; n++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    cout << "Alright im gonna be real this time" << endl;
    for(int m = 1; m < 3; m++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } cout << endl;

    cout << "Your randomly generated passowrd is: " << password;
}