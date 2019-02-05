#include <iostream>
#include <cstring>
using std::array;
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Board {
    public:
        enum Organism { NONE, LIVING, DYING };
        void start();
        void printBoard();
        void setBoard(int x, int y, Organism value);
        int getStatus(int x, int y);
        Board();

    private:
        int ROWS;
        int COLUMNS;
        int initial;
        enum Organism boardOne[20][52];
};

/* Constructor for Board that sets the rows and columns
*  to the specified parameters in the project instructions
*/
Board::Board() {
    ROWS = 18;
    COLUMNS = 50;
}

void Board::start() {

}

/* Prints out the board showing every Organism status:
*  either None, Dead, or Living
*/
void Board::printBoard() {
    // Creates the border for the top of the board
    cout << endl;
    for (int y = 0; y < COLUMNS; y++) {
        if (y == COLUMNS -1 || y == 0) {
            cout << "+";
        }
        else {
            cout << "-";
        }
    }
    // Goes to the next line after creating the top border
    cout << endl;
    // Does a nested for loop to draw each space
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLUMNS; y++) {
            // Draws a line for each left border in a row
            if (y == 0) {
                cout << "|";
            }
            // Draws the status for each space considered an organism
            else if ((y != 0) && (y != COLUMNS-1)) {
                cout << " ";
            }
            // Draws a line for each right border in a row
            else if (y == COLUMNS-1) {
                cout << "|" << endl;
            }
        }
    }
    // Creates the border for the bottom of the board
    for (int y = 0; y < COLUMNS; y++) {
        if (y == COLUMNS -1 || y == 0) {
            cout << "+";
        }
        else {
            cout << "-";
        }
    }
    // Goes to the next line and creates a blank one for aesthetics
    cout << endl;
    cout << endl;
}

/* Sets the status of an Organism
*/
void Board::setBoard(int x, int y, Organism value) {
    boardOne[x][y] = value;
}

/* Gets the status of an Organism
*/
int Board::getStatus(int x, int y) {
    return boardOne[x][y];
}






int main() {
    Board board;
    board.setBoard(0, 0, Board::Organism::LIVING);
    cout << "Status as location (0,0): " << board.getStatus(0,0) << endl;
    board.printBoard();
}