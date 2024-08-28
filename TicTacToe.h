//
// Created by Tom Nguyen on 28/8/2024.
//

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

const int BOARDSIZE = 3;

class TicTacToe {
public:
    int board[BOARDSIZE][BOARDSIZE];
    int noOfMoves;


    TicTacToe();

    bool isValidMove(int, int);
    void addMove(int, int, int);
    int gameStatus() const;
    int getNoOfMoves() const;
    const int* getBoard() const {
        return &board[0][0];
    }
};

TicTacToe::TicTacToe() {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = 0;

    noOfMoves = 0;
}



bool TicTacToe::isValidMove(int x, int y) {
    if (x > 2 || y > 2) {
        return false;
    } else if (x < 0 || y < 0) {
        return false;
    } else if (board[x][y] != 0) {
        return false;
    } else
        return true;
}


int TicTacToe::getNoOfMoves() const {
    return noOfMoves;
}

void TicTacToe::addMove(int x, int y, int player) {
    board[x][y] = player;
    noOfMoves++;
}

int TicTacToe::gameStatus() const {	for (int i = 0; i < 3; i++) {

    if (noOfMoves >= 9){
        return 5;
    }

    if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1)
        return 1;
    else if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == -1)
        return -1;
}

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1)
            return 1;
        else if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1)
            return -1;
    }

    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
        return 1;
    else if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1)
        return -1;

    if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
        return 1;
    else if (board[0][2] == -1 && board[1][1] == -1 && board[2][0] == -1)
        return -1;



    return 0;


}






#endif /* TICTACTOE_H_ */
