#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Global Variables
char miss = 'M';
char hit  = 'H';
int x = 10;        // row 
int y = 10;        // coloum 
int l = 0;         // length
int limited_attempts = 10; 
int score = 0; 
char board[10][10]; 
char display_board[10][10];   

// Functions
void initializeDisplay_board();
void generateShip();
void print_board();
void enterGuess();
bool is_hit(int row, int col);
void playAgain();
void playGame();


int main(){
    
srand(time(0));
initializeDisplay_board();
generateShip();
print_board();
playGame();

  return 0;
}

// initializes game and its display
void initializeDisplay_board(){
    for(int x = 0; x<10; x++){
        for (int y=0; y<10; y++){
            display_board[x][y] = ' '; 
            board[x][y] = ' ';
        }
    }
}

// print board in the display and check where the ship is
void print_board(){
    cout << " ------------------------------" << endl;
    cout << "   Welcome to the Bettleship !"  << endl;
    cout << " ------------------------------" << endl;
    cout << endl;
    cout << "  ";                                 // Move over a space before printing the 'A'
    for (char a = 'A'; a <= 'J'; a++){
        cout << a << " ";
    } cout << endl;
    
    for (int i = 0 ; i < 10 ; i++){
        cout << i << " ";
        for (int y = 0; y < 10; y++){
            cout << board[i][y] << " ";
        }
        cout << endl;
    }
// print display board again for the actual game without the ship assigned
    cout << endl;
    cout << " ------------------------------" << endl;
    cout << "         Actual Game !         " << endl;
    cout << " ------------------------------" << endl;
    cout << endl;
    cout << "  ";                                 // Move over a space before printing the 'A'
    for (char a = 'A'; a <= 'J'; a++){
        cout << a << " ";
    } cout << endl;
    
    for (int i = 0 ; i < 10 ; i++){
        cout << i << " ";
        for (int y = 0; y < 10; y++){
            cout << display_board[i][y] << " ";
        }
        cout << endl;
    }
}

/* create a random position for the ship, and set the position = 1
       this grid is for the vertical direction of ship */
void generateShip(){  
    srand(time(0));     
    y = rand() % 10;    // program randomly determined coloum (y)
    x = rand() % 10;    // program randomly determined row (x)
    l = rand() % 5+1;   // program randomly determined length (l) and the length of the ship should be 1 to 5 
        for (int nRow = x; nRow < (x+l); nRow++){
            board[nRow+1][y] = 'S';   // Ship = 'S'
        }
    }

// Ask the user to enter the row and coloum to guess where the ship had assigned.
void enterGuess(){
    string guess;
    cout << "Please Enter the Location: ";
    getline(cin,guess);
    int n = guess.at(1)- 48;   // in ASCII 48 is the char of '0', n = row 
    int i = guess.at(0) - 65;  // in ASCII 65 is the char of 'A', i = column
    is_hit(n,i);
}

/* check if the user enter the location of the ship is hit or miss.
if the ship is hit, then 'H' will be display in the grid and the score will increase to 1.
if the ship is miss, then 'M' will be display in the grid and the attempt will decrease to 1. */
bool is_hit(int row, int col) {
     bool hit = false;
          if (board[row][col] == 'S') {
            hit = true;
            display_board[row][col] = 'H' ;
            score = score + 1;
            cout << "Wow, You've Hit It!" << " " << "Score:" << score << endl;
          }
           else { 
               display_board[row][col]= 'M';
               limited_attempts = limited_attempts - 1;
               cout << "Woops, You've Miss It!" << " " << "Attempt Left: " <<  limited_attempts << endl;
           }
                 return false;           
} 

// Make sure the ship has been sunk. (length = l)
void playGame(){
    while (score < l && limited_attempts > 0){
    enterGuess();
    print_board();
    }
    if (limited_attempts <= 0 ){
        cout << "Sorry ~ You lose! " << endl;
        cout << endl;
    }
        else {
         cout << "Congrats ~ Your ship sunk !" << endl;
         cout << endl;
     }
   playAgain();
}   

// Ask the user want to play the game again.
void playAgain() {
    char response;
    cout << " Want to play again?  Y/N " << endl;
    cin >> response;
    if (response == 'N'){
        cout << " Thank you ! ";
    }
    // if response is yes, it will play again.
    if (response == 'Y'){  
        limited_attempts = 10;
        score =0;
        main();
    }

}