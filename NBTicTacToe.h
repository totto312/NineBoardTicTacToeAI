//
// Created by Tom Nguyen on 28/8/2024.
//


#ifndef NBTICTACTOE_H_
#define NBTICTACTOE_H_


class NBTicTacToe {
public:

	NBTicTacToe(int x, int y) {

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			grid[i][j] = TicTacToe();
			}
	}

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			gridCopy[i][j] = TicTacToe();
			}
	}

	srand(time(0));
	currentBoard.x = rand() % 3;
	currentBoard.y = rand() % 3;


	currentBoard.x = (currentBoard.x + x - 1) % 3;
	currentBoard.y = (currentBoard.y + y - 1) % 3;
	}
	int player = 0;




    void displayBoards();



    bool areAllGridsFull() const {
    	for (int i = 0; i < 3; i++) {
             for (int j = 0; j < 3; j++) {
                 if (grid[i][j].getNoOfMoves() < 9) {
                     return false; // If any grid is not full, return false
                 }
             }
         }
         return true; // All grids are full
     }


    TicTacToe board;

    TicTacToe grid [3][3];		//nine boards
    TicTacToe gridCopy [3][3];
    struct Coordinate {
        int x;
        int y;
        };

    Coordinate currentBoard;

};




void NBTicTacToe::displayBoards() {
    int printGrid[9][9];
    int rowCounter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            const int* currentBoardArray = grid[i][j].getBoard();
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    int value = currentBoardArray[row * 3 + col];
                    printGrid[i * 3 + row][j * 3 + col] = value;
                }
            }
        }
    }

    for (int i = 0; i < 21; i++) {


        if (i == 0 || i == 6 || i == 7 || i == 13 || i == 14 || i == 20) {
        	int loopCounter;

        	if (i == 0)
        		loopCounter = 0;
        	if (i == 7 || i == 14)
        		loopCounter++;

        	for (int k = 0; k < 3; k++){
        		char symbol = '-';
        		if (k == currentBoard.y && currentBoard.x == loopCounter)
        		{
        			symbol = '*';
        		}
        		for (int j = 0; j < 5; j++) {



        			if (j == 0) {
        				cout << "  ";
        			}
        			cout << symbol << " ";

        			if (j % 5 == 4) {
        				cout << " ";
        			}
        		}
        	}



        } else {
            cout << endl;
        }



        if (i == 1 || i == 3 || i == 5 || i == 8 || i == 10 || i == 12 || i == 15 || i == 17 || i == 19) {
            string symbol;
            string starOrBar;
            int loopCounter;
            if (i == 1) {
                rowCounter = 0;
                loopCounter = 0;
            }

            if (i == 8 || i == 15) {
                loopCounter++;
            }

            for (int j = 0; j < 3; j++) {
                starOrBar = "|";  // Reset starOrBar for each iteration of the inner loop

                if (j == currentBoard.y && currentBoard.x == loopCounter) {
                    starOrBar = "*";
                }

                for (int a = 0; a < 3; a++) {
                    if (printGrid[rowCounter][a + (j * 3)] == 1)
                        symbol = "X";
                    else if (printGrid[rowCounter][a + (j * 3)] == -1)
                        symbol = "O";
                    else
                        symbol = " ";
                    if (a == 0)
                    	cout << starOrBar << " " << symbol << " ";
                    else {
                    	cout << "|" << " " << symbol << " ";
                    }
                    if (a == 2) {
                        cout << starOrBar;
                    }
                }
            }

            rowCounter++;
        }


        if (i == 2 || i == 4 || i == 9 || i == 11 || i == 16 || i == 18){
        	int loopCounter;

        	if (i == 2)
        		loopCounter = 0;

        	if (i == 9 || i == 16)
        		loopCounter++;


        	for (int i = 0; i < 3; i ++){

        		if (i == currentBoard.y && currentBoard.x == loopCounter)
        			cout << "*  -  -  -  *";
        		else
        			cout << "|  -  -  -  |";




        	}



        }


        if (i == 5 || i == 12 || i == 19 || i == 6 || i == 13){

        	cout << endl;
        }


        if (i == 20)
        	cout << endl;
    }
}



















#endif /* NBTICTACTOE_H_ */
