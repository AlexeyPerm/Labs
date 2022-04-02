#pragma once
const int evNothing = 0;    //пустое событие
const int evMessage = 100;   //не пустое событие
const int cmAdd = 1;        //добавить объект в группу
const int cmDel = 2;        //удалить объект из группы
const int cmGet = 3;        //вывести атрибуты всех объектов
const int cmShow = 4;       //вывести всю группу
const int cmElemNumber = 5;       //вывести всю группу
const int cmMake = 6;       //создать группу
const int cmQuit = 101;     //выход

struct TEvent {
    int what;               //тип события
    union {
        int command;        //код команды
        struct {
            int message;
            int a;          //параметр команды
        };
    };
};

