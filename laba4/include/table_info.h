#pragma once
#include <vector>
#include <string>
#include "human.h"
#include "teacher.h"
#include "party_member.h"
#include "teacher_party_member.h"

using namespace std;

/*
 * Только ОБЪЯВЛЕНИЯ:
 *   - TableInfo<T>       — политика "описания таблицы" для конкретного типа;
 *   - printTable<T>()    — универсальный вывод одной таблицы.
 * Реализация находится в src/table_info.tpp (в заголовке кода нет).
 */
template <class T>
struct TableInfo;

template <class T>
void printTable(const vector<T>& items);

#include "../src/table_info.tpp"
