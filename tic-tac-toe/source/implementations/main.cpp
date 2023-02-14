#include "..\headers\board.h"
#include "..\headers\person.h"
#include "..\headers\tic_tac_toe.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;


using game::Board;
using game::Person;
using game::tic_tac_toe;

void ko(int * ar)
{
    for (int i {}; i < 3; ++i)
    {
        ar[i] = 69;
    }
}

const char * error()
{
    return "ok";
}

int main()
{
    // int k[] {1, 2, 3};
    // ko(k);
    // for (int i : k)
    // {
    //     cout << i << " ";
    // }

    // cout << endl;
    // Board ok;
    // ok.display();
    // int k {ok.check()};   
    // cout << k;
    
    // int x {};
    // cin >> x;
    // cout << x << endl;

    // Board b;
    // b[1] = 1;
    // b.display();

    tic_tac_toe me;
    me.run();
}