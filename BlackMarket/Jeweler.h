#pragma once
#include "tile.h"

class Jeweler :
public Tile {
public:
    Jeweler(void);
    bool action(Player&);
    Tile* clone();
};

