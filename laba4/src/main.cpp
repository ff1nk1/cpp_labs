#include <iostream>
#include <limits>
#include "menu.h"

using namespace std;

int main()
{
    int choice;

    while (true)
    {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n"
             << "1. Дерево Teacher            (заполнение, вывод, поиск, удаление)\n"
             << "2. Дерево PartyMember        (заполнение, вывод, поиск, удаление)\n"
             << "3. Дерево TeacherPartyMember (заполнение, вывод, поиск, удаление)\n"
             << "4. Дерево чисел (int)\n"
             << "0. Выход\n"
             << "Ваш выбор: ";
             
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный выбор. Введите число.\n";
            continue;
        }

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            runTeacherMenu();
        }
        else if (choice == 2)
        {
            runPartyMemberMenu();
        }
        else if (choice == 3)
        {
            runTeacherPartyMemberMenu();
        }
        else if (choice == 4)
        {
            runIntMenu();
        }
        else
        {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
