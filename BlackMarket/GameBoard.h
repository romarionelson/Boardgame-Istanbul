#pragma once

#include <vector>
#include <string>
#include "Player.h"


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


#define EXP_OUTOFRANGE 20

//define movement enums
enum Move : int {
    MoveUp = 1, MoveRight, MoveDown, MoveLeft
};

using namespace std;

template <class T, class J, const int R, const int C>
class GameBoard {
private:
    //list of players in the game
    vector<J> _players;
    //location of each player in the game
    vector<int*> _playersLocation;
    //list of tiles in a 2D array
    //to the rest of the file , _tiles is used as a 1d array inorder to solve the referencing problem
    T** _tiles;
public:

    GameBoard(int);
    ~GameBoard(void);
    //add tile at the posirion of row and column
    void add(T*, int, int);
    //adds a player to the players list
    void add(const J&);
    //gets the desired location
    const T& getTile(int, int) const;
    //gets coordinate of a tile in the board
    void getCoordinate(const T &, int *, int *) const;
    //?????
    void setPlayer(J);
    //gets a player by his name
    J getPlayer(const std::string&);
    //checks to see if the player has won the game
    bool win(const std::string&);
    //get the current tile of the player
    const T& getTile(const std::string&) const;
	T* getTilePointer(const T&);
    //get the list of all players in a certain tile
    std::vector<J> getPlayers(const T&) const;
    //gets all the players in the game when reading board from file
    vector<J> getAllPlayers();
    
    //moves the player to a new tile
    const T& move(Move, const std::string&);
    //prints the board to the output
    void printBoard();
    //print the board to the output but displats ** fot the row and col specified
    void printBoard(int, int);

    //saves board to a file

    friend ostream& operator<<(ostream& os, const GameBoard<T, J, R, C>& bg) {
        os << bg._players.size() << "\n";
        //first save the tiles
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; j++) {
                os << *bg._tiles[i * R + j] << " ";
            }
        }
        //just put extra line for file formatting
        os << "\n";
        //now save each players info and location
        int i = 0;
        for (J player : bg._players) {
            os << player << " " << bg._playersLocation[i][0] << " " << bg._playersLocation[i][1] << "\n";
            i++;
        }
        return os;
    }

    //read board from file

    friend istream& operator>>(istream& is, GameBoard<T, J, R, C>& bg) {
        int playerNumber = 0;
        is >> playerNumber;
        //first read the tiles
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; j++) {
                int type;
                is >> type;
                switch ((Move) type) {
                    case RestaurantType:
                        bg._tiles[i * R + j] = new Restaurant();
                        break;
                    case SpiceMerchantType:
                        bg._tiles[i * R + j] = new SpiceMerchant();
                        break;
                    case FabricManufactureType:
                        bg._tiles[i * R + j] = new FabricManufacture();
                        break;
                    case JewelerType:
                        bg._tiles[i * R + j] = new Jeweler();
                        break;
                    case CartManufacturerType:
                        bg._tiles[i * R + j] = new CartManufacturer();
                        break;
                    case SmallMarketType:
                        bg._tiles[i * R + j] = new SmallMarket();
                        break;
                    case SpiceMarketType:
                        bg._tiles[i * R + j] = new SpiceMarket();
                        break;
                    case JewelryMarketType:
                        bg._tiles[i * R + j] = new JewelryMarket();
                        break;
                    case FabricMarketType:
                        bg._tiles[i * R + j] = new FabricMarket();
                        break;
                    case BlackMarketType:
                        bg._tiles[i * R + j] = new BlackMarket();
                        break;
                    case CasinoType:
                        bg._tiles[i * R + j] = new Casino();
                        break;
                    case GemMerchantType:
                        bg._tiles[i * R + j] = new GemMerchant();
                        break;
                    case PalaceType:
                        bg._tiles[i * R + j] = new Palace();
                        break;
                    case DesertType:
                        bg._tiles[i * R + j] = new Desert();
                        break;
                }
            }
        }
        //now read each player
        for (int i = 0; i < playerNumber; i++) {
            //read user info from file
            Player* player = new Player();
            is >> *player;
            // add use to the game
            bg.add(*player);
            //read user location on the board
            is >> bg._playersLocation[i][0];
            is >> bg._playersLocation[i][1];
        }
        return is;
    }

};

template <class T, class J, const int R, const int C>
GameBoard<T, J, R, C>::GameBoard(int players) {
    //create a 2D array of tiles
    _tiles = new T*[R];
    for (int i = 0; i < R; i++)
        _tiles[i] = new T[C];
}

template <class T, class J, const int R, const int C>
GameBoard<T, J, R, C>::~GameBoard(void) {
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::add(T* tile, int row, int col) {
    if (row < 0 || col < 0 || row > R || col > C)
        throw EXP_OUTOFRANGE;
    _tiles[row * R + col] = tile;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::add(const J& player) {
    _players.push_back(player);
    //add a location for this player in the location list
	_playersLocation.push_back(new int[2]);
	_playersLocation[_playersLocation.size()-1][0]=0;
	_playersLocation[_playersLocation.size()-1][1]=0;
}

template <class T, class J, const int R, const int C>
 T* GameBoard<T, J, R, C>::getTilePointer(const T &tile)  {
   for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; j++) {
            if (*_tiles[i * R + j] == tile) {
				return _tiles[i * R + j];
			}
		}
   }
    throw EXP_OUTOFRANGE;
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::getTile(int row, int col) const {
    if (row < 0 || col < 0 || row > R || col > C)
        throw EXP_OUTOFRANGE;
    return *_tiles[row * R + col];
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::getCoordinate(const T &tile, int *row, int *col) const {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; j++) {
            if (*_tiles[i * R + j] == tile) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
    throw EXP_OUTOFRANGE;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::setPlayer(J player) {
    //find the player and his location in the game
    for (int i = 0; i < _players.size(); i++) {
        if (_players[i] == player) {
            _players[i] = player;
            return;
        }
    }
     throw EXP_OUTOFRANGE;
}

template <class T, class J, const int R, const int C>
J GameBoard<T, J, R, C>::getPlayer(const std::string& playerName) {
    int i = 0;
    for (; i < _players.size(); i++) {
        if (_players[i] == playerName)
            return _players[i];
    }
    throw EXP_OUTOFRANGE;
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::getTile(const std::string& playerName) const {

    //find the player and his location in the game
    for (int i = 0; i < _players.size(); i++) {
        if (_players[i] == playerName) {
            return getTile(_playersLocation[i][0], _playersLocation[i][1]);
        }
    }

    throw EXP_OUTOFRANGE;
}

template <class T, class J, const int R, const int C>
bool GameBoard<T, J, R, C>::win(const std::string& playerName) {
    return getPlayer(playerName).wins();
}

template <class T, class J, const int R, const int C>
std::vector<J> GameBoard<T, J, R, C>::getPlayers(const T& tile) const {

    //find the location of the tile
    int row, col;
    getCoordinate(tile, &row, &col);
    std::vector<J> list;
    //find the players with the same location
    for (int i = 0; i < _playersLocation.size(); i++)
        if (_playersLocation[i][0] == row && _playersLocation[i][1] == col)
            list.push_back(_players[i]);

    return list;
}

template <class T, class J, const int R, const int C>
vector<J> GameBoard<T, J, R, C>::getAllPlayers() {
    return _players;
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::move(Move _move, const std::string& playerName) {
    //find current tile location
    int row, col;
    getCoordinate(getTile(playerName), &row, &col);
    //make the move
    switch (_move) {
        case MoveDown:
            row++;
            break;
        case MoveUp:
            row--;
            break;
        case MoveLeft:
            col--;
            break;
        case MoveRight:
            col++;
            break;
    }

    //set the players location
    int i = 0;
    for (; i < _players.size(); i++) {
        if (_players[i] == playerName) {
            _playersLocation[i][0] = row;
            _playersLocation[i][1] = col;
        }
    }

    return getTile(row, col);
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::printBoard() {

    //header of the board
    cout << "=";
    for (int j = 0; j < C; j++) {
        if (j == C - 1)
            cout << "===";
        else
            cout << "===";
    }
    cout << "\n";
    //tiles
    for (int i = 0; i < R; ++i) {
        cout << "|";
        for (int j = 0; j < C; j++) {
            cout << _tiles[i * R + j]->getTypeName() << "|";
        }
        cout << "\n";
        if (i != R - 1) {
            cout << "|";
            for (int j = 0; j < C; j++) {
                if (j == C - 1)
                    cout << "==|";
                else
                    cout << "==+";
            }
            cout << "\n";
        }

    }
    //tail of the board
    cout << "=";
    for (int j = 0; j < C; j++) {
        cout << "===";
    }
    cout << "\n";
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::printBoard(int row, int col) {

    //header of the board
    cout << "=";
    for (int j = 0; j < C; j++) {
        if (j == C - 1)
            cout << "===";
        else
            cout << "===";
    }
    cout << "\n";
    //tiles with ** in the row:col location
    for (int i = 0; i < R; ++i) {
        cout << "|";
        for (int j = 0; j < C; j++) {
            if (i == row && j == col)
                cout << "**|";
            else
                cout << _tiles[i * R + j]->getTypeName() << "|";
        }
        cout << "\n";
        if (i != R - 1) {
            cout << "|";
            for (int j = 0; j < C; j++) {
                if (j == C - 1)
                    cout << "==|";
                else
                    cout << "==+";
            }
            cout << "\n";
        }

    }
    //tail
    cout << "=";
    for (int j = 0; j < C; j++) {
        cout << "===";
    }
    cout << "\n";
}
