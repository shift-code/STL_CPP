#ifndef VEC_H
#define VEC_H

#include <cstddef>
#include <stdexcept>

namespace stdvec{


template<typename T>
class vec_t {
private:
    T *data;
    size_t size;
    size_t cap;

public:
    // Creates an empty vector with an initial capacity of 2.
    vec_t();

    // Frees the dynamically allocated array.
    ~vec_t();

    vec_t(const vec_t&) = delete;
    vec_t& operator=(const vec_t&) = delete;

    // Accesses an element by index for reading and writing.
    T& operator[](size_t index) {
        return data[index];
    }

    // Accesses an element by index in const mode.
    const T& operator[](size_t index) const {
        return data[index];
    }

    // Returns a pointer to the first element in the vector.
    T* begin();

    // Returns a pointer to the element just past the last one.
    T* end();

    // Returns the first element.
    T& front();

    // Returns the last element.
    T& back();

    // Appends an element to the end of the vector.
    void push_back(const T val);

    // Removes the last element if the vector is not empty.
    void pop_back();

    // Inserts an element at the beginning of the vector.
    void push_front(const T x);

    // Removes the first element if the vector is not empty.
    void pop_front();

    // Inserts a value at the specified index.
    void insert(size_t index,const T& value);

    // Replaces the value at the specified index.
    void set_value(const T& value, size_t index);

    // Prints all stored elements to the console.
    void print_all() const;

    // Prints a single element at the given index.
    void print_el(const size_t index);

    // Removes all elements and resets the vector to its initial state.
    void clear_all();

    // Removes the first occurrence of the given value.
    void clear_el(T value);

    // Prints a short help guide describing the available vector methods.
    void help() const;

    // Returns the current number of elements.
    size_t get_size() const;

    // Returns the current capacity of the internal array.
    size_t get_cap() const;

    // Returns the element at the specified index.
    T get_value(size_t index) const;

    // Returns true if the vector contains no elements.
    bool isEmpty() const;
};

}
#endif 
