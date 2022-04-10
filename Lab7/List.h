#pragma once

#include "istream"
#include "iostream"

using namespace std;

template<class T>
class List;

template<class T>
ostream& operator<<(ostream& out, const List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        out << v.data[i] << endl;
    }
    return out;
}

template<class T>
istream& operator>>(istream& in, List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        in >> v.data[i];
    }
    return in;
}

template<class T>
class List {
public:
// ------------------------- Constructors -------------------------- //
    List(int, T);

    [[maybe_unused]] List(const List<T>&);

    ~List();

// --------------------------- Overloads --------------------------- //
    List operator+(T list);

    T& operator[](int) const; //ïåðåãðóçêà èíäåêñèðîâàíèÿ

    explicit operator int() const;

    List& operator=(const List<T>&);

    //Òàê êàê ìû îáúÿâëÿåì ñïåöèàëèçàöèþ äðóãîì, òî ìû ìîæåì âûíåñòè
    //îïðåäåëåíèå (èëè òîëüêî îáúÿâëåíèå) îáùåãî øàáëîíà äî êëàññà List
    //https://ru.stackoverflow.com/a/495222
    friend ostream& operator<<<T>(ostream&, const List<T>&);

    friend istream& operator>><T>(istream&, List<T>&);

private:
    int size = 0;   //ðàçìåð ñïèñêà
    T* data = nullptr;  //óêàçàòåëü íà ìàññèâ ýëåìåíòîâ ñïèñêà
};

/*
Ðàçìåùåíèå êîäà èç List.cpp â List.h ñäåëàåò List.h ñëèøêîì
áîëüøèì/áåñïîðÿäî÷íûì. Àëüòåðíàòèâîé áóäåò ïåðåèìåíîâàíèå
List.cpp â List.inl (.inl îò àíãë. "inline" = "âñòðîåííûé"),
à çàòåì ïîäêëþ÷åíèå List.inl èç íèæíåé ÷àñòè ôàéëà List.h.
Ýòî äàñò òîò æå ðåçóëüòàò, ÷òî è ðàçìåùåíèå âñåãî êîäà â
çàãîëîâî÷íîì ôàéëå, íî êîä ïîëó÷èòñÿ íåìíîãî ÷èùå.
 */
#include "List.inl"
