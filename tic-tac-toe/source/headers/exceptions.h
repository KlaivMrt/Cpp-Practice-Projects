#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <string>

using std::string;

namespace exceptions
{

class exception
{
    protected:
    const char * message {nullptr};

    public:
    explicit exception() noexcept = default;
    explicit exception(char *);
    explicit exception(string);
    virtual ~exception() = default;
    virtual const char * what() const noexcept;
};

class out_of_bounds : public exception
{
    public:
    explicit out_of_bounds();
    explicit out_of_bounds(char *);
    explicit out_of_bounds(string);
    const char * what() const noexcept override;
};

class negative_parameter : public exception
{
    public:
    explicit negative_parameter();
    explicit negative_parameter(char *);
    explicit negative_parameter(string);
    const char * what() const noexcept override;
};

}

#endif