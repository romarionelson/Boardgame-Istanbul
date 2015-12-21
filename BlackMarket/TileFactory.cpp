#include "TileFactory.h"

#include "Restaurant.h"
#include "SpiceMerchant.h"
#include "FabricManufacture.h"
#include "Jeweler.h"
#include "CartManufacturer.h"
#include "SmallMarket.h"
#include "SpiceMarket.h"
#include "JewelryMarket.h"
#include "FabricMarket.h"
#include "BlackMarket.h"
#include "Casino.h"
#include "GemMerchant.h"
#include "Palace.h"
#include "Desert.h"
#include <vector>

using namespace std;

#define PORTION 14

TileFactory::TileFactory(int _nTiles) {
    nTiles = _nTiles;
    Restaurants = 0;
    SpiceMerchants = 0;
    FabricManufactures = 0;
    Jewelers = 0;
    CartManufacturers = 0;
    SmallMarkets = 0;
    SpiceMarkets = 0;
    JewelryMarkets = 0;
    FabricMarkets = 0;
    BlackMarkets = 0;
    Casinos = 0;
    GemMerchants = 0;
    Palaces = 0;
    Deserts = 0;
}

TileFactory::~TileFactory(void) {
}

Tile* TileFactory::next() {

    //first add possible types into a list, add one desert for each other type(double the chance of getting desert)
    std::vector<TileType> possibleList;
    if (Restaurants < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(RestaurantType);
    }

    if (SpiceMerchants < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(SpiceMerchantType);
    }

    if (FabricManufactures < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(FabricManufactureType);
    }

    if (Jewelers < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(JewelerType);
    }

    if (CartManufacturers < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(CartManufacturerType);
    }

    if (SmallMarkets < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(SmallMarketType);
    }

    if (SpiceMarkets < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(SpiceMarketType);
    }

    if (JewelryMarkets < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(JewelryMarketType);
    }

    if (FabricMarkets < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(FabricMarketType);
    }

    if (BlackMarkets < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(BlackMarketType);
    }

    if (Casinos < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(CasinoType);
    }

    if (GemMerchants < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(GemMerchantType);
    }

    if (Palaces < nTiles / PORTION) {
        if (Deserts < nTiles - 13 * nTiles / PORTION) {
            possibleList.push_back(DesertType);
            possibleList.push_back(DesertType);
        }
        possibleList.push_back(PalaceType);
    }

    if (possibleList.size() == 0)
        possibleList.push_back(DesertType);
    //get random number
    int tile = rand() % (possibleList.size());
    //pick the radom tile
    TileType selectecTile = possibleList[tile];
    switch (selectecTile) {
        case RestaurantType:
            Restaurants++;
            return new Restaurant();
            break;
        case SpiceMerchantType:
            SpiceMerchants++;
            return new SpiceMerchant();
            break;
        case FabricManufactureType:
            FabricManufactures++;
            return new FabricManufacture();
            break;
        case JewelerType:
            Jewelers++;
            return new Jeweler();
            break;
        case CartManufacturerType:
            CartManufacturers++;
            return new CartManufacturer();
            break;
        case SmallMarketType:
            SmallMarkets++;
            return new SmallMarket();
            break;
        case SpiceMarketType:
            SpiceMarkets++;
            return new SpiceMarket();
            break;
        case JewelryMarketType:
            JewelryMarkets++;
            return new JewelryMarket();
            break;
        case FabricMarketType:
            FabricMarkets++;
            return new FabricMarket();
            break;
        case BlackMarketType:
            BlackMarkets++;
            return new BlackMarket();
            break;
        case CasinoType:
            Casinos++;
            return new Casino();
            break;
        case GemMerchantType:
            GemMerchants++;
            return new GemMerchant();
            break;
        case PalaceType:
            Palaces++;
            return new Palace();
            break;
        case DesertType:
            Deserts++;
            return new Desert();
            break;
    }
    return NULL;
}
