#include "JewelryMarket.h"
#define SMALL_MARKET_GAIN 6
#define SMALL_MARKET_JEWEL 3

JewelryMarket::JewelryMarket(void) : Tile() {
    type = JewelryMarketType;
}

bool JewelryMarket::action(Player& player) {

    if (player.jewel >= SMALL_MARKET_JEWEL) {
        player.gold += SMALL_MARKET_GAIN;
        player.jewel -= SMALL_MARKET_JEWEL;
        return true;
    }
    return false;
}

Tile* JewelryMarket::clone() {
    return new JewelryMarket();
}