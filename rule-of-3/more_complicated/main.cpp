#include "person.hpp"

#include <iostream>

// More complicated example with 2 dynamic class variables
// Warning: It's bad practice to keep a lot of raw pointers in your class
int main(int argc, char *argv[])
{
    {
        Person julia("Julia", "Roberts", 20);
        Person julia_copy(julia);
        Person natasha("Natasha", "Williams", 30);
        julia = natasha;
    }

    std::cout << "End of main() :(" << std::endl;
}