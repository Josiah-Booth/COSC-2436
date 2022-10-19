// lab 12 : COSC1436 - Lab12 - Fall 2021 - Blinn College
// author: Josiah Booth
// notes : boardProblem - take an array representing a sliding tile board as input and find whether it is solvable or not

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int BOARD_SIZE = 9;

bool solvable(int board[]);

int main() {
    
    int board[BOARD_SIZE];
    //initialize array using user input
        cout << "Enter the order of the numbers for the array (0-8)" << endl;
        for (int i = 0; i < BOARD_SIZE; i++){
        cin >> board[i];
        }
    
    //print array
    cout << "The order of the numbers on the board is:" << endl;
    for (int i = 0; i < BOARD_SIZE; i++){
          cout << setw(3) << board [i] << " ";
      }
    cout << endl;

    //pass array to user defined function to determine if it is solvable
    bool isSolvable = solvable(board);

    if(isSolvable == true){
        cout << "This board is solvable." << endl;
    }

    else{
        cout << "This board is not solvable." << endl;
    }

    return 0;
}

bool solvable(int board[]){
    bool isSolvable;
    int inversionCount = 0;

    //nested loop that starts with an element of the array, goes through each element after it, and if there is an inversion it increases the inversion count
    for (int i = 0; i < BOARD_SIZE; i++){
        for(int j = (i+1); j < BOARD_SIZE; j++){
            if(board[i] > board[j] && board[j] != 0){
                inversionCount++;
            }
        }
    }
    //if inversions are even, it is solvable, if they are odd, it isn't
    if (inversionCount % 2 == 0){
        isSolvable = true;
    }
    else{
        isSolvable = false;
    }
    return isSolvable;
    }