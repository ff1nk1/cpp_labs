#include "teacher.h"

using namespace std;

Teacher::Teacher() : Human(), post("")                          
{
}

Teacher::Teacher(const string& lastName, const string& birthDate, const string& post, const vector<string>& works)
    : Human(lastName, birthDate), post(post), science_works(works)
{
}

Teacher::~Teacher()                                             
{
}

string Teacher::typeName() const                                // Имя типа для таблицы
{
    return "Teacher";
}

string Teacher::getPost() const                                 
{
    return post;                                                
}

vector<string> Teacher::getScienceWorks() const                 
{
    return science_works;                                       
}

void Teacher::setPost(const string& p)                          
{
    post = p;                                                   
}

void Teacher::setScienceWorks(const vector<string>& works)      
{
    science_works = works;                                      
}

ostream& operator<<(ostream& os, const Teacher& obj)            
{
    os << static_cast<const Human&>(obj);                       // Вызов оператора << базового класса через static_cast
    os << " | Post: " << obj.post << " | Works count: " << obj.science_works.size();
    return os;
}

istream& operator>>(istream& is, Teacher& obj)                  
{
    is >> static_cast<Human&>(obj);                             // Вызов оператора >> базового класса
    is >> obj.post;                                             // Считывание своих полей
    
    int count;                                                  
    is >> count;                                                
    obj.science_works.clear();                                  
    for (int i = 0; i < count; ++i)                             
    {
        string work;                                            
        is >> work;                                             
        obj.science_works.push_back(work);                      
    }
    return is;
}
