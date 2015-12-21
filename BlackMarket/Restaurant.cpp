#include "Restaurant.h"
#define RESTAURANT_GAIN 10

Restaurant::Restaurant(void) : Tile() {
    type = RestaurantType;
}

bool Restaurant::action(Player& player) {

    player.food = RESTAURANT_GAIN;
    return true;
}

Tile* Restaurant::clone() {
    return new Restaurant();
}