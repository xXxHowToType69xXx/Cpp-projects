#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout, std::cin, std::endl, std::string, std::fixed, std::setprecision;

struct unit{
    string name;
    string abbreviation;
};

int main(){
    unit metricLength[] = {{"kilometer",  "km"},
                           {"hectomer",   "hm"},
                           {"decamter",   "dam"},
                           {"meter",      "m"},
                           {"decimeter",  "dm"},
                           {"centimeter", "cm"},
                           {"milimeter",  "mm"}};
    
    unit metricMass[] = {{"ton",       "t"},
                         {"kilogram",  "kg"},
                         {"hectogram", "hg"},
                         {"decagram",  "dag"},
                         {"gram",      "g"},
                         {"miligram",  "mg"}};

    unit data[] = {{"byte",     "b", },
                   {"kilobyte", "kb",},
                   {"megabyte", "mb",},
                   {"gigabyte", "gb",},
                   {"terabyte", "tb",},
                   {"petabyte", "pb",}
};

    cout << "----------------------------" << endl;
    cout << "|      Unit Conversion     |" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Length |" << " 2. Mass |" << " 3. Speed" << endl;
    cout << "4. Time   |" << " 5. Data |" << " 6. Temperature" << endl;
    
    bool valid = false;
    cout << "Choose the conversion you want: ";
    int choice;
    cin >> choice;

    string fromUnit, toUnit;
    int from = -1, to = -1;
    double value;
    double result;

    while(!valid){
        switch(choice){
            case 1:
                cout << "Available length units (use abbreviation): " << endl;
                for(int i = 0; i < 7; i++)
                {
                    cout << i + 1 << ". "<< metricLength[i].name << " (" << metricLength[i].abbreviation << ")" << endl;
                }    

                cout << "You want to convert ";
                cin >> fromUnit;
                cout << "You want to convert to ";
                cin >> toUnit;
                
                for(int i = 0; i < 7; i++)
                {
                    if(metricLength[i].abbreviation == fromUnit)
                    {
                        from = i;
                    };
                    if(metricLength[i].abbreviation == toUnit)
                    {
                        to = i;
                    };
                }

                if(from == -1 || to == -1)
                {
                    cout << "--- Invalid choice ---" << endl;
                    cout << endl;
                    break;
                }

                cout << "Enter a value " << "(" << metricLength[from].abbreviation << "): ";
                cin >> value;

                if(from < to)
                {
                    result = value * pow(10, to - from);
                }
                else if(from > to)
                {
                    result = value / pow(10, from - to);
                }
                else
                {
                    result = value;
                }

                cout << "-------------------" << endl;
                cout << fixed << setprecision(0);
                cout << value << " " << metricLength[from].name << " = "  << result << " "<< metricLength[to].name;
                
                valid = true;
                break;
            
            case 2:
                cout << "Available mass units (use abbreviation): " << endl;
                for(int i = 0; i < 7; i++)
                {
                    cout << i + 1 << ". " << " " << metricMass[i].name << " (" << metricMass[i].abbreviation << ")" << endl;
                }

                cout << "You want to convert ";
                cin >> fromUnit;
                cout << "You want to convert to ";
                cin >> toUnit;

                for(int i = 0; i < 7; i++)
                {
                    if(fromUnit == metricMass[i].abbreviation)
                    {
                        from = i;
                    }

                    if(toUnit == metricMass[i].abbreviation)
                    {
                        to = i;
                    }
                }

                if(from == -1 || to == -1)
                {
                    cout << "--- Invalid choice ---" << endl;
                    cout << endl;
                    break;
                }

                cout << "Enter a value (" << metricMass[from].name << "): ";
                cin >> value;

                if(from > to)
                {
                    result = value / pow(10, from - to);
                }
                else if(from < to)
                {
                    result = value * pow(10, to - from);
                }
                else
                {
                    result = value;
                }

                cout << "-------------------" << endl;
                cout << fixed << setprecision(0);
                cout << value << " " << metricMass[from].name << " = "  << result << " "<< metricMass[to].name << endl;

                valid = true;
                break;
            
            case 3:
                cout << "1. From km/s to m/s" << endl;
                cout << "2. From m/s to km/s" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if(choice == 1)
                {
                    cout << "Enter the speed in km/s: ";
                    cin >> value;

                    result = value * 1000;
                    cout << "----------------------------" << endl;
                    cout << "Resuit: " << value << " km/s" << " = " << result << " m/s";
                }
                else if(choice == 2)
                {
                    cout << "Enter the speed in m/s: ";
                    cin >> value;

                    result = value / 1000;
                    cout << "----------------------------" << endl;
                    cout << "Resuit: " << value << " m/s" << " = " << result << " km/s";
                }
                else
                {
                    cout << "Invalid choice";
                    cout << endl;
                }

                valid = true;
                break;

            case 4:
                cout << "___ hour(s) ___ minute(s) ___ seconds(s)" << endl;
                cout << "    1               2             3" << endl;
                cout << "Your choice: ";
                cin >> choice;

                if(choice == 1)
                {
                    cout << "Your desired hour(s): ";
                    cin >> value;

                    cout << value << " hour(s) = ";
                    cout << value * 60 << " minute(s) " << value * 3600 << " seconds(s)";
                    break;
                }
                else if(choice == 2)
                {
                    cout << "Your desired minute(s): ";
                    cin >> value;

                    cout << value << " minute(s) = ";
                    cout << value / 60 << " hour(s) " << value * 60 << " seconds(s)";
                    break;
                }
                else if(choice == 3)
                {
                    cout << "Your desired second(s): ";
                    cin >> value;

                    cout << value << " second(s) = ";
                    cout << value / 3600 << " hour(s) " << value / 60 << " minute(s)";
                    break;
                }
                else
                {
                    cout << "Non existence";
                    cout << endl;
                    break;
                }

                value = true;
                break;

            case 5:
                cout << "Available data unit (use abbreviation): " << endl;
                for(int i = 0; i < 6; i++)
                {
                    cout << i + 1 << ". " << data[i].name << " (" << data[i].abbreviation << ")" << endl;
                }

                cout << "You want to convert ";
                cin >> fromUnit;
                cout << "You want to convert to ";
                cin >> toUnit;
                
                for(int i = 0; i < 6; i++)
                {
                    if(fromUnit == data[i].abbreviation)
                    {
                        from = i;
                    }
                    if(toUnit == data[i].abbreviation)
                    {
                        to = i;
                    }
                }

                if(from == -1 || to == -1)
                {
                    cout << "--- Invalid choice ---" << endl;
                    cout << endl;
                    break;
                }

                cout << "Enter a value (" << data[from].name << "): ";
                cin >> value;
                
                if(from > to)
                {
                    result = value * pow(1024, from - to);
                }
                else if(from < to)
                {
                    result = value / pow(1024, to - from);
                }
                else
                {
                    result = value;
                }

                cout << "----------------------------" << endl;
                cout << fixed << setprecision(0);
                cout << value << " " << data[from].name << " = " << result << " " << data[to].name;

                valid = true;
                break;

            case 6: // yandere dev simulator 9000
                cout << "Available temperature conversions: " << endl;
                cout << "1. Celsius to Fahrenheit" << endl;
                cout << "2. Fahrenheit to Celsius" << endl;
                cout << "3. Kelvin to Celsius    | 4. Celsius to Kelvin" << endl;
                cout << "5. Kelvin to Fahrenheit | 6. Fahrenheit to Kelvin" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if(choice == 1)
                {
                    cout << "Enter the temperature in Celsius: ";
                    cin >> value;
                    cout << "-------------------------------------" << endl;
                    cout << "Result: " << value << " Celsius = " << (value * 1.8) + 32 << " Fahrenheit" << endl;
                }
                else if(choice == 2)
                {
                    cout << "Enter the temperature in Fahrenheit: ";
                    cin >> value;
                    cout << "-------------------------------------" << endl;
                    cout << "Result: " << value << " Fahrenheit = " << (value - 32) / 1.8 << " Celsius" << endl;
                }
                else if(choice == 3)
                {
                    cout << "Enter the temperature in Kelvin: ";
                    cin >> value;
                    cout << "-------------------------------------" << endl;
                    cout << "Result: " << value <<  "Kelvin = " << value - 273.15 << " Celsius" << endl;
                }
                else if(choice == 4)
                {
                    cout << "Enter the temperature in Celsius: ";
                    cin >> value;
                    cout << "-------------------------------------" << endl;
                    cout << "Result: " << value << " Celsius = " << value + 273.15 << " Kelvin" << endl;
                }
                else if(choice == 5)
                {
                    cout << "Enter the temperature in Kelvin: ";
                    cin >> value;
                    cout << "-------------------------------------" << endl;
                    cout << "Result: " << value << " Kelvin = " << 1.8 * (value - 273.15) + 32 << " Fahrenheit" << endl;
                }
                else if(choice == 6)
                {
                    cout << "Enter the temperature in Fahrenheit: ";
                    cin >> value;
                    cout << "-------------------------------------" << endl;
                    cout << "Result: " << value << " Fahrenheit = " << ((value - 32) / 1.8) + 273.15  << " Kelvin" << endl;
                }
                else
                {
                    cout << "Invalid choice" << endl;
                    cout << endl;
                    break;
                }

                valid = true;
                break;
        }
    }

    return 0;
}