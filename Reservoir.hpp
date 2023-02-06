#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

class Reservoir {
public:
    Reservoir() : Name_{new char[1]{""}}, width_{0}, length_{0}, maximum_depth_{0} {}

    Reservoir(const char *Name, const uint32_t width,
              const uint32_t length, uint32_t maximum_depth)
            : width_(width), length_(length), maximum_depth_(maximum_depth) {
        const size_t sizeName = strlen(Name) + 1;
        Name_ = new char[sizeName];
        strcpy_s(Name_, sizeName, Name);
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
        res.width_ = 0;
        res.length_ = 0;
        res.maximum_depth_ = 0;

    }

    Reservoir &operator=(Reservoir &&res) noexcept {
        if (this == &res)
            return *this;
        delete[] Name_;
        Name_ = res.Name_;
        width_ = res.width_;
        length_ = res.length_;
        maximum_depth_ = res.maximum_depth_;
        res.Name_ = nullptr;
        res.width_ = 0;
        res.length_ = 0;
        res.maximum_depth_ = 0;
        return *this;
    }
    void sswap(Reservoir &another) noexcept {
        using std::swap;
        swap(another.Name_, Name_);
        swap(another.width_, width_);
        swap(another.length_, length_);
        swap(another.maximum_depth_, maximum_depth_);

    }

    ~Reservoir() {
        delete[] Name_;
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

    const uint32_t  reservoirVolume(){
        return (width_*length_*maximum_depth_);
    }
    const uint32_t  reservoirS(){
        return (width_*length_);
    }
private:
    char *Name_;
    uint32_t width_;
    uint32_t length_;
    uint32_t maximum_depth_;
};

#endif // RESERVOIR_H