# LABA 4 — шаблоны и наследование

Лабораторная работа: шаблонное бинарное дерево поиска (`BinaryTree<T>`) над
иерархией классов `Human`.

## Структура проекта

Репозиторий содержит единственную папку `laba4/` — саму лабораторную работу:

```
laba4/
  include/   — заголовки (только объявления)
    human.h  teacher.h  party_member.h  teacher_party_member.h
    tree_node.h  binary_tree.h  table_info.h  menu.h
  src/       — реализация
    human.cpp  teacher.cpp  party_member.cpp  teacher_party_member.cpp
    menu.cpp  main.cpp
    binary_tree.tpp  tree_node.tpp  table_info.tpp   (реализация шаблонов)
  .doc          — текст задания
  Диаграмма.jpeg — UML-диаграмма классов
```

## Сборка и запуск

```bash
cd laba4
g++ -g -Wall src/*.cpp -I include -o app
./app
```

В VS Code — задача «Build C++ project» (Ctrl+Shift+B).

## Особенности решения

- **Иерархия сохранена:** `Human` → `Teacher`, `PartyMember` (виртуальное
  наследование) → `TeacherPartyMember` (множественное). Перегрузки
  `operator<<`/`operator>>` по-прежнему строятся как «базовый + свой».
- **`Human` абстрактен** (чисто виртуальный `typeName()`), поэтому дерево
  хранит ровно один конкретный тип — `BinaryTree<Human>` не компилируется.
- **Вывод таблиц** — обобщённый (`TableInfo<T>` + `printTable<T>`), без
  `dynamic_cast` и без хардкода имён классов. Подробности — в заголовке
  `include/table_info.h` и его реализации `src/table_info.tpp`.
