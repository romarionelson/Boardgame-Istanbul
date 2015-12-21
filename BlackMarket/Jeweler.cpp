#include "Jeweler.h"
#define JEWEL_COUNT 3
#define JEWEL_COST 3

Jeweler::Jeweler(void) : Tile() {
    type = JewelerType;
}

bool Jeweler::action(Player& player) {

    if (player.gold >= JEWEL_COST) {
        player.jewel += MIN(player.cartCapacity(), JEWEL_COUNT);
        player.gold -= JEWEL_COST;
        return true;
    }
    return false;
}

Tile* Jeweler::clone() {
    return new Jeweler();
}