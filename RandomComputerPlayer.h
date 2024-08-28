//
// Created by Tom Nguyen on 28/8/2024.
//
#ifndef RANDOMCOMPUTERPLAYER_H_
#define RANDOMCOMPUTERPLAYER_H_

class RandomComputerPlayer {
public:

    bool getComputerMove(int& x, int& y);
};


bool RandomComputerPlayer::getComputerMove(int& x, int& y) {

    x = rand() % 3;
    y = rand() % 3;

    return true;
}




#endif /* RANDOMCOMPUTERPLAYER_H_ */
