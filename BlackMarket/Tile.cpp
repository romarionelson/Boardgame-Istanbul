#include "Tile.h"

Tile::Tile() {
    type = DesertType;
	id=ID++;
}

Tile::~Tile() {
}

bool Tile::operator==(const Tile& tile) {
	return id == tile.id;
}

ostream& operator<<(ostream& out, Tile& tile) {
    out << tile.type;
    return out;
}

const string Tile::getTypeName() {
    switch (type) {
        case RestaurantType:
            return "RE";
            break;
        case SpiceMerchantType:
            return "SP";
            break;
        case FabricManufactureType:
            return "FA";
            break;
        case JewelerType:
            return "JE";
            break;
        case CartManufacturerType:
            return "CA";
            break;
        case SmallMarketType:
            return "MA";
            break;
        case SpiceMarketType:
            return "SM";
            break;
        case JewelryMarketType:
            return "JM";
            break;
        case FabricMarketType:
            return "FM";
            break;
        case BlackMarketType:
            return "BM";
            break;
        case CasinoType:
            return "CA";
            break;
        case GemMerchantType:
            return "GE";
            break;
        case PalaceType:
            return "PA";
            break;
        case DesertType:
            return "DE";
            break;
    }

    return "";
}

