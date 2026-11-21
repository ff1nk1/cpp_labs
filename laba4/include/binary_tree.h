#pragma once
#include "tree_node.h"
#include <vector>
#include <functional>

/*
 * Обобщённое бинарное дерево поиска.
 * Хранит ровно ОДИН конкретный тип T (значения хранятся в узлах по значению).
 * Благодаря хранению по значению абстрактный базовый тип (например, Human)
 * физически не может быть параметром шаблона — это отсекает иерархию-основание
 * без единого упоминания имени класса внутри шаблона.
 */
template <typename T, typename Compare = std::less<T>>
class BinaryTree
{
private:
    TreeNode<T>* root;                                          
    Compare comp;                                               

    void destroyTree(TreeNode<T>* node);                        
    TreeNode<T>* insertNode(TreeNode<T>* node, const T& val);   
    TreeNode<T>* removeNode(TreeNode<T>* node, const T& val);   
    TreeNode<T>* findMin(TreeNode<T>* node) const;              
    void collectInOrder(TreeNode<T>* node, std::vector<T>& vec) const; 

    template <typename Predicate>
    TreeNode<T>* searchNode(TreeNode<T>* node, Predicate pred) const; 

    template <typename Action>
    void printNodeVisual(TreeNode<T>* node, int space, Action action) const;

public:
    BinaryTree();                                               
    ~BinaryTree();                                              

    void add(const T& val);                                     
    void remove(const T& val);                                  
    std::vector<T> toVector() const;                            

    template <typename Predicate>
    T* find(Predicate pred) const;                              // Возврат указателя на данные узла (nullptr, если не найдено)

    template <typename Predicate>
    bool removeIf(Predicate pred);                              // Удаление первого узла, удовлетворяющего предикату

    template <typename Action>
    void print(Action action) const;
};

// Реализация шаблона — в src/ (в заголовке только объявления)
#include "../src/binary_tree.tpp"
