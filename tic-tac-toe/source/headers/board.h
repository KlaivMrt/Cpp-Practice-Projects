#ifndef BOARD
#define BOARD

namespace game
{

class Board
{

    private:
    unsigned short grid[9] {1, 0, 1, 2, 0, 2, 2, 1, 0};
    int partition(unsigned short *, int, int);
    void q_sort(unsigned short *, int, int);

    public:
    // Member Functions
    void reset_grid() noexcept;
    void display();
    unsigned short check();

};

}

#endif