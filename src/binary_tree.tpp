#ifndef BINARY_TREE_CPP_IMPL
#define BINARY_TREE_CPP_IMPL

#include "binary_tree.h"
#include <iostream>

using namespace std;

template <typename T, typename Compare>
BinaryTree<T, Compare>::BinaryTree() : root(nullptr)            // Инициализация пустого дерева
{
}

template <typename T, typename Compare>
BinaryTree<T, Compare>::~BinaryTree()
{
    destroyTree(root);                                          // Освобождение всей выделенной памяти
}

template <typename T, typename Compare>
void BinaryTree<T, Compare>::destroyTree(TreeNode<T>* node)     // Рекурсивное удаление узлов (post-order)
{
    if (node != nullptr)
    {
        destroyTree(node->left);                                
        destroyTree(node->right);                               
        delete node;                                            // Удаление узла вместе с хранимым значением
    }
}

template <typename T, typename Compare>
void BinaryTree<T, Compare>::add(const T& val)
{
    root = insertNode(root, val);
}

template <typename T, typename Compare>
TreeNode<T>* BinaryTree<T, Compare>::insertNode(TreeNode<T>* node, const T& val) 
{
    if (node == nullptr)
    {
        return new TreeNode<T>(val);                            // Создание нового узла, если достигнут конец ветки
    }

    if (comp(val, node->data))                                  // Переход в левое поддерево (если значение меньше)
    {
        node->left = insertNode(node->left, val);
    }
    else if (comp(node->data, val))                             // Переход в правое поддерево (если значение больше)
    {
        node->right = insertNode(node->right, val);
    }
    return node;                                                
}

template <typename T, typename Compare>
void BinaryTree<T, Compare>::remove(const T& val)
{
    root = removeNode(root, val);
}

template <typename T, typename Compare>
TreeNode<T>* BinaryTree<T, Compare>::findMin(TreeNode<T>* node) const 
{
    while (node && node->left != nullptr)                       // Спуск к самому левому (минимальному) узлу
    {
        node = node->left;
    }
    return node;
}

template <typename T, typename Compare>
TreeNode<T>* BinaryTree<T, Compare>::removeNode(TreeNode<T>* node, const T& val) 
{
    if (node == nullptr) return nullptr;

    if (comp(val, node->data))
    {
        node->left = removeNode(node->left, val);
    }
    else if (comp(node->data, val))
    {
        node->right = removeNode(node->right, val);
    }
    else                                                        // Узел для удаления найден
    {
        if (node->left == nullptr)                              // Случай 1-2: Отсутствует один или оба потомка
        {
            TreeNode<T>* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            TreeNode<T>* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode<T>* temp = findMin(node->right);               // Случай 3: Есть оба потомка. Подмена на минимум из правой ветви
        node->data = temp->data;                                
        node->right = removeNode(node->right, temp->data);      
    }
    return node;
}

template <typename T, typename Compare>
template <typename Predicate>
T* BinaryTree<T, Compare>::find(Predicate pred) const           
{
    TreeNode<T>* result = searchNode(root, pred);
    return (result != nullptr) ? &result->data : nullptr;       // Указатель на данные либо nullptr
}

template <typename T, typename Compare>
template <typename Predicate>
bool BinaryTree<T, Compare>::removeIf(Predicate pred)
{
    T* found = find(pred);
    if (found == nullptr) return false;

    T value = *found;                                           // Копия значения до удаления (компаратор найдёт узел)
    remove(value);
    return true;
}

template <typename T, typename Compare>
template <typename Predicate>
TreeNode<T>* BinaryTree<T, Compare>::searchNode(TreeNode<T>* node, Predicate pred) const 
{
    if (node == nullptr) return nullptr;

    if (pred(node->data)) return node;                          // Успешная проверка узла предикатом-лямбдой

    TreeNode<T>* leftResult = searchNode(node->left, pred);     // Рекурсивный поиск по ветвям
    if (leftResult != nullptr) return leftResult;

    return searchNode(node->right, pred);                       
}

template <typename T, typename Compare>
template <typename Action>
void BinaryTree<T, Compare>::printNodeVisual(TreeNode<T>* node, int space, Action action) const 
{
    if (node == nullptr) return;

    space += 10;                                                // Отступ для визуализации глубины дерева

    printNodeVisual(node->right, space, action);                // Правое поддерево выводится выше (визуально)

    std::cout << '\n';
    for (int i = 10; i < space; i++)
    {
        std::cout << " ";
    }
    action(node->data);                                         // Вывод самого узла

    printNodeVisual(node->left, space, action);                 // Левое поддерево выводится ниже (визуально)
}

template <typename T, typename Compare>
template <typename Action>
void BinaryTree<T, Compare>::print(Action action) const
{
    if (root == nullptr) {
        std::cout << "Дерево пустое.\n";
        return;
    }
    printNodeVisual(root, 0, action);
    std::cout << "\n";
}

template <typename T, typename Compare>
void BinaryTree<T, Compare>::collectInOrder(TreeNode<T>* node, std::vector<T>& vec) const 
{
    if (node != nullptr)
    {
        collectInOrder(node->left, vec);                        // Центрированный (In-Order) обход 
        vec.push_back(node->data);                              // гарантирует сортировку элементов по возрастанию
        collectInOrder(node->right, vec);                       
    }
}

template <typename T, typename Compare>
std::vector<T> BinaryTree<T, Compare>::toVector() const         
{
    std::vector<T> vec;
    collectInOrder(root, vec);
    return vec;
}

#endif

