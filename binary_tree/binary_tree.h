#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>

namespace stu
{
struct Binary_tree
{
    using size_type = std::size_t;
    struct Node
    {
        int m_value;
        Node* m_left = nullptr;
        Node* m_right = nullptr;
        Node() = default;
        Node(int value):m_value(value){}
    };

    size_type m_size = 0;
    Node* head = nullptr;
    Binary_tree() = default;

    Node* add(Node* node, int key)
    {
        if(node == nullptr)
        {
            ++m_size;
            return new Node(key);
        }
        if(key < node->m_value)
        {
            node->m_left =  add(node->m_left, key);
        }
        if(key > node->m_value)
        {
            node->m_right = add(node->m_right, key);
        }
        return node;
    }

    void insert(int value)
    {
        head = add(head, value);
    }

    void print(Node* node)
    {
        if(node != nullptr)
        {
            print(node->m_left);
            std::cout << node->m_value << std::endl;
            print(node->m_right);

        }
    }

    void print_all()
    {
        print(head);
    }

    Node* search(Node* node, int key) const
    {
        if(node == nullptr || node->m_value == key)
        {
            return node;
        }
        if(key > node->m_value)
        {
            return search(node->m_right, key);
        }
        return search(node->m_left, key);
    }

    bool contains(const int& key ) const
    {
        return search(head, key) != nullptr;
    }

    size_type size()
    {
        return m_size;
    }

};

}
#endif // BINARY_TREE_H
