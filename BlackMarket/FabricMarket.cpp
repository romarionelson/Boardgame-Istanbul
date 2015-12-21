#include "FabricMarket.h"
#define SMALL_MARKET_GAIN 6
#define SMALL_MARKET_FABRIC 3

FabricMarket::FabricMarket(void) : Tile() {
    type = FabricMarketType;
}

bool FabricMarket::action(Player& player) {

    if (player.fabric >= SMALL_MARKET_FABRIC) {
        player.gold += SMALL_MARKET_GAIN;
        player.fabric -= SMALL_MARKET_FABRIC;
        return true;
    }
    return false;
}

Tile* FabricMarket::clone() {
    return new FabricMarket();
}