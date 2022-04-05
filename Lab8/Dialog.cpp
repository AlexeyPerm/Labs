#include "Dialog.h"
#include <string>
#include <iostream>

void Dialog::GetEvent(TEvent& event) {
    std::string opInt = "+-?s/qm";  //коды операций
    std::string s;
    std::string param;
    char code;

    std::cout << "+ add; - del; / get; m make; s show all; ?(num) show element; q quit;" << std::endl;
    std::cout << ">";
    std::cin >> s;
    code = s[0];    //первый символ команды

    if (opInt.find(code) >= 0) {
        event.what = evMessage;
        switch (code) {
            case 'm': {
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
            case 's': {
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
            case '?': {
                event.command = cmElemNumber;
                break;
            }
//            default: {
//                return;
//            }
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
                Tree::Add();
                ClearEvent(event);
                break;
            }
            case cmDel: {
                Tree::Del();
                ClearEvent(event);
                break;
            }
            case cmShow: {
                Tree::Show();
                ClearEvent(event);
                break;
            }
            case cmElemNumber: {
                Tree::ShowElementNumber(event.a);
                ClearEvent(event);
                break;
            }
            case cmQuit: {
                EndExec();
                ClearEvent(event);
                break;
            }
            default: {
                Tree::HandleEvent(event);
            }
        }
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
    if (EndState) {
        return 1;
    }
    return 0;
}

void Dialog::ClearEvent(TEvent& event) {
    event.what = evNothing;     //пустое событие.
}