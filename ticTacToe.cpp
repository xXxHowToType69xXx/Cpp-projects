#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout, std::cin, std::endl;

void drawBoard(char *board);
void player1Move(char *board, char player1);
void player2Move(char *board, char player2);
void computerMove(char *board, char computer);
bool checkTie(char *board);
bool checkWinner(char *board, char player);
void clearScreen();

int main(){
    char board[9] = {' ', ' ', ' ',
                     ' ', ' ', ' ',
                     ' ', ' ', ' '};
    int choice;
    cout << "===== Tic-Tac-Toe =====" << endl;
    cout << "Available gamemodes: " << endl;
    cout << "1. PvP" << endl;
    cout << "2. PvE" << endl;
    cout << "Select the gamemode: ";
    cin >> choice;
    bool running = true;
    char winner = ' ';
    // some ugly shits here
    if(choice == 1)
    {
        char player1 = 'X';
        char player2 = 'O';

        while(running)
        {
            cout << "*** Player 1's move ***" << endl;
            drawBoard(board);
            player1Move(board, player1);
            clearScreen();
            if(checkWinner(board, player1))
            {
                winner = player1;
                running = false;
                break;
            }
            else if(checkTie(board))
            {
                winner = 'T';
                running = false;
                break;
            }

            cout << "*** Player 2's move ***" << endl;
            drawBoard(board);
            player2Move(board, player2);
            clearScreen();
            if(checkWinner(board, player2))
            {
                winner = player2;
                running = false;
                break;
            }
            else if(checkTie(board))
            {
                winner = 'T';
                running = false;
                break;
            }
        }

        drawBoard(board);

        if(winner == player1) 
        {
            cout << "!!! Player 1 wins !!!" << endl;
            cout << "The final piece falls into place. They have won, at least for now." << endl;
        } 
        else if(winner == player2) 
        {
            cout << "!!! Player 2 wins !!!" << endl;
            cout << "The final piece falls into place. They have won, at least for now." << endl;
        } 
        else if(winner == 'T') 
        {
            cout << "The board is static. You are equally matched." << endl;
        }
    }
    else if(choice == 2)
    {
        char player1 = 'X';
        char computer = 'O';

        while(running)
        {
            cout << "*** Player's move ***" << endl;
            drawBoard(board);
            player1Move(board, player1);
            clearScreen();
            if(checkWinner(board, player1))
            {
                winner = player1;
                running = false;
                break;
            }
            else if(checkTie(board))
            {
                winner = 'T';
                running = false;
                break;
            }

            drawBoard(board);
            computerMove(board, computer);
            clearScreen();
            if(checkWinner(board, computer))
            {
                winner = computer;
                running = false;
                break;
            }
            else if(checkTie(board))
            {
                winner = 'T';
                running = false;
                break;
            }
        }

        drawBoard(board);

        if(winner == player1) 
        {
            cout << "!!! The player wins !!!" << endl;
            cout << "The clanker is defeated. We human are superior.";
        }
        else if(winner == computer) 
        {
            cout << "!!! The clanker wins !!!" << endl;
            cout << "The sky bleeds red as the air thickens in fear. Your downfall has been calculated." << endl;
        } 
        else if(winner == 'T') 
        {
            cout << "The board is static. You are equally matched." << endl;
        }
    }
    return 0;
}

void drawBoard(char *board){
    cout << "           |           |           " << endl;
    cout << "     " << board[0] << "     |     " << board[1]  << "     |     " << board[2] << endl;
    cout << "___________|___________|___________" << endl;
    cout << "           |           |           " << endl;
    cout << "     " << board[3] << "     |     " << board[4]  << "     |     " << board[5] << endl;
    cout << "___________|___________|___________" << endl;
    cout << "           |           |           " << endl;
    cout << "     " << board[6] << "     |     " << board[7]  << "     |     " << board[8] << endl;
    cout << "           |           |           " << endl;
}

void player1Move(char *board, char player1){
    int number;

    do{
        cout << "Select a position to place down (1-9): ";
        cin >> number;
        number--;
        
        if(number >= 0 && number <= 8 && board[number] == ' ')
        {
            board[number] = player1;
            break;
        }
        else
        {
            cout << "The space is not yours to claim. Your choice is invalid. " << endl;
        }

    } while(true);
}

void player2Move(char *board, char player2){
    int number;

    do{
        cout << "Select a position to place down (1-9): ";
        cin >> number;
        number--;
        
        if(number >= 0 && number <= 8 && board[number] == ' ')
        {
            board[number] = player2;
            break;
        }
        else
        {
            cout << "The space is not yours to claim. Your choice is invalid. ";
        }

    } while(true);
}

void computerMove(char *board, char computer){
    int number;
    srand(time(0));

    while(true){
        number = rand() % 9;
        if(board[number] == ' ')
        {
            board[number] = computer;
            break;
        }
    }
}

bool checkTie(char *board){
    for(int i = 0; i < 9; i++){
        if(board[i] == ' ')
        {
            return false;
        }
    }
    cout << "The board is static. You are equally matched. ";
    return true;
}

bool checkWinner(char *board, char player){
    int winCondition[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}             // diagonols
    }; // total 8

    for(int i = 0; i < 8; i++){
        int a = winCondition[i][0];
        int b = winCondition[i][1];
        int c = winCondition[i][2];

        if(board[a] != ' ' && board[a] == board[b] && board[b] == board[c])
        {
            return true;
        }
    
    }
    return false;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}