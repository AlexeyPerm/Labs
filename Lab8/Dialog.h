#pragma once

#include "Tree.h"
#include "Event.h"


class Dialog : public Tree {
public:
// ------------------------- Constructors -------------------------- //
    //explicit Dialog(const int size) : Tree(size) { EndState = 0; }
    Dialog() : Tree() { EndState = 0; }
    ~Dialog() = default;;

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

