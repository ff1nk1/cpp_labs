#ifndef TREE_NODE_TPP_IMPL
#define TREE_NODE_TPP_IMPL

#include "tree_node.h"

// Реализация конструктора узла (шаблон, поэтому в отдельном .tpp из src/)
template <typename T>
TreeNode<T>::TreeNode(const T& val) : data(val), left(nullptr), right(nullptr) {}

#endif
