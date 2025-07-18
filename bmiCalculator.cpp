#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
    cout << "----------------------" << endl;
    cout << "--- BMI calculator ---" << endl;
    cout << "----------------------" << endl;

    cout << "Enter your weight (kg): ";
    double weight;
    cin >> weight;

    cout << "Enter your height (m): "; // use . not ,
    double height;
    cin >> height;

    double result = weight / (height * height);

    if(result < 18.5){
        cout << "Conclusion: You are underweight";
    }
    else if(result >= 18.5 && result <= 24.9){
        cout << "Conclusion: You are healthy";
    }
    else if(result >= 25.0 && result <= 29.9){
        cout << "Conclusion: You are overweight";
    }
    else if(result >= 30.0 && result <= 39.9){
        cout << "Conclusion: You are obese";
    }
    else if(result >= 40){
        cout << "Conclusion: You are heavily obese";
    }

    return 0;
}

