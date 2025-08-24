#include <iostream>
#include <ctime>

using std::cout, std::cin, std::endl;

int main(){
    cout << "<<< Number Guessing Game >>>" << endl;
 
    int number;
    int guess;
    int attempt = 0;
    srand(time(0));
    number = (rand() % 100) + 1;

    do{
        cout << "Pick a number from 0 - 100: ";
        cin >> guess;
        attempt++;

        if(guess > number)
        {
            cout << "Too high" << endl;
        }
        else if(guess < number)
        {
            cout << "Too low" << endl;
        }
        else
        {
            cout << "!!! Ding ding dign correct !!!" << endl;
            cout << "Total attempt(s): " << attempt;
        }

    } while(guess != number);

    return 0;
}