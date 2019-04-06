#ifndef STACK_H
#define STACK_H
#include <vector>
#include <initializer_list>
namespace stu
{

template <class T, class Container = std::vector<T>>
struct stack {

private:
    Container cont;

public:
    using container_type = Container;
    using value_type = typename Container::value_type;
    using reference = typename Container::reference;
    using size_type = typename Container::size_type;
    using const_reference = typename Container::const_reference;
    stack() = default;
    stack(std::initializer_list<value_type> l)
    {
        for(auto i = l.begin(); i != l.end(); ++i)
        {
            push(*i);
        }

    }

    reference top() {
        return cont.back();
    }

    bool empty() const {
        return cont.empty();
    }

    size_type size() const {
        cont.size();
    }

    void swap(stack& other) noexcept {
        using std::swap;
        swap(cont, other.cont);
    }

    void pop() noexcept {
        cont.pop_back();
    }

    void push(const value_type& value)
    {
        cont.push_back(value);
    }

};

template <class TP, class Cont>
bool operator==(const stack<TP, Cont>& lhs, const stack<TP, Cont>& rhs) {
    return lhs.cont == rhs.cont;
}

template <class Tp, class Cont >
    bool operator!=( const stack<Tp,Cont>& lhs,const stack<Tp,Cont>& rhs ){
         return lhs.cont != rhs.cont;
    }

}
#endif // STACK_H
