#include "person.hpp"

#include <iostream>


int main(void)
{
    {
        Person julia("Julia", 20);
        Person julia_copy(julia);

        Person irina("Irina", 40);
        irina = julia_copy;
    }
    std::cout << "-----------------" << std::endl;

    Person::status();
    std::cout << "End of main() :(" << std::endl;
    
}