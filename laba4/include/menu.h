#pragma once

// Каждое дерево хранит РОВНО ОДИН конкретный тип, поэтому для каждой
// сущности — отдельная точка входа в меню (Human абстрактен и недоступен).
void runTeacherMenu();               // Дерево объектов Teacher
void runPartyMemberMenu();           // Дерево объектов PartyMember
void runTeacherPartyMemberMenu();    // Дерево объектов TeacherPartyMember
void runIntMenu();                   // Дерево чисел int
