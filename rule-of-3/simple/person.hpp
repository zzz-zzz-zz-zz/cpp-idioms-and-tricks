#ifndef _ZZZ_PERSON_SIMPLE
#define _ZZZ_PERSON_SIMPLE

#include <string.h>
#include <iostream>

// RULE OF 3:
// if you need 1 of those: copy constructor | copy assign operator | destructor
// you probably need 3 of them
// if you manage resource with new/delete - you need them 100%

class Person
{
public:
    Person(const char*, int);
    Person(const Person &); // copy constructor

    Person& operator=(const Person &); // copy assign operator

    static void status() { std::cout << "Persons in town: " << amount << std::endl; }

    ~Person(); // destructor
private:
    char *name;
    int age;

    static int amount; // Don't need in real program.
};




#endif // _PERSON_SIMPLE