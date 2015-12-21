#pragma once
#include "tile.h"

class SpiceMarket :
public Tile {
public:
    SpiceMarket(void);
    bool action(Player&);
    Tile* clone();
};

