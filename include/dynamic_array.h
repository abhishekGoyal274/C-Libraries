#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<bits/stdc++.h>

static constexpr size_t INITIAL_SIZE = 256; 
static constexpr size_t MAX_SAFE_SIZE = INT_MAX; 
static constexpr size_t MAX_VALUE = INT_MAX; 

template<typename T>
class dynamic_array
{
private:
    T* array;
    size_t current_size{0}; size_t max_size;
    void double_size();
public:
    // Constructors for dynamic_array
    dynamic_array();
    dynamic_array(size_t size);
    dynamic_array(size_t size, T values);

    //RAII compliant copy constructor, copy assignment operator, move constructor, and destructor
    dynamic_array(const dynamic_array& other);
    dynamic_array& operator=(const dynamic_array& other);
    dynamic_array(dynamic_array&& other);
    dynamic_array& operator=(dynamic_array&& other);
    ~dynamic_array();

    // Overloaded subscript operator for element access
    T& operator[](int index);

    
    void push_back(const T& member);
    void pop_back();
    size_t size();
    void clear();
    void free();

};

template<typename T>
dynamic_array<T>::dynamic_array() : current_size(0), max_size(INITIAL_SIZE){
    this->array = new T[max_size];
    return;
}

template<typename T>
dynamic_array<T>::dynamic_array(size_t size) : current_size(0), max_size(size){
    if(size > MAX_SAFE_SIZE) throw std::out_of_range("Size exceeds maximum safe limit");
    this->array = new T[size];
    return;
}

template<typename T>
dynamic_array<T>::dynamic_array(size_t size, T member) : current_size(size), max_size(size){
    if(size > MAX_SAFE_SIZE) throw std::out_of_range("Size exceeds maximum safe limit");
    this->array = new T[size];
    for(size_t i = 0; i < size; i++){
        array[i] = member;
    }
    return;
}

template<typename T>
dynamic_array<T>::dynamic_array(const dynamic_array<T>& other) 
    :current_size(other.current_size), max_size(other.max_size){
    this->array = new T[max_size];
    for(size_t i = 0; i < current_size; i++){
        this->array[i] = other.array[i];
    }
}

template<typename T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array<T>& other){
    if(this == &other) return *this;
    delete[] this->array;
    this->current_size = other.current_size; 
    this->max_size = other.max_size;

    this->array = new T[this->max_size];
    for(int i=0; i<other.current_size; i++){
        this->array[i] = other.array[i];
    }
    return *this;
}

template<typename T>
dynamic_array<T>::dynamic_array(dynamic_array<T>&& other){
    this->current_size = other.current_size;
    this->max_size = other.max_size;
    this->array = other.array;
    other.current_size = other.max_size = 0;
    other.array = nullptr;
}

template<typename T>
dynamic_array<T>& dynamic_array<T>::operator=(dynamic_array<T>&& other){
    if(this == &other) return *this;
    delete[] this->array;
    
    this->current_size = other.current_size;
    this->max_size = other.max_size;
    this->array = other.array;
    other.current_size = other.max_size = 0;
    other.array = nullptr;
    return *this;
}

template<typename T>
T& dynamic_array<T>::operator[](int index){
    if(index < 0 || index >= current_size) throw std::out_of_range("Index out of range");
    return array[index];
}


template<typename T>
dynamic_array<T>::~dynamic_array(){
    delete[] array;
    return;
}

template<typename T>
void dynamic_array<T>::double_size(){
    if(max_size > MAX_SAFE_SIZE/2) return;
    max_size *= 2;
    T* new_array = new T[max_size];
    for(size_t i = 0; i < current_size; i++){
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
    return;
}

template<typename T>
void dynamic_array<T>::push_back(const T& member){
    if(current_size == max_size) double_size();
    array[current_size] = member;
    current_size++;
    return;
}

template<typename T>
void dynamic_array<T>::pop_back(){
    if(current_size == 0) return;
    current_size--;
    return;
}

template<typename T>
size_t dynamic_array<T>::size(){
    return current_size;
}

template<typename T>
void dynamic_array<T>::clear(){
    current_size = 0;
    return;
}

template<typename T>
void dynamic_array<T>::free(){
    delete[] array;
    this->array = nullptr;
    current_size = 0; max_size = INITIAL_SIZE;
    this->array = new T[max_size];
    return;
}

#endif 
