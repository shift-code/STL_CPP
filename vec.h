#ifndef VEC_H
#define VEC_H

#include <cstddef>
#include <stdexcept>

template<typename T>
class vec_t {
private:
    T *data;
    size_t size;
    size_t cap;

public:
    vec_t();
    ~vec_t();

    vec_t(const vec_t&) = delete;
    vec_t& operator=(const vec_t&) = delete;

    void push_back(const T val);
    void pop_back();
    void push_front(const T x);
    void pop_front();

    size_t get_size() const;
    size_t get_cap() const;
    T get_value(size_t index) const;
    bool isEmpty() const;
    void set_value(const T& value, size_t index);
};

#endif 
