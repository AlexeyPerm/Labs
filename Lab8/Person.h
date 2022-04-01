#pragma once

#include <string>
#include "Object.h"

class Person : public Object {
public:
// ------------------------- Constructors -------------------------- //
    Person() { name = "", age = 0; }

    Person(const Person&);              //копирование
    Person(const std::string&, int);    //с параметрами
    ~Person() override;
// --------------------- Overridden Functions ---------------------- //
    void Show() override;
    void Input() override;
    //void HandleEvent(const TEvent & e) override;

// --------------------------- Getters ----------------------------- //
    std::string GetName() const { return name; }

    int GetAge() const { return age; }

// --------------------------- Setters ----------------------------- //
    void SetName(const std::string&);
    void SetAge(const int&);

// --------------------- Overloaded Functions ---------------------- //
    Person& operator=(const Person&);
protected:
    int age{};
    std::string name;
    static bool CheckCorrectInput(std::string&, bool isInt = true);
};

