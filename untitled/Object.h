#pragma once

class Object {
public:
    Object();
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual ~Object();
};

