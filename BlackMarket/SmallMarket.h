#pragma once
#include "tile.h"

class SmallMarket :
public Tile {
public:
    SmallMarket(void);
    bool action(Player&);
    Tile* clone();
};

