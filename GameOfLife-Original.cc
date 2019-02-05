#include <iostream>
#include <cstring>
using namespace std;

class Board {
    public:
        void start();
        void printBoard();
        void setBoard(int x, int y, bool value);
        bool getStatus(int x, int y);
        Board();

    private:
        int ROWS = 18;
        int COLUMNS = 50;
        bool boardOne[18][50] = {};
};


Board::Board() {
    ROWS = 18;
    COLUMNS = 50;
}

void Board::start() {

}

void Board::printBoard() {
    // Creates the border for the top of the board with "-"
    for (int y = 0; y < COLUMNS; y++) {
        cout << " -";
    }
    // Does a nested for loop to draw each space
    for (int x = 0; x < ROWS; x++) {
        cout << endl;
        for (int y = 0; y < COLUMNS; y++) {
            // Draws the left and right border if the space is apart of the last column
            if (y == 49) {
                // If the space [x][y] is true, it will print a star
                if (boardOne[x][y] == true) {
                    cout << "|*|";
                }
                // If the space [x][y] is false, it will print a space
                else {
                    cout << "| |";
                }
            }
            // Draws the left border only if the space is not apart of the last column
            else {
                // If the space [x][y] is true, it will print a star
                if (boardOne[x][y] == true) {
                    cout << "|*";
                }
                //If the space [x][y] is false, it will print a space
                else {
                    cout << "| ";
                }
            }
        }
        cout << endl;
        // Creates the bottom border for each row with "-"
        /* This is apart of the for loop for iterating "x" because we want to draw a
           bottom border after each row of "| |" is drawn
        */
        for (int x = 0; x < COLUMNS; x++) {
        cout << " -";
        }
    }
    cout << endl;
    cout << endl;
}

void Board::setBoard(int x, int y, bool value) {
    boardOne[x][y] = value;
}

bool Board::getStatus(int x, int y) {
    return boardOne[x][y];
}






int main() {
    Board board;
    //Organism o;
    //cout << o.getStatus() << endl;
    board.setBoard(0, 0, true);
    cout << "Status as location (0,0): " << board.getStatus(0,0) << endl;
    cout << "Status of location (0, 2): " << board.getStatus(1,17) << endl;
    board.printBoard();
}