// Create a custom vector class that would support all the functionality
// given in main.cpp.

// Again: Declare your functions inside your class, but define them outside of it.

#pragma once
#include <initializer_list>
#include <iostream>

template <class T>
class Vector{
    public:
        // 1
        Vector();
        Vector(size_t);
        Vector(size_t, T);
        size_t size() const;
        // 2
        Vector(std::initializer_list<T>);
        T& operator[](size_t);
        // 3
        void push_back(const T&);
        // 4
        void pop_back();
        // 5
        void clear();
        bool empty() const;
        // 6
        Vector(const Vector&);
        bool operator==(const Vector&);
        bool operator!=(const Vector&);
        // 7
        Vector& operator=(const Vector&);
        // 8
        T& at(size_t) const;
        T& front() const;
        T& back() const;
        T* data() const;
        // 9
        void reserve(size_t);
        int capacity() const;
        void shrink_to_fit();
        // 10
        void swap(Vector&);
        // 11
        const T& operator[](size_t) const;
        // 12
        ~Vector();
        // 16
        Vector(Vector&&);
        Vector& operator=(Vector&&);

    private:
        size_t m_size;
        size_t m_capacity;
        T* m_data;
};

template<class T>
T* allocFoo(size_t size){
    return static_cast<T*>(operator new[](sizeof(T)*size));
}

template<class T>
void deallocFoo(T* data, size_t size){
    for(size_t i = 0; i < size; i++){
        data[i].~T();
    }
    operator delete[](data);
}

template<class T>
size_t Vector<T>::size() const{
    return m_size;
}

template<class T>
Vector<T>::Vector() : m_size(0), m_capacity(10){
    m_data = allocFoo<T>(m_capacity);
}

template<class T>
Vector<T>::Vector(size_t size) : m_size(size), m_capacity(size){
    m_data = allocFoo<T>(m_capacity);
    for(size_t i = 0; i < size; i++){
        m_data[i] = T();
    }
}

template<class T>
Vector<T>::Vector(size_t size, T var) : m_size(size), m_capacity(size), m_data(new T[m_capacity]) {
    m_data = allocFoo<T>(m_capacity);
    for(size_t i = 0; i < size; i++){
        m_data[i] = var;
    }

}

template <class T>
Vector<T>::~Vector(){
    deallocFoo<T>(m_data, m_size);
}

template<class T>
Vector<T>::Vector(const std::initializer_list<T> vals) {
    m_data = new T[vals.size()];
    m_size = vals.size();
    m_capacity = vals.size();

    size_t i = 0;
    for(const auto a : vals){
        m_data[i] = a;
        ++i;
    }
}

template<class T>
T& Vector<T>::operator[](size_t index){
    return m_data[index];
}

template<class T>
Vector<T>::Vector(const Vector& other){
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new T[m_capacity];
    for(size_t i = 0; i < m_size; i++){
        m_data[i] = other.m_data[i];
    }
}

template<class T>
Vector<T>::Vector(Vector&& other) : m_size(other->m_size), m_capacity(other->m_capacity), m_data(other->m_data) {
    other->m_size = 0;
    other->m_capacity = 0;
    for(size_t i = 0; i < m_size; i++){
        m_data[i] = other->m_data[i];
    }
    other->m_data = nullptr;
}

template<class T>
void Vector<T>::push_back(const T& var){
    if(m_capacity < m_size + 1){
        T* f = allocFoo<T>(m_capacity*2);
        for (int i = 0; i < m_size; i++){
            f[i] = m_data[i];
        }
        deallocFoo<T>(m_data, m_size);
        m_data = f;
        m_capacity *= 2;
    }
    m_data[m_size++] = var;
}


template <class T>
void Vector<T>::pop_back(){
    m_data[--m_size].~T();
}

template <class T>
void Vector<T>::clear(){
    m_size = 0;
}

template <class T>
bool Vector<T>::empty() const{
    return  m_size == 0;
}

template <class T>
bool Vector<T>::operator==(const Vector& other){
    if(m_size != other.m_size){
        return false;
    }
    for(int i = 0; i < m_size; i++){
        if(m_data[i] != other.m_data[i]){
            return false;
        }
    }

    return true;
}

template <class T>
bool Vector<T>::operator!= (const Vector& other){
    return !(*this == other);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector& other){
    if(this == &other){
        return *this;
    }
    if(m_capacity < other.m_capacity){
        deallocFoo<T>(m_data,m_size);
        m_data = allocFoo<T>(other.m_capacity);
    }
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    for(size_t i = 0; i < m_size; i++){
        m_data[i] = other.m_data[i];
    }

    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector&& other){
    if(this == &other){
        return *this;
    }
    if(m_capacity < other.m_capacity){
        deallocFoo<T>(m_data, m_size);
    }
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_data = other.m_data;
    other.m_capacity = 0;
    other.m_size = 0;
    other.m_data = nullptr;

    return *this;
}

template <class T>
T& Vector<T>::at(size_t i) const{
    return m_data[i];
}
template <class T>
T& Vector<T>::front() const{
    return m_data[0];
}
template <class T>
T& Vector<T>::back() const{
    return m_data[m_size-1];
}
template <class T>
T* Vector<T>::data() const{
    return m_data;
}

template <class T>
void Vector<T>::reserve(size_t s){
    if(m_capacity < s){
        m_capacity = s;
        T* tmp = allocFoo<T>(m_capacity);
        for(size_t i = 0; i < m_size; i++){
            tmp[i] = m_data[i];
        }
        deallocFoo<T>(m_data,m_size);
        m_data = tmp;
    }
}

template <class T>
int Vector<T>::capacity() const{
    return m_capacity;
}

template <class T>
void Vector<T>::shrink_to_fit(){
    if(m_size != m_capacity){
        m_capacity = m_size;
        T* tmp = allocFoo<T>(m_capacity);
        for(size_t i = 0; i < m_size; i++){
            tmp[i] = m_data[i];
        }
        deallocFoo<T>(m_data, m_size);
        m_data = tmp;
    }
}

template <class T>
void Vector<T>::swap(Vector& other){
    size_t tmp1 = m_size;
    m_size = other.m_size;
    other.m_size = tmp1;

    size_t tmp2 = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = tmp2;

    T* tmp3 = m_data;
    m_data = other.m_data;
    other.m_data = tmp3;
}

template<class T>
const T& Vector<T>::operator[](size_t i) const{
    return m_data[i];
}

