#include "Dialog.h"
#include <string>
#include <iostream>

Dialog::Dialog(const int size) : Tree(size){
    EndState = 0;
}

Dialog::~Dialog() = default;

void Dialog::GetEvent(TEvent& event) {
    std::string opInt = "+-?/qm";  //коды операций
    std::string s;
    std::string param;
    char code;

    std::cout << "+ add; - del; / get; m make; ? show; q quit;" << std::endl;
    std::cout << ">";
    std::cin >> s;
    code = s[0];    //первый символ команды

    if (opInt.find(code) >= 0) {
        event.what = evMessage;
        switch (code) {
            case 'm': {
                std::cout << "Enter size: ";
                std::cin >> event.a;
                event.command = cmMake;
                break;
            }
            case '+': {
                event.command = cmAdd;
                break;
            }
            case '-': {
                event.command = cmDel;
                break;
            }
            case '?': {
                event.command = cmShow;
                break;
            }
            case 'q': {
                event.command = cmQuit;
                break;
            }
            case '/': {
                event.command = cmGet;
                break;
            }
            default: {
                return;
            }
        }

        if (s.length() > 1) {
            param = s.substr(1, s.length() - 1);
            int a = atoi(param.c_str());
            event.a = a;
        }
    } else {
        event.message = evNothing;
    }
}

int Dialog::Execute() {
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);
    } while (!Valid());
    return EndState;
}

int Dialog::Valid() const {
    if (EndState == 0) {
        return 0;
    } else {
        return 1;
    }
}

void Dialog::ClearEvent(TEvent& event) {
    event.what = evNothing;     //пустое событие.
}

void Dialog::HandleEvent(TEvent& event) {
    if (event.what == evMessage) {
        switch (event.command) {
            case cmMake: {
                size = event.a;     //размер группы
                begin = new Object* [size];
                current = 0;
                ClearEvent(event);
                break;
            }
            case cmAdd: {
                Add();
                ClearEvent(event);
                break;
            }
            case cmDel: {
                Del();
                ClearEvent(event);
                break;
            }
            case cmShow: {
                Show();
                ClearEvent(event);
                break;
            }
            case cmQuit: {
                EndExec();
                ClearEvent(event);
                break;
            }
            case '/': {
                event.command = cmGet;
                break;

            }
            default:{
                Tree::HandleEvent(event);
            }
        }
    }
}