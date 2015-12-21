#pragma once
#include <iostream>
#include "Enums.h"
#include "Player.h"

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

using namespace std;

class Player;
static int ID=0;
class Tile {
	
private:
	int id;
	
protected:
    //type of the tile
    enum TileType type;
	
public:
    Tile();
    ~Tile();
    //performs action on a player

    virtual bool action(Player&) {
        return true;
    };
    //crates a copy of this tile

    virtual Tile* clone() {
        return new Tile();
    };
    //gets the tile name in string
    const string getTypeName();
    bool operator==(const Tile&);
    //writes a tile to file
    friend ostream& operator<<(ostream&, Tile&);
};
