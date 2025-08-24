#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using std::cout, std::cin, std::endl;

int main(){
    cout << "       Hello and welcome to the abnormal vending machine (F-05-52)" << endl;
    cout << "===========================================================================" << endl;
    std::string items[4][4] = {{"Coca Cola", "Oreo", "Heinz Baked Beans"},
                              {"Bater Acid", "Doritos", "Milk"},
                              {"Coffee", "Pepsi", "SoulGlade"},
                              {"Essence of Savor", "Seasoned Rations","Crabshell Rice"}};

    int rows = sizeof(items) / sizeof(items[0]);
    int columns = sizeof(items[0]) / sizeof(items[0][0]);
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++)
        {
            cout  << " | " << std::setw(20) << std::left << items[i][j] << " ";
        }
        cout << endl;
    }

    int x, y, choice;

    do{
        cout << "Choose an edible" << endl;
        cout << "Enter X (row): ";
        cin >> x;
        x--;
        cout << "Enter Y (column): ";
        cin >> y;
        y--;

        if (x < 0 || x >= rows || y < 0 || y >= columns || items[x][y] == "") 
        {
            cout << "Invalid choice, please try again" << endl;
        }
    } while (x < 0 || x >= rows || y < 0 || y >= columns || items[x][y] == "");

    srand(time(0));
    int random = rand() % 101;

    cout << "You selected " << items[x][y] << endl;
    cout << "Quantity left: " << random << endl;
    
    do{
        cout << "How many " << items[x][y] << " you want?: ";
        cin >> choice;

        if (choice > random) 
        {
            cout << "Insufficient stock :( , please try again with a lower quantity" << endl;
        }
    } while(choice > random);

    cout << "--- Your order ---" << endl;
    cout << "Item: " << items[x][y] << endl;
    cout << "Quantity: " << choice << endl;
    cout << "Thank you for using :3";

    return 0;
}
