#pragma once
#include "human.h"
#include <vector>
#include <iostream>

using namespace std;

class Teacher : virtual public Human                            // Виртуальное наследование
{
protected:
    string post;                                                // Должность
    vector<string> science_works;                               // Вектор научных работ

public:
    Teacher();                                                  // Конструктор
    explicit Teacher(const string& lastName, const string& birthDate, const string& post, const vector<string>& works);
    virtual ~Teacher();                                         // Деструктор

    string typeName() const override;                           // Реализация абстрактного метода

    string getPost() const;                                     
    vector<string> getScienceWorks() const;                     

    void setPost(const string& post);                           
    void setScienceWorks(const vector<string>& works);          

    friend ostream& operator<<(ostream& os, const Teacher& obj);// Перегрузка вывода
    friend istream& operator>>(istream& is, Teacher& obj);      // Перегрузка ввода
};
