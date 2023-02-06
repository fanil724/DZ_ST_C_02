#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

class Human {
public:
    Human() : Name_{new char[1]{""}}, SurName_{new char[1]{""}},
              Age_(0), Mobile_phone_{new char[1]{""}},
              information_{new char[1]{""}} {};

    Human(const char *Name, const char *SurName, const int Age, const char *Mobile_phone)
            : Age_(Age), information_{new char[1]{""}} {
        const size_t sizeName = strlen(Name) + 1;
        Name_ = new char[sizeName];
        strcpy_s(Name_, sizeName, Name);
        const size_t sizeHome = strlen(SurName) + 1;
        SurName_ = new char[sizeHome];
        strcpy_s(SurName_, sizeHome, SurName);
       const size_t sizeMobile = strlen(Mobile_phone) + 1;
        Mobile_phone_ = new char[sizeMobile];
        strcpy_s(Mobile_phone_, sizeMobile, Mobile_phone);
    }

    Human(const char *Name, const char *SurName, const int Age, const char *Mobile_phone, const char *information) :
            Human(Name, SurName, Age, Mobile_phone) {
        delete[] information_;
        const size_t sizeInfo = strlen(information) + 1;
        information_ = new char[sizeInfo];
        strcpy_s(information_, sizeInfo, information);
    }

    Human(const Human &human) : Human(human.Name_, human.SurName_,
                                      human.Age_, human.Mobile_phone_,
                                      human.information_) {}

    Human &operator=(const Human &human) noexcept {
        Human human_copy(human);
        this->sswap(human_copy);
        return *this;
    }

    Human(Human &&human) : Human(human.Name_, human.SurName_,
                                 human.Age_, human.Mobile_phone_,
                                 human.information_) {
        human.Name_ = nullptr;
        human.SurName_ = nullptr;
        human.Age_ = 0;
        human.Mobile_phone_ = nullptr;
        human.information_ = nullptr;
    }

    Human &operator=(Human &&human) noexcept {
        if (this == &human)
            return *this;
        delete[] Name_;
        delete[] SurName_;
        delete[] Mobile_phone_;
        delete[] information_;

        Name_ = human.Name_;
        SurName_ = human.SurName_;
        Age_ = human.Age_;
        Mobile_phone_ = human.Mobile_phone_;
        information_ = human.information_;

        human.Name_ = nullptr;
        human.SurName_ = nullptr;
        human.Age_ = 0;
        human.Mobile_phone_ = nullptr;
        human.information_ = nullptr;

        return *this;
    }

    ~Human() {
        delete[] Name_;
        delete[] SurName_;
        delete[] Mobile_phone_;
        delete[] information_;
    }

    void sswap(Human &another) noexcept {
        using std::swap;

        swap(another.Name_, Name_);
        swap(another.SurName_, SurName_);
        swap(another.Age_, Age_);
        swap(another.Mobile_phone_, Mobile_phone_);
        swap(another.information_, information_);
    }

    void Show(const char *ch) {
        size_t size = strlen(ch);
        for (size_t i = 0; i < size; i++) {
            std::cout << ch[i];
        }
        std::cout << std::endl;
    }

    void SetName(const char *Name) {
        const size_t size = strlen(Name) + 1;
        delete[] Name_;
        Name_ = new char[size];
        strcpy_s(Name_, size, Name);
    }

    void SetSurName(const char *SurName) {
        const size_t size = strlen(SurName) + 1;
        delete[] SurName_;
        SurName_ = new char[size];
        strcpy_s(SurName_, size, SurName);
    }

    void SetAge(uint8_t age) {
        Age_ = age;
    }

    void SetPhone(const char *Phone) {
        const size_t size = strlen(Phone) + 1;
        delete[] Mobile_phone_;
        Mobile_phone_ = new char[size];
        strcpy_s(Mobile_phone_, size, Phone);
    }

    void SetInfo(const char *info) {
        const size_t size = strlen(info) + 1;
        delete[] information_;
        information_ = new char[size];
        strcpy_s(information_, size, info);
    }

    [[nodiscard]] inline const char *GetName() {
        return Name_;
    }

    [[nodiscard]] inline const char *GetSurName() {
        return SurName_;
    }

    [[nodiscard]] inline const int GetAge() {
        return Age_;
    }

    [[nodiscard]] inline const char *GetPhone() {
        return Mobile_phone_;
    }

    [[nodiscard]] inline const char *GetInfo() {
        return information_;
    }


    void PrintHuman() {
        std::cout << "Name: ";
        Show(Name_);
        std::cout << "SurName: ";
        Show(SurName_);
        std::cout << "Age: ";
        std::cout<<Age_<<std::endl;
        std::cout << "Mobile phone: ";
        Show(Mobile_phone_);
        std::cout << "Info: ";
        Show(information_);
        std::cout << std::endl;
    }

private:
    char *Name_;
    char *SurName_;
    int Age_;
    char *Mobile_phone_;
    char *information_;
};

#endif // HUMAN_H