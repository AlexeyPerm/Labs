#pragma once
#include "iostream"
#include <initializer_list>

class List;

class Iterator {
	friend class List;	//������ ���������� ������ List ��� ��������.

public:

// ------------------------- Constructors -------------------------- //
	Iterator() { pElem = nullptr; }	//������ ������� ���������
	Iterator(const Iterator& it) { pElem = it.pElem; }

// --------------------------- Overloads --------------------------- //
	Iterator& operator ++ ();	//���������� �������� � ���������� �������� ����������
	Iterator& operator -- ();	//���������� �������� � ����������� �������� ����������
	Iterator& operator-=(int);	//���������� �������� ����� � �������� � ������� n;
	int& operator * () { return *pElem; }	//���������� �������, �� ������� � ������ ������ ��������� ��������.
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

	//������ ������������� ��� ����������� �������� ����������
	//������, ��� �����-�� ������ ���������:
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
	Iterator last() { return end; }		//���������� ��������� �� ������ �������
	Iterator first() { return begin; }	//���������� ��������� �� ��������� �������

// ---------------------------- Methods ---------------------------- //
	void Erase();	//�������� ��������� ������.
	int GetSize() const { return size; }

private:
	int size = 0;	//������ �������
	int* pData;		//��������� �� ������
	Iterator begin;
	Iterator end;

};