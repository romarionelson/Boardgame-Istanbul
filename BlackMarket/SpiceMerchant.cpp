#include "SpiceMerchant.h"
#define SPICE_SACKS 3
#define SPICE_COST 2

SpiceMerchant::SpiceMerchant(void) : Tile() {
    type = SpiceMerchantType;
}

bool SpiceMerchant::action(Player& player) {

    if (player.gold >= SPICE_COST) {
        player.spices += MIN(player.cartCapacity(), SPICE_SACKS);
        player.gold -= SPICE_COST;
        return true;
    }
    return false;
}

Tile* SpiceMerchant::clone() {
    return new SpiceMerchant();
}