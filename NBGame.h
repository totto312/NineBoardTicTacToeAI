//
// Created by Tom Nguyen on 28/8/2024.
//


#ifndef NBGAME_H_
#define NBGAME_H_
#include "RandomComputerPlayer.h"
#include "SmartComputerPlayer.h"
class NBGame {

private:
    NBTicTacToe game;
    int opponentChoice;

public:




    NBGame(int x, int y) : game(x, y), opponentChoice(0) {}



    int getPlayerChoice() {
        cout << "Select opponent:" << endl;
        cout << "1. Random Computer Player" << endl;
        cout << "2. Minimax Player" << endl;
        cout << "3. Smart Computer Player" << endl;
        cout << "Enter your choice (1/2/3): ";
        cin >> opponentChoice;
        return opponentChoice;
    }



    bool getHumanMove(int& x, int& y) {
        HumanPlayer humanPlayer;
        return humanPlayer.getHumanMove(x, y);
    }

    bool getMinimaxMove(int& x, int& y) {
    	MiniMaxPlayer minimaxPlayer(game, game.player);
        return minimaxPlayer.getComputerMove(x, y);
    }

    bool getRandomComputerMove(int& x, int& y) {
    	RandomComputerPlayer randomcomputerPlayer;
    	return randomcomputerPlayer.getComputerMove(x,y);
    }

    bool getSmartComputerMove(int& x, int & y)
    {
    	SmartComputerPlayer smartcomputerPlayer(game.grid[game.currentBoard.x][game.currentBoard.y]);
    	return smartcomputerPlayer.getSmartComputerMove(x, y);
    }




    void play() {

        int player = 1;

        opponentChoice = getPlayerChoice();
        if (opponentChoice != 1 && opponentChoice != 2 && opponentChoice != 3)
        {
        	cout << "Invalid choice. Exiting the game." << endl;
        	return;
        }

        game.displayBoards();

        int done = 0;
        while (done == 0) {
            char playerSymbol = (player == 1) ? 'X' : 'O';

            if (player == -1) {
                cout << "Player " << playerSymbol << " enter move: ";
            }

            int x, y;

            if (player == 1) {
            	if (opponentChoice == 1) {
            		getRandomComputerMove(x,y);
            	} else if (opponentChoice == 2)
            	{
            		getMinimaxMove(x,y);
            	} else
            	{
            		getSmartComputerMove(x,y);
            	}

                while (!game.grid[game.currentBoard.x][game.currentBoard.y].isValidMove(x, y)) {
                	if (opponentChoice == 1) {
                		getRandomComputerMove(x,y);
                	} else if (opponentChoice == 2)
                	{
                		getMinimaxMove(x,y);
                	} else
                	{
                		getSmartComputerMove(x,y);
                	}
                }
                cout << "Player X Move: " << x + 1 << " " << y + 1 << endl;
            } else {
                getHumanMove(x, y); // Use the appropriate player
                while (!game.grid[game.currentBoard.x][game.currentBoard.y].isValidMove(x, y)) {
                    cout << "Invalid move. Please try again:" << endl;
                    getHumanMove(x, y);
                }
            }

            game.grid[game.currentBoard.x][game.currentBoard.y].addMove(x, y, player);

            done = game.grid[game.currentBoard.x][game.currentBoard.y].gameStatus();
            if (done == 1) {
                game.displayBoards();
                cout << "Player X wins!" << endl;
                return;
            } else if (done == -1) {
                game.displayBoards();
                cout << "Player O wins!" << endl;
                return;
            } else if (game.areAllGridsFull()) {
                game.displayBoards();
                cout << "Draw Game!" << endl;
                return;
            }

            player =  -player; // Switch player's turn

            game.currentBoard.x = x;
            game.currentBoard.y = y;

            while (game.grid[game.currentBoard.x][game.currentBoard.y].getNoOfMoves() >= 9) {
                game.currentBoard.x = rand() % 3;
                game.currentBoard.y = rand() % 3;
                x = game.currentBoard.x; // Update x to the new value
                y = game.currentBoard.y; // Update y to the new value
            }

            game.displayBoards();

        }
    }


};



#endif /* NBGAME_H_ */
