#pragma once
#include "iostream"
#include <initializer_list>

class List;

class Iterator {
	friend class List;	//Делаем доступными классу List все элементы.

public:

// ------------------------- Constructors -------------------------- //
	Iterator() { pElem = nullptr; }	//Создаём нулевой указатель
	Iterator(const Iterator& it) { pElem = it.pElem; }

// --------------------------- Overloads --------------------------- //
	Iterator& operator ++ ();	//Перемещает итератор к следующему элементу контейнера
	Iterator& operator -- ();	//Перемещает итератор к предыдущему элементу контейнера
	Iterator& operator-=(int);	//Перемещает итератор влево к элементу с номером n;
	int& operator * () { return *pElem; }	//Возвращает элемент, на который в данный момент указывает итератор.
	bool operator == (const Iterator& it) const { return pElem == it.pElem; }
	bool operator != (const Iterator& it) const { return pElem != it.pElem; }
	

private:
	int* pElem = nullptr;
};

class List {
public:

// ------------------------- Constructors -------------------------- //
	List();
	List(int);
	List(const List&);

	//Список инициализации для возможности создания экземпляра
	//класса, как какой-то массив элементов:
	// List l{1, 2, 345, 567, 2};
	List(const std::initializer_list<int>&);
	~List();

// --------------------------- Overloads --------------------------- //
	operator int() const;
	int& operator [] (int) const;
	List& operator = (const List&);
	friend std::istream& operator >> (std::istream&, List&);
	friend std::ostream& operator << (std::ostream&, const List&);

// --------------------------- Iterators --------------------------- //
	Iterator last() { return end; }		//возвращает указатель на первый элемент
	Iterator first() { return begin; }	//возвращает указатель на последний элемент

// ---------------------------- Methods ---------------------------- //
	void Erase();	//Очистить экземпляр класса.
	int GetSize() const { return size; }

private:
	int size = 0;	//размер массива
	int* pData;		//указатель на массив
	Iterator begin;
	Iterator end;

};