#pragma once
#include <string>
#include <iostream>

using namespace std;

class Human
{
protected:
    string last_name;                                           // Фамилия
    string birth_date;                                          // Дата рождения

public:
    Human();                                                    // Конструктор по умолчанию
    explicit Human(const string& lastName, const string& birthDate);     // Конструктор с параметрами
    virtual ~Human();                                           // Виртуальный деструктор

    virtual string typeName() const = 0;                        // Чисто виртуальный метод: делает Human абстрактным

    string getLastName() const;                                 // Геттер фамилии
    string getBirthDate() const;                                // Геттер даты рождения

    void setLastName(const string& lastName);                   // Сеттер фамилии
    void setBirthDate(const string& birthDate);                 // Сеттер даты рождения

    friend ostream& operator<<(ostream& os, const Human& obj);  // Перегрузка вывода
    friend istream& operator>>(istream& is, Human& obj);        // Перегрузка ввода
};
