#include "Desert.h"

bool Desert::action(Player& player) {

    return true;
}

Tile* Desert::clone() {
    return new Desert();
}