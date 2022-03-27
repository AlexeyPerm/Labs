#pragma once
#include <Windows.h>	//SetConsoleCP(1251);
#include <iostream>
#include <string>
#include <algorithm>	//используется функция all_of()
using namespace std;

class Vehicle {
private:
	string brand;
	string model;
	int cost;

public:
	Vehicle();					//Конструктор по умолчанию
	Vehicle(const string, const string, const int);	//Конструктор с параметрами
	Vehicle(const Vehicle &);			//Конструктор копирования
	~Vehicle();				//Деструктор
	void show() const;

	//--------- Setters ---------
	void set_brand(const string);
	void set_model(const string);
	void set_cost(const int);

	//--------- Getters ---------
	string get_brand() const;
	string get_model() const;
	int get_cost() const;
};

bool CorrectInputCost(const string, int &);	//Проверка корректности ввода цены. По условию цена должна быть типа int