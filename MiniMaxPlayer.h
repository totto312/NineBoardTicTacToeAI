//
// Created by Tom Nguyen on 28/8/2024.
//

#ifndef MINIMAXPLAYER_H_
#define MINIMAXPLAYER_H_

class MiniMaxPlayer {				// Was unable to completely get there for minimaxplayer.
public:

    MiniMaxPlayer(NBTicTacToe& game, int player); // Constructor that takes a TicTacToe reference

    bool getComputerMove(int& x, int& y);
    int minimax(int board[3][3], int depth, bool isMaximising);




    		//nine boards
    struct Coordinate {
        int x;
        int y;


        };

    Coordinate currentBoard;

    int player;
    TicTacToe gridInstance[3][3];


};

MiniMaxPlayer::MiniMaxPlayer(NBTicTacToe& game, int player) : player(player) {
    // Copy the gridCopy array to gridInstance
	cout << 1;
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			gridInstance[i][j] = game.grid[i][j];
			}
	}

	cout << 1;

}


bool MiniMaxPlayer::getComputerMove(int& x, int& y) {

	int bestScore = -100000;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0 ; j < 3; j++)
		{
			//is move available?
			if (gridInstance[currentBoard.x][currentBoard.y].board[i][j] == 0)
			{
				gridInstance[currentBoard.x][currentBoard.y].addMove(i, j, player);
				int tempX = currentBoard.x;
				int tempY = currentBoard.y;
				currentBoard.x = i;
				currentBoard.y = j;
				int score = minimax(gridInstance[currentBoard.x][currentBoard.y].board, 0, false);  // perform minimax on new board
				currentBoard.x = tempX;
				currentBoard.y = tempY;
				gridInstance[currentBoard.x][currentBoard.y].board[i][j] = 0;			// remove added move on old board
				currentBoard.x = i;
				currentBoard.y = j;				// update new board
				if (score > bestScore)
				{
					bestScore = score;
					x = i;
					y = j;
				}
			}
		}
	}


	return true;


}

int MiniMaxPlayer :: minimax(int board[3][3], int depth, bool isMaximising) {


	int result = gridInstance[currentBoard.x][currentBoard.y].gameStatus();
	if (result != 0)
	{
		int score = result;
		if (result == 5)
		{
			score = 0;			// DRAW
		}

		return score;
	}


	if (isMaximising)
	{
		int bestScore = -100000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (gridInstance[currentBoard.x][currentBoard.y].board[i][j] == 0)
				{

					gridInstance[currentBoard.x][currentBoard.y].addMove(i, j, player);
					int tempX = currentBoard.x;
					int tempY = currentBoard.y;
					currentBoard.x = i;
					currentBoard.y = j;
					int score = minimax(gridInstance[currentBoard.x][currentBoard.y].board, depth + 1, false);  // perform minimax on new board
					currentBoard.x = tempX;
					currentBoard.y = tempY;
					gridInstance[currentBoard.x][currentBoard.y].board[i][j] = 0;			// remove added move on old board
					currentBoard.x = i;
					currentBoard.y = j;				// update new board


					if (score > bestScore)
					{
						bestScore = score;
					}
				}
			}
		}
		return bestScore;

	} else {		// MINIMISING
		int bestScore = 100000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (gridInstance[currentBoard.x][currentBoard.y].board[i][j] == 0)
				{
					gridInstance[currentBoard.x][currentBoard.y].addMove(i, j, player * (-1));

					int tempX = currentBoard.x;
					int tempY = currentBoard.y;
					currentBoard.x = i;
					currentBoard.y = j;
					int score = minimax(gridInstance[currentBoard.x][currentBoard.y].board, depth + 1, true);  // perform minimax on new board
					currentBoard.x = tempX;
					currentBoard.y = tempY;
					gridInstance[currentBoard.x][currentBoard.y].board[i][j] = 0;			// remove added move on old board
					currentBoard.x = i;
					currentBoard.y = j;				// update new board




					if (score < bestScore)
					{
						bestScore = score;
					}
				}
			}
		}

		return bestScore;
	}
}



#endif /* MiniMaxPlayer_H_ */
