#pragma once
#include "tile.h"

class SpiceMerchant :
public Tile {
public:
    SpiceMerchant(void);
    bool action(Player&);
    Tile* clone();
};

