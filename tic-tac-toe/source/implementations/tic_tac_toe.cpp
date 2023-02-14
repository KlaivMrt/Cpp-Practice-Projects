#include "..\headers\tic_tac_toe.h"
#include "..\headers\exceptions.h"
#include <iostream>

using exceptions::exception;
using exceptions::out_of_bounds;
using std::cout;
using std::cin;
using std::endl;

namespace game
{
    // the formula to get the index : i = 3*r + c

void tic_tac_toe::get_players()
{
    cout << "Player " << 1 << " type your name ";
    player1.set_name();
    cout << player1 << " pick your sign (1: X, 2: O) ";

    while(true)
    {
        try{
            player1.set_sign();
            break;
        }catch (exception & exc){
            cout << exc.what() << "\ntry again" << endl;
        }
    }

    cout << "Player " << 2 << " type your name ";
    player2.set_name();

    if (player1.get_sign() == 1)
    {
        player2.set_sign(2);
    }else
    {
        player2.set_sign(1);
    }
}

int tic_tac_toe::get_position()
{
    int position;
    cout << ">> >> "; 
    cin >> position;
    cin.clear();
    if (position > 3 || position < 1) throw out_of_bounds {};
    return position;
}

int tic_tac_toe::get_index()
{
    int index;
    int row;
    int column;
    while (true)
    {
        try
        {
            cout << * current_player << " type row >> ";
            row = get_position();
            break;
        }
        catch(exception & exc)
        {
            cout << exc.what() << "\ntry again (row)" << endl;
            cout << endl;
        }
    }
    
    while (true)
    {
        try
        {
            cout << * current_player << " type column >> ";
            column = get_position();
            break;
        }
        catch(exception & exc)
        {
            cout << exc.what() << "\ntry again (column)" << endl;
            cout << endl;
        }
        
    }
    
    index = 3 * (row - 1) + (column - 1);
    return index;
}

void tic_tac_toe::run()
{
    int replay = 1;
    do
    {
        unsigned short check;
        get_players();
        while (check == 0)
        {
            if(current_player == & player2)
            {
                current_player = & player1;
            }else
            {
                current_player = & player2;
            }

            while (true)
            {
                int index = get_index();
                if (board[index]){
                    cout << "position occupied, try again" << endl;
                    cout << endl;
                    continue;
                }
                board[index] = current_player -> get_sign();
                board.display();
                cout << endl;
                break;
            }
            
            check = board.check();
        }
        
        ++(* current_player);
        cout << player1 << endl;
        cout << player2 << endl;

        cout << "Replay? (type any key for yes, 0 for no) >> ";
        cin >> replay;
        cout << replay << endl;
        board.reset_grid();
    } while (replay);
    
}

}
