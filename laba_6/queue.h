#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cassert>



template <class T>
class Queue
{
public:
    using size_type = std::size_t;
    T* m_queuePtr;     // указатель на очередь
    size_type m_size;  // максимальное количество элементов в очереди
    int m_begin;       // начало очереди
    int m_end;         // конец очереди
    int m_elemCT;      // счетчик элементов
public:
    Queue(int = 10);          // конструктор по умолчанию
    Queue(const Queue<T> &); // конструктор копирования
    Queue(T* queuePtr, int begin, int end, int elemCT): m_queuePtr(queuePtr), m_begin(begin), m_end(end), m_elemCT(elemCT){}
    ~Queue();                // деструктор

    void enqueue(const T &); // добавить элемент в очередь
    T dequeue(); // удалить элемент из очереди
    void printQueue();
};

// реализация методов шаблона класса Queue

// конструктор по умолчанию
template<typename T>
Queue<T>::Queue(int sizeQueue) :
    m_size(sizeQueue), // инициализация константы
    m_begin(0), m_end(0), m_elemCT(0)
{
    // дополнительная позици поможет нам различать конец и начало очереди
    m_queuePtr = new T[m_size + 1];
}

// конструктор копии
template<typename T>
Queue<T>::Queue(const Queue &otherQueue) :
    m_size(otherQueue.m_size) , m_begin(otherQueue.m_begin),
    m_end(otherQueue.m_end), m_elemCT(otherQueue.m_elemCT),
    m_queuePtr(new T[m_size + 1])
{
    for (int ix = 0; ix < m_size; ix++)
    {
        m_queuePtr[ix] = otherQueue.m_queuePtr[ix]; // копируем очередь
    }
}

// деструктор класса Queue
template<typename T>
Queue<T>::~Queue()
{
    delete [] m_queuePtr;
}

// функция добавления элемента в очередь
template<typename T>
void Queue<T>::enqueue(const T &newElem)
{
    // проверяем, ести ли свободное место в очереди
    assert(m_elemCT < m_size);

    // обратите внимание на то, что очередь начинает заполняться с 0 индекса
    m_queuePtr[m_end++] = newElem;

    m_elemCT++;

    // проверка кругового заполнения очереди
    if (m_end > m_size)
    {
        m_end -= m_size + 1; // возвращаем end на начало очереди
    }
}

// функция удаления элемента из очереди
template<typename T>
T Queue<T>::dequeue()
{
    // проверяем, есть ли в очереди элементы
    assert(m_elemCT > 0);

    T returnValue = m_queuePtr[m_begin++];
    m_elemCT--;

    // проверка кругового заполнения очереди
    if (m_begin > m_size)
    {
        m_begin -= m_size + 1; // возвращаем behin на начало очереди
    }

    return returnValue;
}

template<typename T>
void Queue<T>::printQueue()
{
    std::cout << "Queue: ";

    if (m_end == 0 && m_begin == 0)
    {

        std::cout << "/n";
    }

    else
    {
        --m_end;
        for (int ix = m_end; ix >= m_begin; ix--)
            std::cout << m_queuePtr[ix] << " ";
        std::cout << std::endl;
    }
}



#endif // QUEUE_H
