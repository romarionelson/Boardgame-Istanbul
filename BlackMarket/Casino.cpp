#include "Casino.h"

#define BLACKMARKET_COST 1

Casino::Casino(void) : Tile() {
    type = CasinoType;
}

bool Casino::action(Player& player) {
    //no gold, no action
    if (player.gold == 0)
        return false;
    int x = rand() % 10;
    //less than 4 is loss
    if (x >= 4) {
        // return float
        if (x >= 4 && x <= 6)
            player.gold += 2;
        else if (x >= 7 && x <= 8)
            player.gold += 3;
        else if (x == 9)
            player.gold += 10;
    }
    return true;
}

Tile* Casino::clone() {
    return new Casino();
}