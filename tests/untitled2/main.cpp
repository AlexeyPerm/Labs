#include <iostream>
#include <vector>
class A {
public:
    virtual void foo() { std::cout << "A::foo\n"; }
};

class B: public A {
public:
    void foo() override { std::cout << "B::foo\n"; }
};

class C: public B {
public:
    void foo() override { std::cout << "C::foo\n"; }
};



int main(){
std::vector<int> v;
    for (const auto& item: v){

    }

    return 0;
}