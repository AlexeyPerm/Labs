#include "Vehicle.h"


Vehicle make_Vehicle();
//bool CorrectInputCost(const string, int &);

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	cout << "\n=================== Without parameters ===================\n\n";
	Vehicle first;
	first.show();

	cout << "\n===================== With parameters =====================\n\n";
	Vehicle second("ВАЗ", "2101", 1330);
	second.show();

	cout << "\n================== Copy (initialization) =================\n\n";
	Vehicle third = second;
	third.set_brand("Kia");
	third.set_model("Seltos");
	third.set_cost(9965);
	third.show();
	cout << "Адрес элемента: " << &third << endl;

	cout << "\n============= Copy (class as class parameter) ============\n\n";
	Vehicle fourth(third);
	fourth.show();
	cout << "Адрес элемента: " << &fourth << endl;

	cout << "\n===================== Copy (function) ====================\n\n";
	first = make_Vehicle();
	cout << endl;
	first.show();

	return 0;
}

Vehicle make_Vehicle() {
	string n{}, s{}, costString{};
	int costInt{};
	cout << "Введите марку: \n>";
	getline(cin, n);
	cout << "Введите модель: \n>";
	getline(cin, s);
	cout << "Введите стоимость: \n>";
	getline(cin, costString);
	while (!CorrectInputCost(costString, costInt)) {
		getline(cin, costString);
	}

	Vehicle temp(n, s, costInt);
	return temp;
}