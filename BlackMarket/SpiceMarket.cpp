#include "SpiceMarket.h"
#define SMALL_MARKET_GAIN 6
#define SMALL_MARKET_SPICE 3

SpiceMarket::SpiceMarket(void) : Tile() {
    type = SpiceMarketType;
}

bool SpiceMarket::action(Player& player) {

    if (player.spices >= SMALL_MARKET_SPICE) {
        player.gold += SMALL_MARKET_GAIN;
        player.spices -= SMALL_MARKET_SPICE;
        return true;
    }
    return false;
}

Tile* SpiceMarket::clone() {
    return new SpiceMarket();
}