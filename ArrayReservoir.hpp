#ifndef ARRAYRESERVOIR_H
#define ARRAYRESERVOIR_H

#include <iostream>
#include <string>
#include "Reservoir.hpp"


class ArrayReservoir {
public:
    ArrayReservoir() : size(0),
                       arrayreservoir_{new Reservoir[size]} {}


    ArrayReservoir(const ArrayReservoir &another)
            : ArrayReservoir(another.arrayreservoir_, another.GetSize()) {}

    ArrayReservoir(ArrayReservoir &&another) noexcept
            : size(std::exchange(another.size, 0ull)),
              arrayreservoir_(std::exchange(another.arrayreservoir_, nullptr)) {}

    ArrayReservoir &operator=(ArrayReservoir &&another) noexcept {
        if (&another == this)
            return *this;
        delete[] arrayreservoir_;
        size = std::exchange(another.size, 0ull);
        arrayreservoir_ = std::exchange(another.arrayreservoir_, nullptr);
        return *this;
    }

    ~ArrayReservoir() {
        delete[] arrayreservoir_;
    };

    void Add(Reservoir elment) {
        Reservoir *arr = new Reservoir[size + 1];
        if (size == 0) {
            arr[size] = elment;
        } else {
            for (int i = 0; i < size; i++) {
                arr[i] = arrayreservoir_[i];
            }
            arr[size] = elment;
        }
        size += 1;
        delete[] arrayreservoir_;
        arrayreservoir_ = arr;
    }

    size_t Search(const char *names) {
        for (int i = 0; i < size; i++) {
            if (strcmp(names, arrayreservoir_[i].GetName()) == 0) {
                return i;
            }
        }
        return -1;
    };

    Reservoir &operator[](size_t index) {
        return arrayreservoir_[index];
    }

    const size_t &GetSize() const {
        return size;
    }

    size_t &GetSize() {
        return size;
    }

    void Remove(int index) {
        Reservoir *arr = new Reservoir[size - 1];
        for (int i = index; i < size - 1; i++) {
            arr[i] = arrayreservoir_[i + 1];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = arrayreservoir_[i];
        }
        size -= 1;
        delete[] arrayreservoir_;
        arrayreservoir_ = arr;
    }

    void PrintPhoneBook() {
        for (int i = 0; i < size; i++) {
            arrayreservoir_[i].PrintContact();
        }
    }


    void WritePhonebook() {
        for (int i = 0; i < size; i++) {
            arrayreservoir_[i].WriteFile();
        }
    }


private:
    ArrayReservoir(const Reservoir array[], const size_t size_)
            : size(size_), arrayreservoir_(new Reservoir[size]) {
        for (size_t i = 0; i < size; i++)
            arrayreservoir_[i] = array[i];
    }

    size_t size = 0;
    Reservoir *arrayreservoir_ = new Reservoir[size];
};

#endif // ARRAYRESERVOIR_H