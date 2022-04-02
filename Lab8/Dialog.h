#pragma once

#include "Tree.h"
#include "Event.h"

#define DEBUG_DIALOG

#ifdef DEBUG_DIALOG
#include <iostream>
#endif //DEBUG_DIALOG

class Dialog : public Tree {
public:
// ------------------------- Constructors -------------------------- //
    explicit Dialog(const int size) : Tree(size) { EndState = 0; }
#ifndef DEBUG_DIALOG
    virtual ~Dialog() = default;
#else
    ~Dialog() {
        std::cout << "Destructor for " << this << std::endl;
    }
#endif //DEBUG_DIALOG
// ---------------------------- Methods ---------------------------- //
    virtual void GetEvent(TEvent&);     //получить событие
    virtual int Execute();             //главный цикл обработки события
    virtual void HandleEvent(TEvent&);  //обработчик
    virtual void ClearEvent(TEvent&);   //очистить событие
    int Valid() const;                  //проверка атрибута EndState
    void EndExec() { EndState = 1; }    //обработка события "конец работы"
protected:
    int EndState;
};

