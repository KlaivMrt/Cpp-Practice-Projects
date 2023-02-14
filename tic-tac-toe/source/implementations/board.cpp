#include "..\headers\board.h"
#include <iostream>

using game::Board;
using std::cout;
using std::cin;
using std::endl;

namespace game
{

// Member Function

void Board::reset_grid() noexcept
{
    for (unsigned short i : grid)
    {
        i = 0;
    }
}

void Board::display()
{
    for (int i {}; i < 9; ++i)
    {
        cout << (grid[i] == 0 ? " + " : (grid[i] == 1 ? " X " : " O "));
        if ((i + 1) % 3 == 0) cout << endl;
    }
}

int Board::partition(unsigned short * array, int low, int high)
{
    unsigned short x = array[high];
    int i = low - 1;
    unsigned short swap;

    for (int j = low; j <= high - 1; ++j)
    {
        if(array[j] >= x)
        {
            ++i;
            swap = array[j];
            array[j] = array[i];
            array[i] = swap;
        }
    }
    swap = array[i + 1];
    array[i + 1] = array[high];
    array[high] = swap;

    return i + 1;
}

void Board::q_sort(unsigned short * array, int low, int high)
{
    if (low < high)
    {
        int part {partition(array, low, high)};
        q_sort(array, low, part - 1);
        q_sort(array, part + 1, high);
    }
}
 
unsigned short Board::check()
{
    if (grid[0] == grid[4] && grid[4] == grid[8]) return grid[0];
    if (grid[2] == grid[4] && grid[4] == grid[5]) return grid[2];
    if (grid[0] == grid[1] && grid[1] == grid[2]) return grid[0];
    if (grid[3] == grid[4] && grid[4] == grid[5]) return grid[3];
    if (grid[6] == grid[7] && grid[7] == grid[8]) return grid[6];
    if (grid[0] == grid[3] && grid[3] == grid[6]) return grid[0];
    if (grid[1] == grid[4] && grid[4] == grid[7]) return grid[1];
    if (grid[2] == grid[5] && grid[5] == grid[8]) return grid[2];
    return 0;
}

//Operator Oveloads

unsigned short & Board::operator[](unsigned int index)
{
    return grid[index];
}

}