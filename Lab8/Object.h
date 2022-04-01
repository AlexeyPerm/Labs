#pragma once

class Object {
public:
    Object() = default;
    virtual ~Object() = default;
    virtual void Show() = 0;
    virtual void Input() = 0;
};




