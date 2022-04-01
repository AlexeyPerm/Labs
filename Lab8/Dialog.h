#pragma once

#include "Tree.h"
#include "Event.h"

class Dialog : public Tree {
public:
// ------------------------- Constructors -------------------------- //

    //Dialog() { EndState = 0; }
    explicit Dialog(int);
    virtual ~Dialog();

// ---------------------------- Methods ---------------------------- //
    virtual void GetEvent(TEvent&);     //�������� �������
    virtual int  Execute();              //������� ���� ��������� �������
    virtual void HandleEvent(TEvent&);  //����������
    virtual void ClearEvent(TEvent&);   //�������� �������
    int Valid() const;                  //�������� �������� EndState
    void EndExec() { EndState = 1; }    //��������� ������� "����� ������"
protected:
    int EndState;
};

