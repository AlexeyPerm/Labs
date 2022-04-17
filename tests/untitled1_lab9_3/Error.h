#pragma once

#include <iostream>
#include <string>

class Error {
public:
    virtual void what() = 0;
private:
};

// ========================== Size Error =========================== //
class SizeError : public Error {    //ошибка в размере вектора
protected:
    std::string msg;
public:
    SizeError() { msg = "Size error \n"; }
};

class MaxSizeError : public SizeError {
protected:
    std::string msg_;
public:
    MaxSizeError() : SizeError() { msg_ = "Size > MAX_SIZE\n"; }

    void what() override { std::cout << msg << msg_; }
};

class EmptySizeError : public SizeError {
protected:
    std::string msg_;
public:
    EmptySizeError() : SizeError() { msg_ = "Vector is empty\n"; }

    void what() override { std::cout << msg << msg_; }
};

// ============================ Index ============================== //
class IndexError : public Error {   //ошибка в индексе вектора
protected:
    std::string msg;
public:
    IndexError() { msg = "Index Error\n"; }

    void what() override { std::cout << msg; }
};

class IndexError1 : public IndexError { // index < 0
protected:
    std::string msg_;
public:
    IndexError1() : IndexError() { msg_ = "Index < 0\n"; }

    void what() override { std::cout << msg << msg_; }
};

class IndexError2 : public IndexError { // index > vector.size
protected:
    std::string msg_;
public:
    IndexError2() : IndexError() { msg_ = "Index > Size\n"; }

    void what() override { std::cout << msg << msg_; }
};