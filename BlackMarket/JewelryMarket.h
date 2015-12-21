#pragma once
#include "tile.h"

class JewelryMarket :
public Tile {
public:
    JewelryMarket(void);
    bool action(Player&);
    Tile* clone();
};

