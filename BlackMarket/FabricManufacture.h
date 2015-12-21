#pragma once
#include "tile.h"

class FabricManufacture :
public Tile {
public:
    FabricManufacture(void);
    bool action(Player&);
    Tile* clone();
};

