#pragma once
#include "tile.h"

class Restaurant :
public Tile {
public:
    Restaurant(void);
    bool action(Player&);
    Tile* clone();
};

