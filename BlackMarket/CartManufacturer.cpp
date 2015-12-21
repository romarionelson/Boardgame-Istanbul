#include "CartManufacturer.h"
#define CART_COUNT 3
#define CART_COST 7

CartManufacturer::CartManufacturer(void) : Tile() {
    type = CartManufacturerType;
}

bool CartManufacturer::action(Player& player) {

    if (player.gold >= CART_COST) {
        player.cart += CART_COUNT;
        player.gold -= CART_COST;
        return true;
    }
    return false;
}

Tile* CartManufacturer::clone() {
    return new CartManufacturer();
}