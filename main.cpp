#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
#include <limits>

using namespace std;

#include "TicTacToe.h"
#include "NBTicTacToe.h"
#include "HumanPlayer.h"
#include "MiniMaxPlayer.h"
#include "NBGame.h"
#include "RandomComputerPlayer.h"
#include "SmartComputerPlayer.h"




int main() {

    NBGame game(2, 2);
    game.play();

    return 0;
}
