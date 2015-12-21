#pragma once
#include <string>
#include <iostream>
#include "tile.h"
#define INIT_CAPACITY 9
#define CAPACITY_GROWING 3

using namespace std;

class Tile;

class Player {
private:

public:
    std::string name;
    unsigned int gold;
    unsigned int ruby;
    unsigned int spices; // The number of sacks of spices.
    unsigned int fabric; // The number of rolls of fabric.
    unsigned int jewel; // The number of pieces of jewelry.
    unsigned int cart; // The capacity of the cart.
    unsigned int food; // The number of food items
    bool canAct() const; // returns true if food > 0
    //player pays gold to another player
    bool pay(Player& player);
    //returns the cart current empty capacity
    unsigned int cartCapacity();
    //player acts and eats a food portion
    void eat();

    Player();
    //return true if the user wins
    bool wins();
    //wirtes the player to a file
    friend ostream& operator<<(ostream&, Player&);
    //reads a player form file
    friend istream& operator>>(istream&, Player&);
    //compares a player to another player name
    bool operator==(const string&) const;
    //compares a player to another player name
    bool operator==(const Player&) const;

    void operator=(const Player &player) {
        gold = player.gold;
        ruby = player.ruby;
        spices = player.spices;
        fabric = player.fabric;
        jewel = player.jewel;
        cart = player.cart;
        food = player.food;
    }
};