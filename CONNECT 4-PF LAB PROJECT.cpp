#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Function & Global Variable Declarartion.

const int ROW = 6;
const int COL = 7;
char board[ROW][COL];
bool gameFinished = false;
char currentPlayer = 'O';
char CP = ' ';
void displayBoard();
int playerChoosesColumn(char currentPlayer);
int findFreeRow(int validColumn);
void checkGameFinished(char currentPlayer, int validRow, int validColumn);
bool checkHorizontal(char currentPlayer, int validRow, int column);
bool checkVertical(char currentPlayer, int validColumn);
bool checkDiagonal(char currentPlayer, int validRow, int validColumn);
bool checkReverseDiagonal(char currentPlayer, int validRow, int validColumn);
void swapPlayer();
int p1 = 0, p2 = 0, d = 0;
void toss(string name, string name1);
void instructions();
string player1, player2;

//Main program which controls the iteration and call the function sequentially.
int main() {

    cout << setw(75) << "---------------WELCOME TO CONNECT 4---------------" << endl << endl;

    cout << "Enter 0 to play & -1 to exit the game\n";
    cout << endl;

    int opt;
    string name, name1;
    bool flag = false;
    int choice = 0;
    while (flag == false)
    {
        cin >> choice;
        if (choice == 0 || choice == -1)
        {
            flag = true;
        }
        else
        {
            cout << "Enter the valid choice\n";
            continue;
        }
    }
   
    cout << endl;
    while (choice == 0)
    {

        cout << setfill('-') << setw(50) << "\t" << endl;

        cout << "-" << setfill(' ') << setw(31) << "1. To play the game" << setfill(' ') << setw(17) << "-" << endl;
        cout << "-" << setfill(' ') << setw(22) << "2. Credits" << setfill(' ') << setw(26) << "-" << endl;
        cout << "-" << setfill(' ') << setw(27) << "3. Instructions" << setfill(' ') << setw(21) << "-" << endl;
        cout << "-" << setfill(' ') << setw(21) << "4. Record" << setfill(' ') << setw(27) << "-" << endl;
        cout << "-" << setfill(' ') << setw(19) << "5. Exit" << setfill(' ') << setw(29) << "-" << endl;
        cout << "-------------------------------------------------\n";

        cin >> opt;
        switch (opt)
        {

            {
        case 1:
        {
            bool valid = false;
            bool valid2 = false;
            while (valid == false)
            {
                cout << "Player 1 Enter your name\n";
                getline(cin, name);
                for (int i = 0; i < name.length(); i++)
                {
                    if (name[i] >= 'A' || name[i] >= 'a' && name[i] >= 'Z' || name[i] >= 'z')
                        valid = true;


                }
                if (valid == false)
                {
                    cout << "Invalid name\n";
                    continue;
                }
            }

            while (valid2 == false)
            {
                cout << "Player 2 Enter your name\n";
                getline(cin , name1);
                for (int i = 0; i < name1.length(); i++)
                {
                    if (name1[i] >= 'A' || name1[i] >= 'a' && name1[i] >= 'Z' || name1[i] >= 'z')
                        valid2 = true;

                }
                if (valid2 == false)
                {
                    cout << "Invalid name\n";
                    continue;
                }
            }


            toss(name, name1);
            system("pause");

            for (int i = 0; i < ROW; ++i) {
                for (int j = 0; j < COL; ++j) {
                    board[i][j] = '_';
                }
            }

            system("cls");
            displayBoard();

            cout << endl;
            while (!gameFinished) {
                int validcolumn = playerChoosesColumn(currentPlayer);
                int validrow = findFreeRow(validcolumn);
                board[validrow][validcolumn] = currentPlayer;

                system("cls");
                displayBoard();
                cout << endl;
                checkGameFinished(currentPlayer, validrow, validcolumn);


                swapPlayer();
            }

            break;
        }

        case 2:
        {
            cout << setfill(' ') << setw(25) << "Credits" << endl;
            cout << setfill(' ') << setw(30) << "Ayaan Hassan \n";
            cout << setfill(' ') << setw(30) << "Hassaan Bashir\n";

            break;
        }

        case 3:
        {
            instructions();
            break;
        }
        case 4:
        {
            cout << "Record is stored in file named as record\n";
            ofstream fout;
            fout.open("Record.txt", ios::app);
            if (!fout.is_open())
            {
                cout << "File not open\n";
                return -1;
            }
            else
                if (CP == 'O')
                {
                    fout << player1 << " " << "won in : " << p1 << " " << "turns" << endl;
                }

                else if (CP == 'X')
                {
                    fout << player2 << " " << "won in :" << p2 << " " << "turns" << endl;
                }
                else if (CP == ' ')
                {
                    fout << player1 << " " << "turns are :" << " " << p1 << endl;
                    fout << player2 << " " << "turns are :" << " " << p2 << endl;
                }
            break;
        }
        case 5:
        {
            exit(-1);
            break;
        }

        default:
            break;
            }

        }
        cout << endl;
        cout << "Enter 0 to continue and -1 to exit\n";
        while (flag == false)
        {
            cin >> choice;
            if (choice == 0 || choice == -1)
            {
                flag = true;
            }
            else
            {
                cout << "Enter the valid choice\n";
                continue;
            }
        }
        system("cls");

    }

    return 0;
}

//To Display the board.
void displayBoard() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            cout << "|" << setw(3) << board[i][j] << "  ";
            if (j == COL - 1) {
                cout << "|" << " ";
            }
        }
        cout << endl;
    }
}


//Ask player to enter the column
int playerChoosesColumn(char currentPlayer) {
    int columnNumber;
    bool valid = false;
    do {
        if (currentPlayer == 'O') {
            cout << player1 << " " << "Enter the column number(0 - 6) : ";
            p1++;
        }
        else {
            cout << player2 << " " << "Enter column number(0 - 6) : ";
            p2++;
        }
        cin >> columnNumber;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (columnNumber >= 0 && columnNumber < COL) {
            valid = true;
        }
        else {
            cout << "Invalid column number. Please try again.\n";
        }
    } while (!valid);

    return columnNumber;
}

// To find the free row.
int findFreeRow(int validColumn) {
    int thisRow = ROW - 1;

    while (thisRow >= 0 && board[thisRow][validColumn] != '_') {
        --thisRow;
    }
    return thisRow;
}

//To detect the winner or the game is draw.
void checkGameFinished(char currentPlayer, int validRow, int validColumn) {
    bool winnerFound = false;
    winnerFound = checkHorizontal(currentPlayer, validRow, validColumn) ||
        checkVertical(currentPlayer, validColumn) ||
        checkDiagonal(currentPlayer, validRow, validColumn) ||
        checkReverseDiagonal(currentPlayer, validRow, validColumn);

    if (winnerFound) {
        gameFinished = true;
        if (currentPlayer == 'O')
        {
            cout << player1 << " " << "has won the game!\n";
            CP = 'O';
            p1++;
        }
        else
        {
            cout << player2 << " " << "has won the game!\n";
            CP = 'X';
            p2++;
        }
    }
    else {
        bool fullBoard = true;
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (board[i][j] == '_') {
                    fullBoard = false;
                    break;
                }
            }
            if (!fullBoard) {
                break;
            }
        }
        if (fullBoard) {
            gameFinished = true;
            cout << "The board is full. It's a draw!\n";
            CP = ' ';
        }
    }
}

//To check the combo horizontally.
bool checkHorizontal(char currentPlayer, int validRow, int column) {
    int count = 0;

    for (int col = 0; col < COL; ++col) {
        if (board[validRow][col] == currentPlayer) {
            count++;
            if (count >= 4) {
                return true;
            }
        }
        else {
            count = 0;
        }
    }
    return false;
}

// To check the combo vertically.
bool checkVertical(char currentPlayer, int validColumn) {
    int count = 0;

    for (int row = 0; row < ROW; ++row) {
        if (board[row][validColumn] == currentPlayer) {
            count++;
            if (count >= 4) {
                return true;
            }
        }
        else {
            count = 0;
        }
    }
    return false;
}


// To check the combo in main diagonal.

bool checkDiagonal(char currentPlayer, int validRow, int validColumn) {
    int count = 0;

    for (int offset = -3; offset <= 3; ++offset) {
        int row = validRow + offset;
        int col = validColumn + offset;

        if (row >= 0 && row < ROW && col >= 0 && col < COL) {
            if (board[row][col] == currentPlayer) {
                count++;
                if (count >= 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
    }
    return false;
}


// To check the combo in the reversed diagonal.

bool checkReverseDiagonal(char currentPlayer, int validRow, int validColumn) {
    int count = 0;

    for (int offset = -3; offset <= 3; ++offset) {
        int row = validRow - offset;
        int col = validColumn + offset;

        if (row >= 0 && row < ROW && col >= 0 && col < COL) {
            if (board[row][col] == currentPlayer) {
                count++;
                if (count >= 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
    }
    return false;
}

// To swap the players.
void swapPlayer() {
    if (currentPlayer == 'O') {
        currentPlayer = 'X';
    }
    else {
        currentPlayer = 'O';
    }
}

//Function for toss.
void toss(string name, string name1)
{
   
    int t1, toss;
    bool fine = false;
    cout << name << " " << "\"Enter 0 or 1 for the toss\"\n";
    while (fine == false)
    {
        cin >> t1;
        if (t1 == 0 || t1 == 1)
        {
            fine = true;

        }
        else
        {
            cout << "Enter valid number\n";
            continue;
        }
           

    }
    
   
    toss = rand() % 2;

    if (toss == t1)
    {
        cout << name << " " << "you won the toss\n";
        player1 = name;
        player2 = name1;
    }
    else
    {
        cout << name1 << " " << "you won the toss\n";
        player1 = name1;
        player2 = name;
    }


}

//Function to display instructions.
void instructions()
{
    cout << "how to play the game \n" << setw(20);


    cout << "1. connect four is a game with a 6x7 grid.\n";

    cout << "2. players take turns dropping colored discs into columns.\n";

    cout << "3. the goal is to make a line of four of your discs.\n";

    cout << "4. lines can be horizontal, vertical, or diagonal.\n";

    cout << "5. the first player to achieve this wins.\n";

    cout << "6. the game ends in a draw if the grid fills up.\n";

    cout << "7. you can't place discs in full columns.\n";

    cout << "8. strategize to win and block your opponent.\n";

    cout << "that's the essence of connect four!\n";
}
