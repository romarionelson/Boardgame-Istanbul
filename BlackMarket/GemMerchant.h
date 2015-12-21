#pragma once
#include "tile.h"

class GemMerchant :
public Tile {
public:
    GemMerchant(void);
    bool action(Player&);
    Tile* clone();
};

