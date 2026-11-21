#pragma once
#include "human.h"
#include <vector>
#include <iostream>

using namespace std;

class PartyMember : virtual public Human                        // Виртуальное наследование
{
protected:
    string party_name;                                          // Название партии
    vector<string> autobiography;                               // Автобиография

public:
    PartyMember();                                              
    explicit PartyMember(const string& lastName, const string& birthDate, const string& partyName, const vector<string>& bio);
    virtual ~PartyMember();                                     

    string typeName() const override;                           // Реализация абстрактного метода

    string getPartyName() const;                                
    vector<string> getAutobiography() const;                    

    void setPartyName(const string& partyName);                 
    void setAutobiography(const vector<string>& bio);           

    friend ostream& operator<<(ostream& os, const PartyMember& obj); 
    friend istream& operator>>(istream& is, PartyMember& obj);       
};
