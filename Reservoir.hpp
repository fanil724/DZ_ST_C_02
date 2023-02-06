#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

class Reservoir {
public:
    explicit Reservoir() : Name_{new char[1]{""}}, type_{new char[1]{""}}, width_{0}, length_{0}, maximum_depth_{0} {}

    explicit  Reservoir(const char *Name, const uint32_t width,
              const uint32_t length, uint32_t maximum_depth)
            : type_{new char[1]{""}}, width_(width), length_(length), maximum_depth_(maximum_depth) {
        const size_t sizeName = strlen(Name) + 1;
        Name_ = new char[sizeName];
        strcpy_s(Name_, sizeName, Name);
        SetType();
    }

    Reservoir(const Reservoir &res) : Reservoir(res.Name_, res.width_,
                                                res.length_, res.maximum_depth_) {}

    Reservoir &operator=(const Reservoir &res) noexcept {
        Reservoir res_copy(res);
        this->sswap(res_copy);
        return *this;
    }

    Reservoir(Reservoir &&res) : Reservoir(res.Name_, res.width_,
                                           res.length_, res.maximum_depth_) {
        res.Name_ = nullptr;
        res.type_ = nullptr;
        res.width_ = 0;
        res.length_ = 0;
        res.maximum_depth_ = 0;

    }

    Reservoir &operator=(Reservoir &&res) noexcept {
        if (this == &res)
            return *this;
        delete[] Name_;
        delete[] type_;
        Name_ = res.Name_;
        type_ = res.type_;
        width_ = res.width_;
        length_ = res.length_;
        maximum_depth_ = res.maximum_depth_;
        res.Name_ = nullptr;
        res.type_ = nullptr;
        res.width_ = 0;
        res.length_ = 0;
        res.maximum_depth_ = 0;
        return *this;
    }

    void sswap(Reservoir &another) noexcept {
        using std::swap;
        swap(another.Name_, Name_);
        swap(another.type_, type_);
        swap(another.width_, width_);
        swap(another.length_, length_);
        swap(another.maximum_depth_, maximum_depth_);

    }

    ~Reservoir() {
        delete[] Name_;
        delete[] type_;
    }

    void SetWidth(uint32_t width) {
        width_ = width;
    }

    void SetAge(uint32_t length) {
        length_ = length;
    }

    void SetMaximumDepth(uint32_t Depth) {
        maximum_depth_ = Depth;
    }

    void SetName(const char *name) {
        const size_t size = strlen(name) + 1;
        delete[] Name_;
        Name_ = new char[size];
        strcpy_s(Name_, size, name);
    }

    [[nodiscard]] inline const uint32_t GetWidth(uint32_t width) {
        return width_;
    }

    [[nodiscard]] inline const uint32_t GetAge(uint32_t length) {
        return length_;
    }

    [[nodiscard]] inline const uint32_t GetMaximumDepth(uint32_t Depth) {
        return maximum_depth_;
    }

    [[nodiscard]] inline const char *GetName(const char *name) {
        return Name_;
    }

    void WriteFile() {
        std::ofstream out;
        out.open("Reservoir.txt", std::ios::app);
        if (out.is_open()) {
            out << Name_ << " " << type_ << " " << width_ << " " << length_ << " " << maximum_depth_ << " "
                << " \0" << std::endl;
        }
        out.close();
    }

    void SetType() {
        uint64_t V = reservoirVolume();
        if (V >= 100000) {
            const size_t size = strlen("reservoirs") + 1;
            delete[] type_;
            type_ = new char[size];
            strcpy_s(type_, size, "reservoirs");
        } else {
            const size_t size = strlen("ponds") + 1;
            delete[] type_;
            type_ = new char[size];
            strcpy_s(type_, size, "ponds");
        }
    }

    bool type_comparison(Reservoir res) {
        if (strcmp(type_, res.type_)==0) {
            return true;
        } else {
            return false;
        }
    }

    Reservoir area_comparison(Reservoir res) noexcept {
        if (type_comparison(res)) {
            if (reservoirS() > res.reservoirS()) {
                return *this;
            } else {
                return res;
            }
        } else {
            throw std::out_of_range("reservoirs are not of the same type!!");
        }
    }

    void PrintReservoir() {
        std::cout << "Name reservoires: " << Name_ << std::endl;
        std::cout << "Type reservoires: " << type_ << std::endl;
        std::cout << "Width reservoires: " << width_ << std::endl;
        std::cout << "Length reservoires: " << length_ << std::endl;
        std::cout << "Maximum depth reservoires: " << maximum_depth_ << std::endl;
    }

    const uint32_t reservoirVolume() {
        return (width_ * length_ * maximum_depth_);
    }

    const uint32_t reservoirS() {
        return (width_ * length_);
    }

private:
    char *Name_;
    char *type_;
    uint32_t width_;
    uint32_t length_;
    uint32_t maximum_depth_;
};

#endif // RESERVOIR_H