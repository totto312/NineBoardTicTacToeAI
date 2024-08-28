//
// Created by Tom Nguyen on 28/8/2024.
//

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

class HumanPlayer {
public:
    bool getHumanMove(int& x, int& y);
};

bool HumanPlayer::getHumanMove(int& x, int& y) {

    while (true) {
        int row, col;
        cin >> row >> col;
        cout << endl;

        x = row - 1;
        y = col - 1;
        return true;

    }
}
#endif /* HUMANPLAYER_H_ */
