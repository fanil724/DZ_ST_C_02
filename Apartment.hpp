#ifndef APARTAMENT_H
#define APARTAMENT_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include "Human.hpp"

class Apartament {
public:
    Apartament() : size(0),
                   apartament_{new Human[size]} {}

    Apartament(const Human array[],
               const size_t new_size,
               const size_t argument_size)
            : size(new_size), apartament_(new Human[new_size]{}) {
        const size_t min_size = std::min(
                argument_size,
                new_size
        );
        for (size_t i = 0; i < min_size; i++) {
            apartament_[i] = array[i];
        }
    }

    Apartament(const Apartament &another)
            : Apartament(another.apartament_, another.size) {}


    Apartament &operator=(const Apartament &another) {
        if (&another == this)
            return *this;
        Apartament copy(another);
        std::swap(size, copy.size);
        std::swap(apartament_, copy.apartament_);
        return *this;
    }

    Apartament(Apartament &&another) noexcept
            : size(std::exchange(another.size, 0ull)),
              apartament_(std::exchange(another.apartament_, nullptr)) {}

    Apartament &operator=(Apartament &&another) noexcept {
        if (&another == this)
            return *this;
        delete[] apartament_;
        size = std::exchange(another.size, 0ull);
        apartament_ = std::exchange(another.apartament_, nullptr);
        return *this;
    }

    ~Apartament() {
        delete[] apartament_;
    };

    void Add(Human elment) {
        Human *arr = new Human[size + 1];
        if (size == 0) {
            arr[size] = elment;
        } else {
            for (int i = 0; i < size; i++) {
                arr[i] = apartament_[i];
            }
            arr[size] = elment;
        }
        size += 1;
        delete[] apartament_;
        apartament_ = arr;
    }

    Human &operator[](size_t index) {
        if (index >= size)
            throw std::out_of_range("Index is out of range");
        return apartament_[index];
    }

    const Human &operator[](size_t index) const {
        if (index >= size)
            throw std::out_of_range("Index is out of range");
        return apartament_[index];
    }

    void Remove(int index) {
        Human *arr = new Human[size - 1];
        for (int i = index; i < size - 1; i++) {
            arr[i] = apartament_[i + 1];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = apartament_[i];
        }
        size -= 1;
        delete[] apartament_;
        apartament_ = arr;
    }

    size_t &GetSize() {
        return size;
    }

    void PrintApartament() {
        for (int i = 0; i < size; i++) {
            apartament_[i].PrintHuman();
        }
    }

private:
    Apartament(const Human array[], const size_t size_)
            : size(size_), apartament_(new Human[size]) {
        for (size_t i = 0; i < size; i++)
            apartament_[i] = array[i];
    }

    size_t size = 0;
    Human *apartament_ = new Human[size];
};


#endif // APARTAMENT_H