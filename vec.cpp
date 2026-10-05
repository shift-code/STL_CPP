#include "vec.h"

template<typename T>
vec_t<T>::vec_t() : data(new T[2]), size(0), cap(2) {}

template<typename T>
vec_t<T>::~vec_t() {
    delete[] data;
}

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

template<typename T>
void vec_t<T>::pop_back() {
    if (size > 0) {
        --size;
    }
}

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

template<typename T>
size_t vec_t<T>::get_size() const {
    return size;
}

template<typename T>
size_t vec_t<T>::get_cap() const {
    return cap;
}

template<typename T>
T vec_t<T>::get_value(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("vec_t index out of range");
    }
    return data[index];
}

template<typename T>
bool vec_t<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void vec_t<T>::set_value(const T& value, size_t index) {
    if (index < size) {
        data[index] = value;
    }
}
