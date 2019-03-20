#ifndef LIST_H
#define LIST_H
#include <cstddef>
#include <initializer_list>
#include <iterator>
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
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    Node* head = nullptr;
    size_type m_size = 0;
    list():head(new Node()){}
    Node* find_last()
    {
        Node* i = head;
        for(; i->next != nullptr; i = i->next);
        return i;
    }

public:
    void push_back(T value)
    {
        Node* current = find_last();
        current->m_value = value;
        current->next = new Node();
        ++m_size;
    }

list(std::initializer_list<T> l):list()
{
    for(typename std::initializer_list<T>::iterator i = l.begin(); i != l.end(); ++i)
    {
        push_back(*i);
    }
}


struct iterator
{
    Node* m_current = nullptr;
    iterator() = default;
    iterator(Node* current):m_current(current){}
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

    bool operator==(const iterator& that)
    {
        return  this->m_current == that.m_current;
    }

    bool operator!=(const iterator& that)
    {
        return  this->m_current != that.m_current;
    }

};

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

iterator insert_after(const iterator pos, T value)
{
    Node* temp = pos.m_current->next;
    pos.m_current->next = new Node(value);
    pos.m_current->next->next = temp;
}

};

}


#endif // LIST_H
