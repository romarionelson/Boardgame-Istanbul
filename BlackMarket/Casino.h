#pragma once
#include "tile.h"
#include <stdlib.h>

class Casino :
public Tile {
public:
    Casino(void);
    bool action(Player&);
    Tile* clone();
};

