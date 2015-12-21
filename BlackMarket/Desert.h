#pragma once
#include "Tile.h"

class Desert : public Tile {
public:
    bool action(Player&);
    Tile* clone();
};