#ifndef _ZZZ_PERSON
#define _ZZZ_PERSON

#include <iostream>
#include <string.h>
using std::cout;
using std::endl;



class Person
{
public:
    Person(const char *name, const char *surname, int age);

    Person(const Person &that);
    Person& operator=(const Person &that);
    ~Person();

    void amt();
private:
    char *name;
    char *surname;
    int age;

    static int amount;    
};









#endif // _ZZZ_PERSON