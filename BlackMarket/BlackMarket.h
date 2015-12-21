#pragma once
#include "tile.h"
#include <stdlib.h>

class BlackMarket :
public Tile {
public:
    BlackMarket(void);
    bool action(Player&);
    Tile* clone();
};

