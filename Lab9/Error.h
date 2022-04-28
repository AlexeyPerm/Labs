#pragma once

#include <iostream>
#include <string>

#define OPTION 3  //Вариант реализации (2 или 3)

#if OPTION == 2

class Error {
    std::string str;
public:
    explicit Error(std::string s) { str = s; }
    void what() { std::cout << str << std::endl; }
};

#elif OPTION == 3

class Error {
public:
    virtual void what() = 0;
private:
};

// ========================== Size Error =========================== //
class SizeError : public Error {    //ошибка в размере списка
protected:
    std::string msg;
public:
    SizeError() { msg = "Size error!\n"; }
};

class NegativeSizeError : public SizeError {
protected:
    std::string msg_;
public:
    NegativeSizeError() : SizeError() { msg_ = "Size < 0\n"; }

    void what() override { std::cout << msg << msg_; }
};

class EmptySizeError : public SizeError {
protected:
    std::string msg_;
public:
    EmptySizeError() : SizeError() { msg_ = "List is empty\n"; }

    void what() override { std::cout << msg << msg_; }
};

// ============================ Index ============================== //
class IndexError : public Error {   //ошибка в индексе вектора
protected:
    std::string msg;
public:
    IndexError() { msg = "Index Error!\n"; }

    void what() override { std::cout << msg; }
};

class NegativeIndexError : public IndexError { // index < 0
protected:
    std::string msg_;
public:
    NegativeIndexError() : IndexError() { msg_ = "Index < 0\n"; }

    void what() override { std::cout << msg << msg_; }
};

class OversizeIndexError : public IndexError { // index > list.size
protected:
    std::string msg_;
public:
    OversizeIndexError() : IndexError() { msg_ = "Index > Size\n"; }

    void what() override { std::cout << msg << msg_; }
};

#endif //OPTION