#pragma once
#include "tile.h"

class FabricMarket :
public Tile {
public:
    FabricMarket(void);
    bool action(Player&);
    Tile* clone();
};

