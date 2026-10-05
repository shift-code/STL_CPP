# Dynamic Vector Project

This project implements a simple dynamic array-based vector container in C++.

## Overview

The `stdvec::vec_t<T>` class stores elements in a dynamically allocated array and supports:

- adding elements to the front or back
- removing elements from the front or back
- getting and setting values by index
- checking the size and capacity
- printing elements
- clearing the vector

## Files

- `vec.h` — class declaration
- `vec.cpp` — method implementations

## Example

```cpp
#include "vec.h"
#include <iostream>

int main() {
    stdvec::vec_t<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_front(5);

    std::cout << "Size: " << v.get_size() << std::endl;
    std::cout << "First value: " << v.get_value(0) << std::endl;

    v.pop_back();
    v.print_all();

    return 0;
}
```

## Notes

- The vector starts with an initial capacity of `2`.
- When it becomes full, the internal array is reallocated with doubled capacity.
- Accessing an invalid index throws `std::out_of_range`.

## Build

Compile with:

```bash
g++ -std=c++17 vec.cpp main.cpp -o vector
```

If you want, you can also add a `main.cpp` file and test the vector with custom input.
