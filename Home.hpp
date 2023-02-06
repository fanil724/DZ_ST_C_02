#ifndef HOME_H
#define HOME_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include "Apartment.hpp"

class Home {
public:
    Home() : size(0),
             home_{new Apartament[size]} {}

    Home(const Apartament array[],
         const size_t new_size,
         const size_t argument_size)
            : size(new_size), home_(new Apartament[new_size]{}) {
        const size_t min_size = std::min(
                argument_size,
                new_size
        );
        for (size_t i = 0; i < min_size; i++) {
            home_[i] = array[i];
        }
    }

    Home(const Home &another)
            : Home(another.home_, another.size) {}


    Home &operator=(const Home &another) {
        if (&another == this)
            return *this;
        Home copy(another);
        std::swap(size, copy.size);
        std::swap(home_, copy.home_);
        return *this;
    }

    Home(Home &&another) noexcept
            : size(std::exchange(another.size, 0ull)),
              home_(std::exchange(another.home_, nullptr)) {}

    Home &operator=(Home &&another) noexcept {
        if (&another == this)
            return *this;
        delete[] home_;
        size = std::exchange(another.size, 0ull);
        home_ = std::exchange(another.home_, nullptr);
        return *this;
    }

    ~Home() {
        delete[] home_;
    };

    void Add(Apartament elment) {
        Apartament *arr = new Apartament[size + 1];
        if (size == 0) {
            arr[size] = elment;
        } else {
            for (int i = 0; i < size; i++) {
                arr[i] = home_[i];
            }
            arr[size] = elment;
        }
        size += 1;
        delete[] home_;
        home_ = arr;
    }

    void Remove(int index) {
        Apartament *arr = new Apartament[size - 1];
        for (int i = index; i < size - 1; i++) {
            arr[i] = home_[i + 1];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = home_[i];
        }
        size -= 1;
        delete[] home_;
        home_ = arr;
    }

    Apartament &operator[](size_t index) {
        return home_[index];
    }

    void PrintHome() {
        for (int j = 0; j < size; j++) {
            std::cout << "Apartament: " << j + 1 << std::endl;
            for (int i = 0; i < home_[j].GetSize(); i++) {
                home_[j][i].PrintHuman();
            }
        }
    }

private:
    Home(const Apartament array[], const size_t size_)
            : size(size_), home_(new Apartament[size]) {
        for (size_t i = 0; i < size; i++)
            home_[i] = array[i];
    }

    size_t size = 0;
    Apartament *home_ = new Apartament[size];
};

#endif // HOME_H