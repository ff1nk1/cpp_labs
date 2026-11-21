#include "teacher_party_member.h"

using namespace std;

TeacherPartyMember::TeacherPartyMember() : Human(), Teacher(), PartyMember(), job("") 
{
}

TeacherPartyMember::TeacherPartyMember(const string& lastName, const string& birthDate, const string& post, const vector<string>& works, const string& partyName, const vector<string>& bio, const string& job)
    : Human(lastName, birthDate), Teacher(lastName, birthDate, post, works), PartyMember(lastName, birthDate, partyName, bio), job(job)
{
}

TeacherPartyMember::~TeacherPartyMember()                       
{
}

string TeacherPartyMember::typeName() const                     // Имя типа (снимает неоднозначность "ромба")
{
    return "TeacherPartyMember";
}

string TeacherPartyMember::getJob() const                       
{
    return job;                                                 
}

void TeacherPartyMember::setJob(const string& j)                
{
    job = j;                                                    
}

ostream& operator<<(ostream& os, const TeacherPartyMember& obj) 
{
    os << static_cast<const Human&>(obj);                       // 1. Выводим базу Human один раз (static_cast предотвращает ромб)
    os << " | Post: " << obj.post << " | Works count: " << obj.science_works.size(); // 2. Напрямую берем поля Teacher
    os << " | Party: " << obj.party_name << " | Bio entries: " << obj.autobiography.size(); // 3. Напрямую берем поля PartyMember
    os << " | Job: " << obj.job;                                // 4. Свое поле
    return os;
}

istream& operator>>(istream& is, TeacherPartyMember& obj)       
{
    is >> static_cast<Human&>(obj);                             // Считываем базу 1 раз
    is >> obj.post;                                             
    
    int w_count;                                                
    is >> w_count;                                              
    obj.science_works.clear();                                  
    for (int i = 0; i < w_count; ++i)                           
    {
        string work;                                            
        is >> work;                                             
        obj.science_works.push_back(work);                      
    }
    
    is >> obj.party_name;                                       
    
    int b_count;                                                
    is >> b_count;                                              
    obj.autobiography.clear();                                  
    for (int i = 0; i < b_count; ++i)                           
    {
        string entry;                                           
        is >> entry;                                            
        obj.autobiography.push_back(entry);                     
    }
    
    is >> obj.job;                                              // Считываем свое поле
    return is;
}
