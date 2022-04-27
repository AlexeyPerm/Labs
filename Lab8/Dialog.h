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
    virtual int Execute();             //главный цикл обработки события
    virtual void GetEvent(TEvent&);     //получить событие
    virtual void ClearEvent(TEvent&);   //очистить событие
    virtual void HandleEvent(TEvent&);  //обработчик

    int Valid() const;                  //проверка атрибута EndState
    void EndExec() { EndState = 1; }    //обработка события "конец работы"
protected:
    int EndState;
};