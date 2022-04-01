#pragma once

class Object {
public:
    Object() = default;
    virtual ~Object();
    virtual void Show() = 0;
    virtual void Input() = 0;
};

Object::~Object() = default;



