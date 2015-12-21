#include "SmallMarket.h"
#define SMALL_MARKET_GAIN 8
#define SMALL_MARKET_FABRIC 1
#define SMALL_MARKET_JEWEL 1
#define SMALL_MARKET_SPICE 1

SmallMarket::SmallMarket(void) : Tile() {
    type = SmallMarketType;
}

bool SmallMarket::action(Player& player) {

    if (player.spices >= SMALL_MARKET_SPICE &&
            player.jewel >= SMALL_MARKET_JEWEL &&
            player.fabric >= SMALL_MARKET_FABRIC) {
        player.gold += SMALL_MARKET_GAIN;

        player.spices -= SMALL_MARKET_SPICE;
        player.jewel -= SMALL_MARKET_JEWEL;
        player.fabric -= SMALL_MARKET_FABRIC;

        return true;
    }
    return false;
}

Tile* SmallMarket::clone() {
    return new SmallMarket();
}