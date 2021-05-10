#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <initializer_list>

template <class T>
class myArray 
{
    public:
        myArray();
        myArray(std::initializer_list<T> list);
        myArray(const myArray &copy);
        ~myArray();

        size_t push_back(T data);
        T pop_back();
        void insert(T data, size_t index);
        T erase(size_t index);
        void swap(int a, int b);
        void clear();

        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        T* begin() const;
        T* end() const;

        T& operator[](const size_t index) const;
        myArray& operator=(const myArray &data);

    private:
        size_t allocateMoreMem();
        T *m_content;
        size_t m_totalSize;
        size_t m_currentSize;
};

#include <algorithm>
#include <iterator>

template<class T>
myArray<T>::myArray() :
    m_content(new T[1]) {}

template <class T>
myArray<T>::myArray(std::initializer_list<T> list) :
    m_content(new T[list.size()]), m_totalSize(list.size()), m_currentSize(list.size())
{
    std::copy(list.begin(), list.end(), m_content);
}

template <class T>
myArray<T>::myArray(const myArray<T> &copy) :
    m_content(new T[copy.size()]), m_currentSize(copy.size()), m_totalSize(copy.capacity())
{
    std::copy(copy.begin(), copy.end(), m_content);
}

template <class T>
myArray<T>::~myArray()
{
   delete[] m_content;
}

template <class T>
size_t myArray<T>::push_back(T data)
{
    if (m_currentSize == m_totalSize)
        allocateMoreMem();
    m_content[m_currentSize++] = data;
    return m_currentSize;
}

template <class T>
T myArray<T>::pop_back()
{
    if (m_currentSize == 0)
        throw "Array is empty";
    return m_content[--m_currentSize];
}

template <class T>
void myArray<T>::insert(T data, size_t index)
{
    if (index >= m_currentSize)
        throw "Access Error: out of bounds";
    if (m_currentSize == m_totalSize)
        allocateMoreMem();
    m_currentSize++;
    for (int i = m_currentSize - 1; i > index; i--)
    {
        m_content[i] = m_content[i - 1];
    }
    m_content[index] = data;
}

template <class T>
T myArray<T>::erase(size_t index)
{
    if (index >= m_currentSize)
        throw "Access error: out of bounds";
    if (m_currentSize == 0)
        throw "Array is empty";
    for (int i = index; i < m_currentSize; i++)
        swap(i, i + 1);
    return m_content[--m_currentSize];
}

template <class T>
void myArray<T>::swap(int a, int b)
{
    T tmp = m_content[a];
    m_content[a] = m_content[b];
    m_content[b] = tmp;
}

template <class T>
void myArray<T>::clear()
{
    delete[] m_content;
    m_content = new T[1];
    m_currentSize = 0;
    m_totalSize = 1;
}

template <class T>
bool myArray<T>::empty() const
{
    return !m_currentSize;
}

template <class T>
size_t myArray<T>::size() const
{
    return m_currentSize;
}

template <class T>
size_t myArray<T>::capacity() const
{
    return m_totalSize;
}

template <class T>
T* myArray<T>::begin() const
{
    return &m_content[0];
}

template <class T>
T* myArray<T>::end() const
{
    return &m_content[m_currentSize];
}

template <class T>
T& myArray<T>::operator[](const size_t index) const
{
    if (index >= m_currentSize)
        throw "Access Error: out of bounds";
    return m_content[index];
}

template <class T>
myArray<T>& myArray<T>::operator=(const myArray<T> &data)
{
    if (data.m_content == nullptr)
        throw "Access Error: null reference";
    delete[] m_content;
    m_content = new T[data.size()];
    std::copy(data.begin(), data.end(), m_content);
    m_currentSize = data.size();
    m_totalSize = data.capacity();
    return *this;
}

template <class T>
size_t myArray<T>::allocateMoreMem()
{
    T* old = m_content;
    m_content = new T[m_totalSize*=2];
    std::copy(old, old + m_currentSize, m_content);
    delete[] old;
    return m_totalSize;
}

#endif //MYARRAY_H