#pragma once
#include "teacher.h"
#include "party_member.h"
#include <iostream>

using namespace std;

class TeacherPartyMember : public Teacher, public PartyMember   // Множественное наследование
{
private:
    string job;                                                 // Место работы

public:
    TeacherPartyMember();                                       
    explicit TeacherPartyMember(const string& lastName, const string& birthDate, const string& post, const vector<string>& works, const string& partyName, const vector<string>& bio, const string& job);
    ~TeacherPartyMember() override;                             

    string typeName() const override;                           // Переопределение снимает неоднозначность "ромба"

    string getJob() const;                                      
    void setJob(const string& job);                             

    friend ostream& operator<<(ostream& os, const TeacherPartyMember& obj); 
    friend istream& operator>>(istream& is, TeacherPartyMember& obj);       
};
