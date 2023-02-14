#ifndef BOARD
#define BOARD

namespace game
{

class Board
{

    private:
    unsigned short grid[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int partition(unsigned short *, int, int);
    void q_sort(unsigned short *, int, int);

    public:
    // Member Functions
    void reset_grid() noexcept;
    void display();
    unsigned short check();

    //Operator overloads
    unsigned short & operator[](unsigned int);

};

}

#endif