#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl;

void showAnswer(double answer);

int main(){
    cout << "---------------------------------" << endl;
    cout << "---                           ---" << endl;
    cout << "--         CALCULATOR         -- " << endl;
    cout << "---                           ---" << endl;
    cout << "---------------------------------" << endl;
    cout << "|    +    |     -    |    *     |" << endl;
    cout << "|   Add   | Subtract | Multiply |" << endl;
    cout << "---------------------------------" << endl;
    cout << "|    /    |     s    |     c    |" << endl;
    cout << "|  Divide |    sin   |    cos   |" << endl;
    cout << "---------------------------------" << endl;
    cout << "|    t    |    d     |     r    |" << endl;
    cout << "|   tan   | o -> rad | rad -> o |" << endl;
    cout << "|    c    |" << endl;
    cout << "|  clear  |" << endl;

    bool valid = 0;
    double num1;
    double num2;
    double answer;
    const double PI = 3.141592653589793;
    char input;

    while(!valid){
        cout << "Enter operator: ";
        cin >> input;
        input = tolower(input);

    switch(input){
        case '+':
            cout << "Enter 1st number: ";
            cin >> num1;
            cout << "Enter 2nd number: ";
            cin >> num2;
            answer = num1 + num2;
            valid = 1;
            break;
        case '-':
            cout << "Enter 1st number: ";
            cin >> num1;
            cout << "Enter 2nd number: ";
            cin >> num2;
            answer = num1 - num2;
            valid = 1;
            break;
        case '*':
            cout << "Enter 1st number: ";
            cin >> num1;
            cout << "Enter 2nd number: ";
            cin >> num2;
            answer = num1 * num2;
            valid = 1;
            break;
        case '/':
            cout << "Enter 1st number: ";
            cin >> num1;
            cout << "Enter 2nd number: ";
            cin >> num2;
            answer = num1 / num2;
            valid = 1;
            break;
        case 's':
            cout << "Enter a number: ";
            cin >> num1;
            answer = sin(num1);
            valid = 1;
            break;
        case 'c':
            cout << "Enter a number: ";
            cin >> num1;
            answer = cos(num1);
            valid = 1;
            break;
        case 't':
            cout << "Enter a number: ";
            cin >> num1;
            answer = tan(num1);
            valid = 1;
            break;
        case 'd':
            cout << "Enter degrees: ";
            cin >> num1;
            answer = num1 * (PI / 180);
            valid = 1;
            break;
        case 'r':
            cout << "Enter radians: ";
            cin >> num1;
            answer = num1 * (180 / PI);
            valid = 1;
            break;
        default:
            cout << "You've entered invalid value" << endl;
        }
    }

    showAnswer(answer);
    
    return 0;
}

void showAnswer(double answer){
    cout << "-------------------------------" << endl;
    cout << "|   Result: " << answer << endl;
    cout << "-------------------------------" << endl;
}