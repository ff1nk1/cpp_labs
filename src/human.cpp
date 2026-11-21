#include "human.h"

using namespace std;

Human::Human() : last_name(""), birth_date("")                  // Инициализация пустых строк
{
}

Human::Human(const string& lastName, const string& birthDate) : last_name(lastName), birth_date(birthDate)
{
}

Human::~Human()                                                 // Деструктор
{
}

string Human::getLastName() const                               
{
    return last_name;                                           
}

string Human::getBirthDate() const                              
{
    return birth_date;                                          
}

void Human::setLastName(const string& lastName)                 
{
    last_name = lastName;                                       
}

void Human::setBirthDate(const string& birthDate)               
{
    birth_date = birthDate;                                     
}

ostream& operator<<(ostream& os, const Human& obj)              // Вывод базовых полей
{
    os << "Name: " << obj.last_name << ", BirthDate: " << obj.birth_date;
    return os;
}

istream& operator>>(istream& is, Human& obj)                    // Ввод базовых полей
{
    is >> obj.last_name >> obj.birth_date;
    return is;
}
