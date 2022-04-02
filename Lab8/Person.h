#pragma once

#include <string>
#include "Object.h"
#include "Event.h"

#define DEBUG_PERSON

#ifdef DEBUG_PERSON
#include <iostream>
#endif //DEBUG_PERSON


class Person : public Object {
public:
// ------------------------- Constructors -------------------------- //
    Person() { name = "", age = 0; }
    Person(const Person&);              //копирование
    Person(const std::string&, int);    //с параметрами
#ifndef DEBUG_PERSON
    ~Person() override = default;
#else
    ~Person() override {
        std::cout << "Destructor for " << this << std::endl;
    }
#endif //DEBUG_STUDENT
// --------------------- Overridden Functions ---------------------- //
    void Show() override;
    void Input() override;
    void HandleEvent(const TEvent& e) override;
// --------------------------- Getters ----------------------------- //
    std::string GetName() const { return name; }
    int GetAge() const { return age; }
// --------------------------- Setters ----------------------------- //
    void SetAge(const int& a) { age = a; }
    void SetName(const std::string& n) { name = n; }
// --------------------- Overloaded Functions ---------------------- //
    Person& operator=(const Person&);

protected:
    int age;
    std::string name;
    static bool CheckCorrectInput(std::string&, bool isInt = true);
};

