#include "..\headers\person.h"
#include "..\headers\exceptions.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using exceptions::exception;
using exceptions::out_of_bounds;
using exceptions::negative_parameter;

namespace game
{

// Destructor
Person::~Person()
{
    delete[] name;
}

// Memebr Functions

void Person::set_name()
{
    name = new char [11] {};
    cout << ">> >> ";
    cin.getline(name, 11);
    cin.clear();
}

void Person::set_sign()
{
    cout << ">> >> ";
    cin >> sign;
    cin.ignore();
    if (sign != 1 && sign != 2) throw out_of_bounds {};
}

void Person::set_sign(int n_sign)
{
    // if (n_sign < 1) throw negative_parameter {};
    sign = static_cast<unsigned short>(n_sign);
}

unsigned short Person::get_sign()
{
    return sign;
}

// Operators

Person & Person::operator++()
{
    ++score;
    return * this;
}

const Person Person::operator++(int)
{
    Person copy {* this};
    ++score;
    return copy;
}

ostream & operator<<(ostream & stream, const Person & person)
{
    stream << person.name << " --score: " << person.score << "--";
    return stream;
}

}
