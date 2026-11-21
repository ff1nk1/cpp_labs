#include "menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "teacher.h"
#include "party_member.h"
#include "teacher_party_member.h"
#include "table_info.h"
#include "binary_tree.h"

using namespace std;

template <class T>
struct LastNameLess
{
    bool operator()(const T& a, const T& b) const
    {
        return a.getLastName() < b.getLastName();
    }
};

template <class T, class Compare>
void fillManual(BinaryTree<T, Compare>& tree, const string& inputFormat)
{
    T obj;
    cout << "Введите " << obj.typeName() << " (формат: " << inputFormat << ")\n>> ";
    cin >> obj;

    if (!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Данные не добавлены.\n";
    }
    else
    {
        tree.add(obj);
        cout << "\n[OK] Данные добавлены!\n";
    }
}

template <class T, class Compare>
void runEntityMenu(const string& inputFormat, const vector<T>& demoData)
{
    BinaryTree<T, Compare> tree;
    const string name = T().typeName();
    int choice;

    while (true)
    {
        cout << "\n--- МЕНЮ " << name << " ---\n"
             << "1. Добавить " << name << " вручную\n"
             << "2. Автозаполнить дерево " << name << "\n"
             << "3. Вывести дерево " << name << " и ТОЛЬКО его таблицу\n"
             << "4. Найти " << name << " по фамилии\n"
             << "5. Удалить " << name << " по фамилии\n"
             << "0. Назад в главное меню\n"
             << "Ваш выбор: ";

        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        if (choice == 0) break;
        else if (choice == 1) fillManual(tree, inputFormat);
        else if (choice == 2) {
            for (const T& item : demoData) tree.add(item);
            cout << "\n[OK] Дерево заполнено тестовыми объектами!\n";
        }
        else if (choice == 3) {
            vector<T> db = tree.toVector();
            if (db.empty()) cout << "\nДерево пустое.\n";
            else {
                cout << "\nСтруктура дерева (повернута на 90 градусов):\n";
                tree.print([](const T& v) { cout << v.getLastName(); });
                cout << "\nТабличный вид:\n";
                printTable(db);
            }
        }
        else if (choice == 4) {
            string surname; cout << "Фамилия для поиска: "; cin >> surname;
            T* found = tree.find([&](const T& v) { return v.getLastName() == surname; });
            if (found) { vector<T> tmp = {*found}; printTable(tmp); }
            else cout << "Не найдено.\n";
        }
        else if (choice == 5) {
            string surname; cout << "Фамилия для удаления: "; cin >> surname;
            if (tree.removeIf([&](const T& v) { return v.getLastName() == surname; }))
                cout << "Удалено.\n";
            else cout << "Не найдено.\n";
        }
    }
}


void runTeacherMenu()
{
    vector<Teacher> demo = {
        Teacher("Ivanov", "22.08.1985", "Docent", {"Physics", "Math"}),
        Teacher("Petrov", "22.08.1985", "Docent", {"Physics", "Math"}),
        Teacher("Sidorov", "01.01.1990", "Professor", {"Math"})
    };
    runEntityMenu<Teacher, LastNameLess<Teacher>>(
        "LastName BirthDate Post WorksCount Work1...", demo);
}

void runPartyMemberMenu()
{
    vector<PartyMember> demo = {
        PartyMember("Antonov", "10.11.1980", "Green_Party", {"Born_in_Minsk", "Graduated_BSU"}),
        PartyMember("Orlov", "03.03.1970", "Blue_Party", {"Born_in_Gomel"})
    };
    runEntityMenu<PartyMember, LastNameLess<PartyMember>>(
        "LastName BirthDate PartyName BioCount Bio1...", demo);
}

void runTeacherPartyMemberMenu()
{
    vector<TeacherPartyMember> demo = {
        TeacherPartyMember("Smirnov", "05.05.1975", "Professor", {"Physics", "Math"},
                           "Science", {"Born_in_Minsk", "Graduated_BSU"}, "BSUIR")
    };
    runEntityMenu<TeacherPartyMember, LastNameLess<TeacherPartyMember>>(
        "LastName BirthDate Post WorksCount Work... Party BioCount Bio... Job", demo);
}

void runIntMenu()
{
    BinaryTree<int> tree;
    int choice;

    while (true)
    {
        cout << "\n--- МЕНЮ INT ---\n"
             << "1. Добавить число\n"
             << "2. Автозаполнение\n"
             << "3. Вывести дерево чисел\n"
             << "4. Поиск числа\n"
             << "5. Удалить число\n"
             << "0. Назад в главное меню\n"
             << "Ваш выбор: ";

        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        if (choice == 0) break;
        else if (choice == 1) {
            int val; cout << "Введите число: "; cin >> val;
            tree.add(val); cout << "Добавлено.\n";
        }
        else if (choice == 2) {
            tree.add(50); tree.add(30); tree.add(70); tree.add(20); tree.add(40); tree.add(60); tree.add(80);
            cout << "Дерево заполнено числами!\n";
        }
        else if (choice == 3) {
            if (tree.toVector().empty()) cout << "\nДерево пустое.\n";
            else tree.print([](const int& val) { cout << val; });
        }
        else if (choice == 4) {
            int val; cout << "Число для поиска: "; cin >> val;
            int* found = tree.find([&](const int& v) { return v == val; });
            if (found) cout << "Число " << *found << " найдено в дереве.\n";
            else cout << "Не найдено.\n";
        }
        else if (choice == 5) {
            int val; cout << "Число для удаления: "; cin >> val;
            if (tree.removeIf([&](const int& v) { return v == val; }))
                cout << "Удалено.\n";
            else cout << "Не найдено.\n";
        }
    }
}

