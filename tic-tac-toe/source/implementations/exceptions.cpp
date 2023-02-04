#include "..\headers\exceptions.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

namespace exceptions
{

// exception
// Constructors

exception::exception(char * msg) : message {msg}
{}

exception::exception(string msg) : message {msg.c_str()}
{}

// Member functions

const char * exception::what() const noexcept
{
    return message;
}

// Destructor

exception::~exception()
{
    delete[] message;
}

// out_of_bounds
// Constructors

out_of_bounds::out_of_bounds()
{
    message = "input is out of bounds";
}

out_of_bounds::out_of_bounds(char * msg) :  exception {msg}
{}

// Memebr functions

const char * out_of_bounds::what() const noexcept
{
    return message;
}

}