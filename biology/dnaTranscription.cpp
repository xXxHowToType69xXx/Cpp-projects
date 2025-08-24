#include <iostream>
#include <utility>
#include <cctype>

using std::cout, std::cin, std::endl, std::string;

void menu();
void pair();
void reversePair();
void dna_to_mRNA();
void mRNA_to_DNA();
void run();
void convertToUpper(string& s);
void clearScreen();

int main(){
    run();

    return 0;
}

void menu(){
    cout << "==============================" << endl;
    cout << "       DNA Transcription      " << endl;
    cout << "==============================" << endl;
    cout << "1. Pairing DNA (5'-3')" << endl;
    cout << "2. Reverse pairing DNA (3'-5')" << endl;
    cout << "3. DNA to mARN transcription" << endl;
    cout << "4. mRNA to DNA transcription" << endl;
    cout << "5. Exit" << endl;
}

void pair(){
    string start = "5'-";
    string end = "-3'";

    cout << "Enter the DNA strand: ";
    string dna;
    cin.ignore();
    getline(cin, dna);
    convertToUpper(dna);
    string dnaFull = start + dna + end;
    cout << "Your DNA strand: " << dnaFull;

    bool isValid = true;
    for(char c : dna)
    {
        if(c != 'A' && c != 'T' && c != 'G' && c != 'C')
        {
            isValid = false;
            break;
        }
    }

    if(isValid)
    {
        string dnaPair = "";
        string startPair = "3'-";
        string endPair = "-5'";

        for(int i = 0; i < dna.size(); i++)
        {
            if(dna[i] == 'A' || dna[i] == 'a') // A - T
            {
                dnaPair += 'T';
            }
            else if(dna[i] == 'T' || dna[i] == 't') // T - A
            {
                dnaPair += 'A';
            }
            else if(dna[i] == 'G' || dna[i] == 'g') // G - C
            {
                dnaPair += 'C';
            }
            else if(dna[i] == 'C' || dna[i] == 'c') // C - G
            {
                dnaPair += 'G';
            }
        }
    
        clearScreen();

        string dnaNewPair = startPair + dnaPair + endPair;
        cout << "Your entered DNA: " << dnaFull << endl;
        cout << "Your paired DNA strand: " << dnaNewPair << endl;
    }
    else
    {
        cout << "Invalid input of DNA strand. Try again" << endl;
    }
}

void reversePair(){
    string start = "3'-";
    string end = "-5'";

    cout << "Enter the DNA strand: ";
    string dna;
    cin.ignore();
    getline(cin, dna);
    convertToUpper(dna);
    string dnaFull = start + dna + end;
    cout << "Your DNA strand: " << dnaFull;

    bool isValid = true;
    for(char c : dna)
    {
        if(c != 'A' && c != 'T' && c != 'G' && c != 'C')
        {
            isValid = false;
            break;
        }
    }

    if(isValid)
    {
        string dnaPair = "";
        string startPair = "5'-";
        string endPair = "-3'";

        for(int i = 0; i < dna.size(); i++)
        {
            if(dna[i] == 'A' || dna[i] == 'a') // A - T
            {
                dnaPair += 'T';
            }
            else if(dna[i] == 'T' || dna[i] == 't') // T - A
            {
                dnaPair += 'A';
            }
            else if(dna[i] == 'G' || dna[i] == 'g') // G - C
            {
                dnaPair += 'C';
            }
            else if(dna[i] == 'C' || dna[i] == 'c') // C - G
            {
                dnaPair += 'G';
            }
        }

        clearScreen();

        string dnaNewPair = startPair + dnaPair + endPair;
        cout << "Your entered DNA strand: " << dnaFull << endl;
        cout << "Your paired DNA strand: " << dnaPair << endl;
    }
    else
    {
        cout << "Invalid input of DNA strand. Try again" << endl;
    }
}

void dna_to_mRNA(){
    string start = "3'-";
    string end = "-5'";

    cout << "Enter the DNA strand: ";
    string dna;
    cin.ignore();
    getline(cin, dna);
    convertToUpper(dna);
    string dnaFull = start + dna + end;
    cout << "Your DNA strand: " << dnaFull;

    bool isValid = true;
    for(char c : dna)
    {
        if(c != 'A' && c != 'T' && c != 'G' && c != 'C')
        {
            isValid = false;
            break;
        }
    }
     
    if(isValid)
    {
        string mRNAPair = "";
        string startPair = "5'-";
        string endPair = "-3'";

        for(int i = 0; i < dna.size(); i++)
        {
            if(dna[i] == 'A' || dna[i] == 'a') // A - U
            {
                mRNAPair += 'U';
            }
            else if(dna[i] == 'U' || dna[i] == 'U') // U -A
            {
                mRNAPair += 'A';
            }
            else if(dna[i] == 'G' || dna[i] == 'g') // G - C
            {
                mRNAPair += 'C';
            }
            else if(dna[i] == 'C' || dna[i] == 'c') // C - G
            {
                mRNAPair += 'G';
            }
        }
        clearScreen();

        string mRNANewPair = startPair + mRNAPair + endPair;
        cout << "Your entered DNA strand: " << dnaFull << endl;
        cout << "Your transcripted DNA strand: " << mRNAPair << endl;
    }
    else
    {
        cout << "Invalid input of DNA strand. Try again" << endl;
    }
}

void mRNA_to_DNA(){
    string start = "5'-";
    string end = "-3'";

    cout << "Enter the mRNA strand: ";
    string mRNA;
    cin.ignore();
    getline(cin, mRNA);
    convertToUpper(mRNA);
    string mRNA_Full = start + mRNA + end;
    cout << "Your mRNA strand: " << mRNA_Full;

    bool isValid = true;
    for(char c : mRNA_Full)
    {
        if(c != 'A' && c != 'U' && c != 'G' && c != 'C')
        {
            isValid = false;
            break;
        }
    }

    if(isValid)
    {
        string dnaPair = "";
        string startPair = "3'-";
        string endPair = "-5'";

        for(int i = 0; i < mRNA_Full.size(); i++)
        {
            if(mRNA_Full[i] == 'A' || mRNA_Full[i] == 'a') // A - T
            {
                mRNA_Full += 'T';
            }
            else if(mRNA_Full[i] == 'U' || mRNA_Full[i] == 'u') // T - A
            {
                mRNA_Full += 'A';
            }
            else if(mRNA_Full[i] == 'G' || mRNA_Full[i] == 'g') // G - C
            {
                mRNA_Full += 'C';
            }
            else if(mRNA_Full[i] == 'C' || mRNA_Full[i] == 'c') // C - G
            {
                mRNA_Full += 'G';
            }
        }
        
        string dnaNewPair = startPair + dnaPair + endPair;
        cout << "Your entered mRNA strand: " << mRNA_Full << endl;
        cout << "Your transcripted mRNA strand: " << dnaPair << endl;
    }
    else
    {
        cout << "Invalid input of mRNA strand. Try again :P" << endl;
    }
}

void run(){
    int choice;
    do
    {
        menu();
        cout << "Choose your needed appliance: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                pair();
                break;
            case 2:
                reversePair();
                break;
            case 3:
                dna_to_mRNA();
                break;
            case 4:
                mRNA_to_DNA();
                break;
            case 5:
                cout << "bye bye" << endl;
                break;
            default:
                cout << "Invalid choice, try again" << endl;
        }
    } while (choice != 5);
}

void convertToUpper(string& s){
    for(char& c : s)
    {
        c = toupper(c);
    }
}

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}