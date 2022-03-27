#include "Vehicle.h"


//--------------- Setters ---------------
void Vehicle::set_brand(const string brand) {
	this->brand = brand;
}

void Vehicle::set_model(const string model) {
	this->model = model;
}
void Vehicle::set_cost(const int cost) {
	this->cost = cost;
}

//--------------- Getters ---------------
string Vehicle::get_brand() const {
	return brand;
}

string Vehicle::get_model() const {
	return model;
}

int Vehicle::get_cost() const {
	return cost;
}

//------------ Constructors ------------
Vehicle::Vehicle() {
	brand = "";
	model = "";
	cost = 0;
}

Vehicle::Vehicle(const string n, const string s, const int sg) {	//Конструтор с параметрами
	brand = n;
	model = s;
	cost = sg;
}

Vehicle::Vehicle(const Vehicle &E) {	//Конструктор копирования T::T(const T&) {...}
	brand = E.brand;
	model = E.model;
	cost = E.cost;
}

Vehicle::~Vehicle() {}	//Деструктор создан только для выполнения задания. В данном случае его можно было не создавать. 

//------------ Other funcions ------------
void Vehicle::show() const {
	cout << "brand: " << get_brand() << endl;
	cout << "model: " << get_model() << endl;
	cout << "cost: " << get_cost() << endl;
}

bool CorrectInputCost(const string str, int &costInt) {
	if (!(all_of(str.begin(), str.end(), isdigit))) {	//проверяем все элементы строки на число
		cout << "Стоимость должна быть целым числом. Повторите ввод: \n>";
		return false;
	}
	try {	//Пробую на вкус обработку исключений. 
		costInt = stoi(str);
	}
	catch (const out_of_range &e) {
		cout << e.what() << "\nВведите число поменьше: \n>" ;

		return false;
	}

	return true;
}