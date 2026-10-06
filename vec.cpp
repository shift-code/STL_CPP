#include "vec.h"
#include <iostream>

namespace stdvec{ //stdvec START

    template<typename T>
    vec_t<T>::vec_t() : data(new T[2]), size(0), cap(2) {}

    template<typename T>
    vec_t<T>::~vec_t() {
        delete[] data;
    }

    // Returns a pointer to the first element of the vector.
    template<typename T>
    T* vec_t<T>::begin(){
        return &(data[0]);
    }

    // Returns a pointer to the element right after the last one.
    template<typename T>
    T* vec_t<T>::end(){
        return &(data[size]);
    }

    // Returns a reference to the first element.
    template<typename T>
    T& vec_t<T>::front(){
        return data[0];
    }

    // Returns a reference to the last element.
    template<typename T>
    T& vec_t<T>::back(){
        return data[size-1];
    }

    // Adds a new element to the end of the vector and grows the internal array if necessary.
    template<typename T>
    void vec_t<T>::push_back(const T val) {
        if (size == cap) {
            cap *= 2;
            T *newData = new T[cap];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = val;
        ++size;
    }

    // Removes the last element if the vector is not empty.
    template<typename T>
    void vec_t<T>::pop_back() {
        if (size > 0) {
            --size;
        }
    }

    // Inserts an element at the front and shifts existing items to the right.
    template<typename T>
    void vec_t<T>::push_front(const T x) {
        if (size == cap) {
            cap *= 2;
            T *newData = new T[cap];
            for (size_t i = 0; i < size; ++i) {
                newData[i + 1] = data[i];
            }
            delete[] data;
            data = newData;
        } else {
            for (size_t i = size; i > 0; --i) {
                data[i] = data[i - 1];
            }
        }
        data[0] = x;
        ++size;
    }

    // Removes the first element and shifts the remaining values left.
    template<typename T>
    void vec_t<T>::pop_front() {
        if (size == 0) {
            return;
        }
        for (size_t i = 0; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    // Inserts a value at the given position and replaces the existing element there.
    template<typename T>
    void vec_t<T>::insert(size_t index,const T& value){
        if(index >= size)throw std::out_of_range("vec_t index out of range");
        data[index] = value;
    }

    // Returns the number of currently stored elements.
    template<typename T>
    size_t vec_t<T>::get_size() const {
        return size;
    }

    // Returns the current maximum number of elements before reallocation.
    template<typename T>
    size_t vec_t<T>::get_cap() const {
        return cap;
    }

    // Returns the element located at the given index.
    template<typename T>
    T vec_t<T>::get_value(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("vec_t index out of range");
        }
        return data[index];
    }

    // Checks whether the vector is empty.
    template<typename T>
    bool vec_t<T>::isEmpty() const {
        return size == 0;
    }

    // Updates the element at the specified index with a new value.
    template<typename T>
    void vec_t<T>::set_value(const T& value, size_t index) {
        if (index < size) {
            data[index] = value;
        }
    }

    // Prints every stored element with its index.
    template<typename T>
    void vec_t<T>::print_all() const{
        if(size == 0)return;
        for(size_t i = 0;i < size;++i){
            std::cout<<"ID: "<<i<<"\tValue: "<<data[i]<<std::endl;
        }
    }

    // Prints one element by its index.
    template<typename T>
    void vec_t<T>::print_el(const size_t index){
        if(size == 0)return;
        if(index >= size)throw std::out_of_range("vec_t index out of range");
        std::cout<<"Element: "<<data[index]<<std::endl;
    }

    // Clears the entire vector and resets its internal capacity.
    template<typename T>
    void vec_t<T>::clear_all(){
        if(size == 0)return;
        delete[] data;
        data = new T[2];
        size = 0;
        cap = 2;
    }

    // Removes the first element matching the specified value.
    template<typename T>
    void vec_t<T>::clear_el(T value){
        if(size == 0)return;

        size_t index = size;
        for(size_t i = 0;i < size;++i){
            if(data[i] == value){
                index = i;
                break;
            }
        }

        if(index == size){
            return;
        }

        for(size_t i = index;i + 1 < size;++i){
            data[i] = data[i + 1];
        }
        --size;
    }



    // Shows a short list of all available operations for this vector.
    template<typename T>
    void vec_t<T>::help() const{
        std::cout << "\nstdvec::vec_t<T> help\n";
        std::cout << "----------------------\n";
        std::cout << "operator[]          - access an element by index\n";
        std::cout << "begin()             - get pointer to first element\n";
        std::cout << "end()               - get pointer to end position\n";
        std::cout << "front()             - access the first element\n";
        std::cout << "back()              - access the last element\n";
        std::cout << "push_back(value)    - add an element to the end\n";
        std::cout << "pop_back()          - remove the last element\n";
        std::cout << "push_front(value)   - add an element to the beginning\n";
        std::cout << "pop_front()         - remove the first element\n";
        std::cout << "insert(index, v)    - insert/replace at index\n";
        std::cout << "get_size()          - return current number of elements\n";
        std::cout << "get_cap()           - return current internal capacity\n";
        std::cout << "get_value(index)    - access an element by index\n";
        std::cout << "set_value(value, i) - replace an element at index i\n";
        std::cout << "isEmpty()           - check whether the vector is empty\n";
        std::cout << "print_all()         - print all elements\n";
        std::cout << "print_el(index)     - print one element by index\n";
        std::cout << "clear_all()         - remove all elements\n";
        std::cout << "clear_el(value)     - remove the first matching value\n";
        std::cout << "help()              - show this menu\n";
    }

} //stdvec END