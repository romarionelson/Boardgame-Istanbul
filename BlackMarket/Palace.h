#pragma once
#include "tile.h"

class Palace :
public Tile {
public:
    Palace(void);
    bool action(Player&);

    Tile* clone();
};

