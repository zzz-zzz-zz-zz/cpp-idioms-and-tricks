#include "person.hpp"


int Person::amount = 0;

void Person::amt() 
{ 
    cout << "Persons in town: " << amount << endl; 
}


Person::Person(const char *the_name, const char *the_surname, int the_age)
{
    amount++;
    cout << "Person::Person(" << the_name << " " << the_surname << ", " << the_age << " y.o.)" << endl;
    amt();

    name = new char[strlen(the_name)+1];
    strcpy(name, the_name);
    
    try 
    {
        surname = new char[strlen(the_surname)+1];
        strcpy(surname, the_surname);
    } 
    catch (std::bad_alloc &e) 
    { 
        std::cout << "No memory for surname: " << e.what() << std::endl;
        delete[] name;
    }

    age = the_age;
}

Person::Person(const Person &that)
{
    amount++;
    cout << "Person::Person(const Person &)" << endl; 
    cout << "\tPerson(" << that.name << " " << that.surname << ", " << that.age << " y.o.)" << endl;       
    amt();

    name = new char[strlen(that.name)+1];
    strcpy(name, that.name);
    
    try 
    {
        surname = new char[strlen(that.surname)+1];
        strcpy(surname, that.surname);
    } 
    catch (std::bad_alloc &e) 
    { 
        std::cout << "No memory for surname: " << e.what() << std::endl;
        delete[] name;
    }

    age = that.age;
}

Person& Person::operator=(const Person &that)
{
    cout << "Person::operator=(const Person &)" << endl; 
    cout << "\tPerson(" << that.name << " " << that.surname << ", " << that.age << " y.o.)" << endl;                  
    amt();

    if (this != &that)
    {
        delete[] name;

        name = new char[strlen(that.name)+1];
        strcpy(name, that.name);
        
        try 
        {
            delete[] surname;

            surname = new char[strlen(that.surname)+1];
            strcpy(surname, that.surname);
        } 
        catch (std::bad_alloc &e) 
        { 
            std::cout << "No memory for surname: " << e.what() << std::endl;
            delete[] name;
        }

        age = that.age;
    }
    return *this;
}

Person::~Person()
{
    amount--;
    cout << "Person::~Person(). Bye, " << name << " " << surname << endl;   
    cout << "\t~Person(" << name << " " << surname << ", " << age << " y.o.)" << endl;                           
    amt();
    

    delete[] name;
    delete[] surname;
}