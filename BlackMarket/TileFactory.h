#pragma once
#include "Tile.h"

class TileFactory {
private:
    int nTiles;
    TileFactory(int);

    //list of how many tiles of each type has been generated so far
    int Restaurants;
    int SpiceMerchants;
    int FabricManufactures;
    int Jewelers;
    int CartManufacturers;
    int SmallMarkets;
    int SpiceMarkets;
    int JewelryMarkets;
    int FabricMarkets;
    int BlackMarkets;
    int Casinos;
    int GemMerchants;
    int Palaces;
    int Deserts;

public:

    ~TileFactory(void);

    static TileFactory *get(int _nTiles) {
        static TileFactory tf(_nTiles);
        return &tf;
    }
    //creates a new tile
    Tile* next();
};

