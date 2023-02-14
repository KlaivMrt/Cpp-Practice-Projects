#ifndef PERSON
#define PERSON
#include <iostream>

using std::ostream;
using std::string;

namespace game
{

class Person
{
    private:
    char * name {nullptr};
    unsigned short sign;
    unsigned int score {0};

    public:
    // Constructors
    explicit Person() = default;

    // Destructors
    ~Person();

    // Member functions
    void set_name();
    void set_sign();
    void set_sign(int);
    unsigned short get_sign();
    void reset_score();

    // operators
    Person & operator++();
    const Person operator++(int);
    Person & operator=(const Person &) = delete;
    friend ostream & operator<<(ostream &, const Person &);
};

ostream & operator<<(ostream &, const Person &);

}

#endif