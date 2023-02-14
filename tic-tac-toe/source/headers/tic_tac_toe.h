#ifndef TICTACTOE
#define TICTACTOE

#include ".\board.h"
#include ".\person.h"
#include <iostream>

using game::Person;
using game::Board;
using std::cout;
using std::cin;
using std::endl;

namespace game
{

class tic_tac_toe
{
    private:
    Board board;
    Person player1;
    Person player2;
    Person * current_player = & player2;
    void get_players();
    int get_position();
    int get_index();

    public:

    void run();

};

}
#endif