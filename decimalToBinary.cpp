#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
    cout << "~~~ Decimal to Binary Converter ~~~" << endl;
    cout << "Enter a decimal number: ";
    int decimal;
    cin >> decimal;

    int orignalDecimal = decimal;
    int remain;
    int binary = 0;
    int placeValue = 1;

    while(decimal != 0){
        remain = decimal % 2; // odd = 1, even = 0
        binary = binary + (remain * placeValue);
        decimal = decimal / 2;
        placeValue = placeValue * 10;
    }

    cout << "--------------------------" << endl;
    cout << "Binary number of " << orignalDecimal << ": " << binary;

    return 0;
}