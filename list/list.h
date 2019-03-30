#ifndef LIST_H
#define LIST_H
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <list>
#include <iostream>
#include <forward_list>

namespace stu
{
template <class T>
class list
{

public:

    struct Node
    {
        Node* next = nullptr;
        T m_value;
        Node() = default;
        Node(T value):m_value(value){}

    };


    struct m_iterator
    {
        Node* m_current = nullptr;
        m_iterator() = default;
        m_iterator(Node* current):m_current(current){}
        operator bool()
        {
            return m_current != nullptr;
        }

        void operator++()
        {
            m_current = m_current->next;
        }

        auto& operator*()
        {
            return m_current->m_value;
        }

        bool operator==(const m_iterator& that)
        {
            return this->m_current == that.m_current;
        }

        bool operator!=(const m_iterator& that)
        {
            return this->m_current != that.m_current;
        }

    };


    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using iterator = m_iterator;
    using reference = T&;
    using const_reference = const reference;

    Node* head = nullptr;
    size_type m_size = 0;

    list():head(new Node()){}
    list(std::initializer_list<value_type> l):list()
    {
        for(typename std::initializer_list<value_type>::iterator i = l.begin(); i != l.end(); ++i)
        {
            push_back(*i);
        }
    }


    Node* find_last()
    {
        Node* i = head;
        for(; i->next != nullptr; i = i->next);
        return i;
    }


    void push_back(value_type value)
    {
        Node* current = find_last();
        current->m_value = value;
        current->next = new Node();
        ++m_size;
    }

iterator begin()
{
    return iterator(head);
}

iterator end()
{
    return iterator(find_last());
}

bool empty()
{
    return head->next == nullptr;
}

size_type size()
{
    return m_size;
}

Node* find(iterator key)
{
    for(auto i = begin(); i != end(); ++i)
    {
        if(i == key)
        {
            return i;
        }
    }
    return end();
}

iterator insert_after(const iterator pos, value_type value)
{
    Node* temp = pos.m_current->next;
    pos.m_current->next = new Node(value);
    pos.m_current->next->next = temp;
}

void erase_after(iterator pos)
{
    Node* temp;
    ++pos;
    for(auto i = pos; i != end(); ++i)
    {
        delete temp;
        temp = i.m_current;
        --m_size;
        std::cout << *i <<" ";
    }
    std::cout << std::endl;
    pos.m_current->next = nullptr;
}

void push_front(value_type value)
{
    Node* temp = head;
    head = new Node(value);
    head->next = temp;
}

void pop_front()
{
    Node* temp = head;
    head = head->next;
    delete temp;
}

void swap(list& other)
{
    std::iter_swap(this->head, other.head);
}

};

}


#endif // LIST_H
