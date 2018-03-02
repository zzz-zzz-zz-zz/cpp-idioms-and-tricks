#include <iostream>

#include "all.hpp"


int main()
{
    // Note: EmptyFieldException declared in all.hpp

    Update upd;
    try 
    {
        std::cout << upd.get_message().get_text() << std::endl;
    }
    catch (EmptyFieldException &e)
    {
        std::cout << e.what() << std::endl;
    }

    Update upd2("Hello world!");
    try
    {
        std::cout << upd2.get_message().get_text() << std::endl;
    }
    catch (EmptyFieldException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}