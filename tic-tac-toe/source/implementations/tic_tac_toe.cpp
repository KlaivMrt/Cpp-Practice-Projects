#include "..\headers\tic_tac_toe.h"
#include "..\headers\exceptions.h"
#include <iostream>

using std::exception;
using std::cout;
using std::cin;
using std::endl;

namespace game
{
    // the formula to get the index : i = 3*r + r

void tic_tac_toe::get_players()
{
    current_player = & player1;
    for (int i {}; i < 2; ++i)
    {
        cout << "Player " << i + 1 << " type your name ";
        current_player -> set_name();

        do
        {
            try
            {
            cout << * current_player << " pick your sign (1: O, 2: X) ";
            current_player -> set_sign();
            break;
            }
            catch(const exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        } while (true);
        current_player = & player2;
        
    }
}

}
