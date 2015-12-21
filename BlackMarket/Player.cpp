#include "Player.h"
#include <iomanip>

#define RUBY_WINS 5
#define PAY_GOLD 1
#define MIN_GOLD 1

Player::Player() {
    gold = 5;
    ruby = 0;
    spices = 1;
    fabric = 1;
    jewel = 1;
    food = 10;
    cart = INIT_CAPACITY;
}

bool Player::canAct() const {
    return food >= MIN_GOLD;
}

void Player::eat() {
    if (canAct())
        food -= MIN_GOLD;
}

bool Player::pay(Player& player) {
    if (gold >= PAY_GOLD) {
        player.gold += PAY_GOLD;
        gold -= PAY_GOLD;
        return true;
    }
    return false;
}

unsigned int Player::cartCapacity() {
    return cart - ruby - spices - fabric - jewel;
}

bool Player::wins() {
    return ruby >= RUBY_WINS;
}

bool Player::operator==(const string& otherName) const {
    return name.compare(otherName) == 0;
}


bool Player::operator==(const Player& otherPlayer) const {
    return name.compare(otherPlayer.name) == 0;
}

ostream& operator<<(ostream& out, Player& player) {
    out << setw(10) << player.name;
	out << setw(2) << player.gold << " "<< setw(2) << player.food << " "<< setw(2) << player.jewel;
    out << setw(2) << " " << player.fabric << " " << setw(2) << player.spices << " "<< setw(2) << player.ruby;

    return out;
}

istream& operator>>(istream& in, Player& player) {
    in >> player.name >> player.gold >> player.food >> player.jewel;
    in >> player.fabric >> player.spices >> player.ruby;

    return in;
}
