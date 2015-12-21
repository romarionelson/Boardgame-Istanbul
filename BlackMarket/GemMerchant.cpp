#include "GemMerchant.h"
#define GEM_MINGOLD 12

GemMerchant::GemMerchant(void) : Tile() {
    type = GemMerchantType;
}

bool GemMerchant::action(Player& player) {

    if (player.gold < player.ruby + GEM_MINGOLD)
        return false;
    player.gold -= player.ruby + GEM_MINGOLD;
    player.ruby++;
    return true;
}

Tile* GemMerchant::clone() {
    return new GemMerchant();
}