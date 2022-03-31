#pragma once

#include "Vector.h"
#include "Event.h"

class Dialog : public Vector {
public:
// ------------------------- Constructors -------------------------- //

    //Dialog() { EndState = 0; }
    explicit Dialog(int);
    virtual ~Dialog();

// ---------------------------- Methods ---------------------------- //
    virtual void GetEvent(TEvent&);     //получить событие
    virtual int Execute();              //главный цикл обработки события
    virtual void HandleEvent(TEvent&);  //обработчик
    virtual void ClearEvent(TEvent&);   //очистить событие
    int Valid() const;                  //проверка атрибута EndState
    void EndExec() { EndState = 1; }    //обработка события "конец работы"
protected:
    int EndState;
};

