//
// Created by Tom Nguyen on 28/8/2024.
//
#ifndef SMARTCOMPUTERPLAYER_H_
#define SMARTCOMPUTERPLAYER_H_

class SmartComputerPlayer {
public:
    SmartComputerPlayer(const TicTacToe& game); // Use a const reference to avoid modifications
    bool getSmartComputerMove(int& x, int& y);

private:
    TicTacToe gameState; // Use a separate copy for internal state

};

SmartComputerPlayer::SmartComputerPlayer(const TicTacToe& game) : gameState(game) {
}

bool SmartComputerPlayer::getSmartComputerMove(int& x, int& y) {
    srand(time(0));
    int player = 1;

    // Create a separate copy of the gameState to work with
    TicTacToe gameCopy = gameState;

    // Check if there's a winning move for the player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameCopy.board[i][j] == 0) {
                // Make the move for the player
                gameCopy.addMove(i, j, player);

                // Check if this move leads to a win for the player
                if (gameCopy.gameStatus() == player) {
                    x = i;
                    y = j;
                    return true;
                }

                // Undo the move
                gameCopy.board[i][j] = 0;
            }
        }
    }

    // Check if there's a winning move for the opponent and block it
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameCopy.board[i][j] == 0) {
                // Make the move for the opponent
                gameCopy.addMove(i, j, -player);

                // Check if this move leads to a win for the opponent
                if (gameCopy.gameStatus() == -1) {
                    // Block the opponent's winning move
                    x = i;
                    y = j;
                    return true;
                }

                // Undo the move
                gameCopy.board[i][j] = 0;
            }
        }
    }

    // If no winning moves are found, make a random move
    x = rand() % 3;
    y = rand() % 3;

    return true;
}

#endif /* SMARTCOMPUTERPLAYER_H_ */
