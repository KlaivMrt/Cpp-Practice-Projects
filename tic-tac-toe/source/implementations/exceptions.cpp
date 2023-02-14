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

//negtive_parameter
//Constructors

negative_parameter::negative_parameter()
{
    message = "negative argument provided in positive paremeter";
}

negative_parameter::negative_parameter(char * msg) : exception (msg)
{}

negative_parameter::negative_parameter(string msg) : exception (msg.c_str())
{}

const char * negative_parameter::what() const noexcept
{
    return message;
}

}