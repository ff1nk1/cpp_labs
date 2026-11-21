#include "party_member.h"

using namespace std;

PartyMember::PartyMember() : Human(), party_name("")            
{
}

PartyMember::PartyMember(const string& lastName, const string& birthDate, const string& partyName, const vector<string>& bio)
    : Human(lastName, birthDate), party_name(partyName), autobiography(bio)
{
}

PartyMember::~PartyMember()                                     
{
}

string PartyMember::typeName() const                            // Имя типа для таблицы
{
    return "PartyMember";
}

string PartyMember::getPartyName() const                        
{
    return party_name;                                          
}

vector<string> PartyMember::getAutobiography() const            
{
    return autobiography;                                       
}

void PartyMember::setPartyName(const string& pName)             
{
    party_name = pName;                                         
}

void PartyMember::setAutobiography(const vector<string>& bio)   
{
    autobiography = bio;                                        
}

ostream& operator<<(ostream& os, const PartyMember& obj)        
{
    os << static_cast<const Human&>(obj);                       // Вызов вывода базового класса через static_cast
    os << " | Party: " << obj.party_name << " | Bio entries: " << obj.autobiography.size();
    return os;
}

istream& operator>>(istream& is, PartyMember& obj)              
{
    is >> static_cast<Human&>(obj);                             // Считываем базу
    is >> obj.party_name;                                       
    
    int count;                                                  
    is >> count;                                                
    obj.autobiography.clear();                                  
    for (int i = 0; i < count; ++i)                             
    {
        string entry;                                           
        is >> entry;                                            
        obj.autobiography.push_back(entry);                     
    }
    return is;
}
