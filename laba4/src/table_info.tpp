#ifndef TABLE_INFO_TPP_IMPL
#define TABLE_INFO_TPP_IMPL

#include "table_info.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

/*
 * Политика "описания таблицы" для конкретного типа.
 * Столбцы и значения строятся как БАЗОВЫЕ + СОБСТВЕННЫЕ (тот же принцип,
 * что в operator<< каждого класса), поэтому наследование отражено напрямую,
 * а в печатающем коде нет ни dynamic_cast, ни списка имён классов.
 */
template <>
struct TableInfo<Human>
{
    static vector<string> columns() { return {"Name", "Birth"}; }
    static vector<string> row(const Human& h) { return {h.getLastName(), h.getBirthDate()}; }
};

template <>
struct TableInfo<Teacher>
{
    static vector<string> columns()
    {
        vector<string> cols =
         TableInfo<Human>::columns();      // базовые столбцы
        cols.push_back("Post");                                 // + собственные
        cols.push_back("Wks");
        return cols;
    }
    static vector<string> row(const Teacher& t)
    {
        vector<string> r = TableInfo<Human>::row(t);            // базовые значения
        r.push_back(t.getPost());                               // + собственные
        r.push_back(to_string(t.getScienceWorks().size()));
        return r;
    }
};

template <>
struct TableInfo<PartyMember>
{
    static vector<string> columns()
    {
        vector<string> cols = TableInfo<Human>::columns();
        cols.push_back("Party");
        cols.push_back("Bio");
        return cols;
    }
    static vector<string> row(const PartyMember& p)
    {
        vector<string> r = TableInfo<Human>::row(p);
        r.push_back(p.getPartyName());
        r.push_back(to_string(p.getAutobiography().size()));
        return r;
    }
};

template <>
struct TableInfo<TeacherPartyMember>
{
    static vector<string> columns()
    {
        vector<string> cols = TableInfo<Human>::columns();      // Human
        cols.push_back("Post");                                 // Teacher
        cols.push_back("Wks");
        cols.push_back("Party");                                // PartyMember
        cols.push_back("Bio");
        cols.push_back("Job");                                  // собственное поле
        return cols;
    }
    static vector<string> row(const TeacherPartyMember& x)
    {
        vector<string> r = TableInfo<Human>::row(x);            // Human один раз (без "ромба")
        r.push_back(x.getPost());
        r.push_back(to_string(x.getScienceWorks().size()));
        r.push_back(x.getPartyName());
        r.push_back(to_string(x.getAutobiography().size()));
        r.push_back(x.getJob());
        return r;
    }
};

// Универсальный вывод одной таблицы для однородного набора объектов типа T
template <class T>
void printTable(const vector<T>& items)
{
    const vector<string> cols = TableInfo<T>::columns();
    const size_t n = cols.size();
    const size_t gap = 3;

    vector<size_t> width(n);
    for (size_t i = 0; i < n; ++i)
        width[i] = cols[i].size();

    vector<vector<string>> rows;
    rows.reserve(items.size());
    for (const T& item : items)
    {
        vector<string> r = TableInfo<T>::row(item);
        for (size_t i = 0; i < n && i < r.size(); ++i)
            width[i] = max(width[i], r[i].size());
        rows.push_back(move(r));
    }

    size_t total = 0;
    for (size_t w : width) total += w + gap;

    const string title = items.empty() ? string("Empty") : items.front().typeName();

    cout << "\n" << title << "\n";
    cout << string(total, '-') << "\n";

    cout << left;
    for (size_t i = 0; i < n; ++i)
        cout << setw(int(width[i] + gap)) << cols[i];
    cout << "\n";
    cout << string(total, '-') << "\n";

    for (const vector<string>& r : rows)
    {
        for (size_t i = 0; i < n; ++i)
            cout << setw(int(width[i] + gap)) << r[i];
        cout << "\n";
    }
    cout << string(total, '-') << "\n";
}

#endif
