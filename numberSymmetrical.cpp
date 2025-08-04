#include <iostream>
#include <chrono> // for std::chrono::milliseconds
#include <thread> // for std::this_thread::sleep_for

using std::cout, std::cin, std::endl;

int main(){
    cout << "Enter a number: ";

    int number, tmp;
    int remainder = 0, reverse = 0;
    cin >> number; // 121
    tmp = number;
    // 1st loop | 2nd loop | 3rd loop,...
    while(tmp != 0){
        remainder = tmp % 10; // 1 | 2 | 1
        reverse = reverse * 10 + remainder; // 1 | 12 | 121
        tmp = tmp / 10; // 12 | 1 | 0 -> loop ends
    }
 
    cout << "Analyzing..." << endl;
    for(int i = 1; i <= 10; i++){
        cout << i << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    cout << endl;

    // 121    == 121
    if(number == reverse){
        cout << "The number " << number << " is symmetrical";
    }
    else{
        cout << "The number " << number << " is not symmetrical";
    }

    return 0;
}