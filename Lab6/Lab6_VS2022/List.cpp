#include "List.h"
#include <string> 

// ------------------------- Constructors -------------------------- //

List::List() {
	size = 0;
	pData = nullptr;
	begin.pElem = nullptr;
	end.pElem = nullptr;
}

List::List(const int size) {
	if (size > 0) {
		this->size = size;
		pData = new int[size] {};
		begin.pElem = &pData[0];
		end.pElem = &pData[size - 1];
	}
	else {
		std::cout << "Error!!! Size <= 0\n";
		pData = nullptr;
	}
}

//initializer_list ����� ������� size(), ������� ���������� ����������
//��������� ������. ���������� �������������� ���� size_t -> int.
//���������� ����������� List::List(int);
List::List(const std::initializer_list<int>& l) : List(static_cast<int> (l.size())) {
	//��������� "Range-based for loop":
	//https://en.cppreference.com/w/cpp/language/range-for 
	int count = 0;
	for (auto& i : l) {
		pData[count] = i;
		count++;
	}
}

List::~List() {
	delete[] pData;
	pData = nullptr;
}

List::List(const List& l) {	//����������� �����������
	this->size = l.size;
	pData = new int[size] {};
	for (int i = 0; i < size; ++i) {
		this->pData[i] = pData[i];
	}
	begin = l.begin;
	end = l.end;
}

// --------------------------- Overloads --------------------------- //

List& List::operator=(const List& l) {	//����������� ������������
	if (this == &l) {	//�������� �� ����������������
		return *this;
	}
	if (pData) {
		delete[] pData;	//���� ���� �� Null, �� ����������� ������.
	}

	size = l.size;
	pData = new int[size];
	for (int i = 0; i < size; ++i) {
		pData[i] = l.pData[i];
	}

	begin = l.begin;
	end = l.end;
	return *this;
}

int& List::operator[](const int index) const {
	if (size > index) {
		return pData[index];
	}
	else {
		std::cout << "\nError! Index > size\nExit..." << std::endl;
		exit(0);
	}
}

std::ostream& operator<<(std::ostream& out, const List& l) {
	for (int i = 0; i < l.size; ++i) {
		out << l.pData[i] << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, List& l) {
	for (int i = 0; i < l.size; ++i) {
		std::cout << "> ";
		in >> l.pData[i];
	}
	return in;
}

List::operator int() const {
	return size;
}

//� ����� � ������������ ������� �� �����-�� ������� ��������� � ��������� �������������
//�� ������ ���������. �� ����������� ������ ������������ ������ �� ������.
//https://en.cppreference.com/w/cpp/language/operator_incdec
Iterator& Iterator::operator++() {
	++pElem;
	return *this;
}

Iterator& Iterator::operator--() {
	--pElem;
	return *this;
}


Iterator& Iterator::operator-=(const int n) {	//���������.
	pElem -=n;
	return *this;
}

// ---------------------------- Methods ---------------------------- //

void List::Erase() {
	delete[] pData;
	size = 0;
	pData = nullptr;
	begin.pElem = nullptr;
	end.pElem = nullptr;
}