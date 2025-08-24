#include <iostream>

using std::cout, std::cin, std::endl, std::string;

int main(){
    cout << "1. 190mm Bruh" << endl;
    cout << "2. 166mm Peacemaker" << endl;
    cout << "3. TOS-1" << endl;
    cout << "4. AFG Mk1" << endl << endl;

    cout << "Choose gun: ";
    int choice;
    cin >> choice;

    switch(choice){
        case 1:
            cout << "--- 190mm Bruh ---" << endl;
            cout << "Map: Avance to Yew Kay" << endl;
            cout << "South B | J9 | 150m [botttom]" << endl;
            cout << "South C | J0 | 100m [middle]" << endl;
            cout << "North B | B9 | 50m  [top]" << endl;
            cout << "North C | B9 | 250m [middle]" << endl;
            break;

        case 2:
            cout << "--- 166mm Peacemaker ---" << endl;
            cout << "Map: Avance to Yew Kay" << endl;
            cout << "South B | J9 | 50m  [botttom]" << endl;
            cout << "South C | J9 | 200m [top+]" << endl;
            cout << "North B | A7 | 200m [top]" << endl;
            cout << "North C | B9 | 350m [top+]" << endl;
            break;

        case 3:
            cout << "--- TOS-1 ---" << endl;
            cout << "Map: Avance to Yew Kay" << endl;
            cout << "South B | J9 | 150m [botttom]" << endl;
            cout << "South C | J9 | 300m [middle]" << endl;
            cout << "North B | B9 | 200m [bottom]" << endl;
            cout << "North C | B9 | 150m [bottom]" << endl;
            break;

        case 4:
            cout << "--- AFG Mk1 ---" << endl;
            cout << "Map: Avance to Yew Kay" << endl;
            cout << "South B | J9 | 300m  [botttom]" << endl;
            cout << "South C | J9 | 450m  [middle]" << endl;
            cout << "North B | B9 | 300m  [top+]" << endl;
            cout << "North C | B9 | 350m  [bottom]" << endl;
            break;
        
        default:
            cout << "no" << endl << endl;
    }

    return 0;
}