#include "FabricManufacture.h"
#define FABRIC_ROLLS 3
#define FABRIC_COST 2

FabricManufacture::FabricManufacture(void) : Tile() {
    type = FabricManufactureType;
}

bool FabricManufacture::action(Player& player) {

    if (player.gold >= FABRIC_COST) {
        player.fabric += MIN(player.cartCapacity(), FABRIC_ROLLS);
        player.gold -= FABRIC_COST;
        return true;
    }
    return false;
}

Tile* FabricManufacture::clone() {
    return new FabricManufacture();
}