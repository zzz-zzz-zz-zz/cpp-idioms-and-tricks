#include "person.hpp"

int Person::amount = 0;

Person::Person(const char* the_name, int the_age)
{
    // Common situtation: creating new object from parameters
    //      by copying.
    std::cout << "New person: " << the_name << ", " << the_age << " y.o." << std::endl;
    amount++; // NEW PERSON. Note: `amount` don't need in real program!!!
    status();

    name = new char[strlen(the_name)+1];
    strcpy(name, the_name);
    age = the_age;
}

Person::Person(const Person &that) // copy constructor
{
    // You need to create object of existing one.
    // If you meet dynamic resource(new/delete) - make sure you
    //      allocated new space for it to copy.
    // Note: take care of std::bad_alloc in case of 2 or more dynamic resources.
    std::cout << "New person from existing one: " << that.name << ", " << that.age << " y.o." << std::endl;
    amount++; // NEW PERSON. Note: `amount` don't need in real program!!!
    status();
    
    name = new char[strlen(that.name)+1];
    strcpy(name, that.name);
    age = that.age;
}

Person& Person::operator=(const Person &that) // copy assign operator
{
    // Little more complicated situation: assigning(copying) 1 object
    //      in another.
    // To prevent memory leak you have to free occupied memory before
    //      allocating space for new one(-s)
    // Make sure you have exception safety. In case of no space for
    //      new object make sure there will be no memory leaks!
    // Note: take care of std::bad_alloc in case of 2 or more dynamic resources.
    
    // No amount++ here: it's not constructor
    std::cout << "Rewriting person with: " << that.name << ", " << that.age << " y.o." << std::endl;

    if (this != &that)
    {
        delete[] name;

        name = new char[strlen(that.name)+1];
        strcpy(name, that.name);
        age = that.age;
    }
    return *this;
}

Person::~Person() // destructor
{
    // Do not forget to delete allocated memory. Automatic variables will be
    //      calling for this automatically in end of their scope.
    std::cout << "Deleting Person " << name << ", " << age << " y.o. Bye :(" << std::endl;
    amount--; // Note: `amount` don't need in real program!!!
    status();

    delete[] name;    
}
