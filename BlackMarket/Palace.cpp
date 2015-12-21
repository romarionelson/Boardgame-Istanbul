#include "Palace.h"
#define PALACE_GAIN 1
#define PALACE_FABRIC_COST 5
#define PALACE_JEWEL_COST 5
#define PALACE_SPICE_COST 5

Palace::Palace(void) : Tile() {
    type = PalaceType;
}

bool Palace::action(Player& player) {

    if (player.spices < PALACE_SPICE_COST ||
            player.jewel < PALACE_JEWEL_COST ||
            player.fabric < PALACE_FABRIC_COST)
        return false;

    player.spices -= PALACE_SPICE_COST;
    player.jewel -= PALACE_JEWEL_COST;
    player.fabric -= PALACE_FABRIC_COST;
    player.ruby++;
    return true;
}

Tile* Palace::clone() {
    return new Palace();
}