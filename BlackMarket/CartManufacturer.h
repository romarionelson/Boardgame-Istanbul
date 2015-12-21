#pragma once
#include "tile.h"

class CartManufacturer :
public Tile {
public:
    CartManufacturer(void);
    bool action(Player&);
    Tile* clone();
};

