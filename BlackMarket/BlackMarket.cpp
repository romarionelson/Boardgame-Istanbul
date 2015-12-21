#include "BlackMarket.h"
#define BLACKMARKET_MAXCOUNT 5
#define BLACKMARKET_COST 1
#define BLACKMARKET_GOODCOUNT 4

BlackMarket::BlackMarket(void) : Tile() {
    type = BlackMarketType;
}

bool BlackMarket::action(Player& player) {

    if (BLACKMARKET_COST < player.gold)
        return false;
    player.gold--;
    unsigned int goodType = rand() % BLACKMARKET_GOODCOUNT;
    unsigned int goodCount = rand() % (BLACKMARKET_MAXCOUNT + 1);

    if (goodType == 0)
        player.fabric = MIN(player.cartCapacity(), goodCount);
    else if (goodType == 1)
        player.jewel = MIN(player.cartCapacity(), goodCount);
    else if (goodType == 2)
        player.ruby = MIN(player.cartCapacity(), goodCount);
    else
        player.spices = MIN(player.cartCapacity(), goodCount);
    return true;
}

Tile* BlackMarket::clone() {
    return new BlackMarket();
}
