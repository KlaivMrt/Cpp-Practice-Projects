#include "..\headers\person.h"
#include "..\headers\exceptions.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using exceptions::exception;
using exceptions::out_of_bounds;

namespace game
{

// Destructor
Person::~Person()
{
    delete[] name;
}

// Memebr Functions

void Person::set_name() noexcept
{
    name = new char [11] {};
    cout << ">> >> ";
    cin.getline(name, 11);
    cout << endl;
    cin.clear();
}

void Person::set_sign()
{
    // do
    // {
        // try
        // {
            cout << ">> >> ";
            cin >> sign;
            cout << endl;
            cin.clear();
            if (sign != 1 && sign != 2) throw out_of_bounds {};
            // break;
        // }
    //     catch(const exception & e)
    //     {
    //         cout << e.what() << "\n try again" << endl;
    //     }
        
    // } while(true);
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
