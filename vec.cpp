#include <iostream>
#include <stdexcept>

template<typename T>
class vec_t{
public:
private:
    T *data;
    size_t size;
    size_t cap;
public:
    vec_t(){
        size = 0;
        cap = 2;
        data = new T[cap];
    }

    ~vec_t(){
        delete[] data;
    }

    vec_t(const vec_t&) = delete;
    vec_t& operator=(const vec_t&) = delete;

    void push_back(const T val){
        if(size == cap){
            cap*=2;
            T *newData = new T[cap];
            for(int i = 0;i<size;++i){
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = val;
        ++size;
    }

    void pop_back(){
        if(size > 0){
            --size;
        }
    }

    void push_front(const T x){
        if(size == cap){
            cap*=2;
            T *newData = new T[cap];
            for(int i = 0;i<size;++i){
                newData[i+1] = data[i];
            }
            delete[] data;
            data = newData;
        }
        else{
            for(size_t i = size;i > 0;--i){
                data[i] = data[i-1];
            }
        }
        data[0] = x;
        ++size;
    }

    void pop_front(){
        if(size == 0)return;
        for(int i = 0;i<size-1;++i){
            data[i] = data[i+1];
        }
        --size;
    }

    size_t get_size(){
        return size;
    }
    size_t get_cap(){
        return cap;
    }
    T get_value(size_t index){
        if(index >= size)throw std::out_of_range("vec_t index out of range");
        return data[index];
    }
    bool isEmpty(){
        return !size;
    }

    void set_value(T value,size_t index){
        if(!(index<size))return;
        data[index] = value;
    }
};