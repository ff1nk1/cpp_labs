#pragma once

template <typename T>
class TreeNode
{
public:
    T data;                                                     // Данные узла
    TreeNode* left;                                             // Указатель на левое поддерево
    TreeNode* right;                                            // Указатель на правое поддерево

    explicit TreeNode(const T& val);
};

// Реализация — в src/ (в заголовке только объявления)
#include "../src/tree_node.tpp"
