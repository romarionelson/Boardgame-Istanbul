#include "TileFactory.h"
#include "GameBoard.h"
#include <time.h> 
#include <iostream>
#include "stdio.h"
#include <fstream>

#define EXP_PAUSE 19
#define BOARD_ROWS 6
#define BOARD_COLS 6
#define FILE_NAME "game.dat"


bool takeTurn(GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS>&, const std::string&);
Move getMove(const std::string&, GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS>&);
bool takeAction();
void saveGame(GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS>&);
bool loadGame(GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS>&);

int main(int argc, char** argv) {
    //init random generator wiht new seed
    srand(time(NULL));
    //get players coutn from input
    int players = 1;
	cout << "Please Enter the players count:";
	cin >> players;
	cin.ignore();
    //list of players name
    vector<string> playerNames;
    //create a board game
    GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS> bg(players);
    //read game from file
    //if read is not successful read all values from user input
    if (!loadGame(bg)) {
        //create a tile factory
        TileFactory *tf = TileFactory::get(BOARD_ROWS * BOARD_COLS);
        //add tiles to boards
        for (int i = 0; i < BOARD_ROWS; i++) {
            for (int j = 0; j < BOARD_COLS; j++) {
                Tile* tile = tf->next();
                bg.add(tf->next(), i, j);
            }
        }
        //show board
        bg.printBoard();
        //enter user names
        for (int i = 0; i < players; i++) {
            cout << "Please enter a user name #" << i << ":";
            //create new user
            Player* player = new Player();
            cin >> player->name;
            //add user to the list
            bg.add(*player);
            playerNames.push_back(player->name);
        }
    } else {
        //board is read from the file now fill the players names list
        vector<Player> playersList = bg.getAllPlayers();
        //show board
        cout << "This is the board game tiles" << endl;
        bg.printBoard();
        cout << endl << endl;

        for (auto player : playersList) {
            playerNames.push_back(player.name);
        }
    }
    //while not paused
    bool running = true;
    while (running) {
        try {
            for (auto playerName : playerNames) {
                //for ( auto pName : playerNames ) {
                do {
                    //get player and his current tile position
                    Player player = bg.getPlayer(playerName);
                    //show user stat
                    cout << "Name      " << "Go Fo Je Fa Sp Ru " << endl;
                    cout << player << endl;
                } while (!takeTurn(bg, playerName));
                //end game if user wins
                if (bg.win(playerName)) {
                    cout << "Player " << playerName << " won the game!";
                    cin.clear();
                    return 0;
                }
            }
        } catch (int exp) {
            if (exp == EXP_PAUSE) {
                cout << "Game paused";
                cin.clear();
                running = false;
            }
        }

    }
    if (!running)
        saveGame(bg);
    return 0;
}


//saves the game to a file

void saveGame(GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS>& bg) {
    //deletes currently saved file
    remove(FILE_NAME);
    //open the file
    ofstream out(FILE_NAME);
    if (out.is_open()) {
        //save the game
        out << bg;
        //close the file
        out.close();
    }
}


//reads game from file and returns true if it succeeds

bool loadGame(GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS>& bg) {
    //open the game file if ay
    ifstream in(FILE_NAME);
    if (in.is_open()) {
        //read game from the file
        in >> bg;
        in.close();
        return true;
    }
    return false;
}


//lets a player to play

bool takeTurn(GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS>& bg, const std::string& playerName) {
    //show user on the board by ** on the tile he is currently in
    int row, col;
    //get the player from the board
    Player player = bg.getPlayer(playerName);
    //get users current location in order to be shown on the board
    bg.getCoordinate(bg.getTile(playerName), &row, &col);
    //print the board with user loation marked with **
    bg.printBoard(row, col);
    //get player and his move
    Move m = getMove(playerName, bg);
    //make move
    Tile t = bg.move(m, playerName);
    //see if user can act
    if (player.canAct()) {
        //ask user for taking action or not
        if (takeAction()) {
            //pay to current users in this tile
            std::vector<Player> opL = bg.getPlayers(t);
            //if player have anough gold, pay others and make action
            if (player.gold >= opL.size()) {
                player.eat();
                for (auto otherPlayer : opL) {
                    player.pay(otherPlayer);
                    bg.setPlayer(otherPlayer);
                }
                //make action
				bg.getTilePointer(t)->action(player);
                bg.setPlayer(player); //not sure what for?
                //update user stat
                cout << "Name      " << "Go Fo Je Fa Sp Ru" << endl;
                cout << player << endl << endl << endl;
            }
        } else
            cout << "No action is performed by the user" << endl;
    }
    return true;

}

//get move from input or pause
//possible moves are shown based on the user current location

Move getMove(const std::string& playerName, GameBoard<Tile, Player, BOARD_ROWS, BOARD_COLS>& bg) {
    //get tile coordinates to show the right possible moves
    int row, col;
    bg.getCoordinate(bg.getTile(playerName), &row, &col);
    while (true) {
        cout << "Enter a valid move fro the list[" << (row == 0 ? "" : " U(UP)") << (row == BOARD_ROWS - 1 ? "" : " D(DOWN)") << (col == 0 ? "" : " L(LEFT)") << (col == BOARD_COLS - 1 ? "" : " R(RIGHT)") << " P(Pause) ]";
        char text;
        if (cin >> text) {
            if ((text == 'd' || text == 'D') && row != BOARD_ROWS - 1) {
                return MoveDown;
            } else if ((text == 'u' || text == 'U') && row != 0) {
                return MoveUp;
            } else if ((text == 'l' || text == 'L') && col != 0) {
                return MoveLeft;
            } else if ((text == 'r' || text == 'R') && col != BOARD_COLS - 1) {
                return MoveRight;
            } else if ((text == 'p' || text == 'P')) {
                throw EXP_PAUSE;
            } else
                cout << "Wrong move...\n";
        }
    }
}

//get action from input or pause

bool takeAction() {
    char text;
    while (true) {
        cout << "Do you want to act?[Y(Yes)  N(No) P(PAUSE)]:";
        cin>>text;
        if (text == 'Y' || text == 'y')
            return true;
        else if (text == 'N' || text == 'n')
            return false;
        else if ((text == 'p' || text == 'P'))
            throw EXP_PAUSE;
        else
            cout << "Wrong Selection...\n";
    }
}