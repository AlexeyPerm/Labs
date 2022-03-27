#pragma once
#include <fstream>
#include <string>
using namespace std;

class Triad
{
protected:
	int first;
	int second;
	int third;
	static bool InputValidation(const string &);

public:
	Triad();	//Конструктор по умолчанию
	Triad(const int, const int, const int);	//Конструктор с параметрами
	Triad(const Triad &);	//Конструктор копирования
	~Triad() = default;	//Деструктор
	virtual void Show() const;

	//--------- Setters ---------

	void set_first (const int);
	void set_second(const int);
	void set_third (const int);

	//--------- Getters ---------

	int get_first () const;
	int get_second() const;
	int get_third () const;

	//-- Operators overloading --
	Triad &operator = (const Triad &);
	friend ostream &operator << (ostream &out, const Triad &);
	friend istream &operator >> (istream &in, Triad &);

	//----- Other Functions -----
	virtual int FirstAddOne ();	//увеличение на единичку
	virtual int SecondAddOne();	//увеличение на единичку
	virtual int ThirdAddOne ();	//увеличение на единичку

};