#include "calculation.h"
using namespace std;

calculation make_calculation(const double, const int, const int);

int main() {
	setlocale(LC_ALL, "rus");

	//--------------------- Method calculation::Init() --------------------

	calculation initCalc{};
	calculation initCalc_2{};
	cout << "\n------------ Method Init() ------------\n";
	initCalc.Init(4.54, 10, 30);
	initCalc_2.Init(4.54, 10, 28);
	cout << fixed << setprecision(2);
	initCalc.Show();
	cout << "Sum = " << initCalc.summa() << endl << endl;
	initCalc_2.Show();
	cout << "Sum = " << initCalc_2.summa() << endl;


	//------------------------- Pointer to Struct -------------------------
	// 
	//Создаём структуру и присваиваем её адрес указателю
	cout << "\n---------  Pointer to Struct ---------\n";
	calculation *pCalcPointer = new calculation{};
	pCalcPointer->Init(12, 25, 31);
	pCalcPointer->Show();
	cout << "Sum = " << pCalcPointer->summa() << endl;
	delete pCalcPointer;

	//--------------------------- Static Array ----------------------------

	cout << "\n---------  Static Array ---------\n";
	int const count = 2;
	calculation staticArrayCalc[count]{};

	//Пишут, что эта конструкция rfor() предпочтительнее, чем циклы for на основе индекса. Интересно было использовать. 
	//https://docs.microsoft.com/en-us/cpp/cpp/range-based-for-statement-cpp?view=msvc-170
	//https://en.cppreference.com/w/cpp/language/range-for
	for (auto &i : staticArrayCalc) {
		i.Read();
		i.Show();
		cout << "Sum = " << i.summa() << endl << endl;
	}

	//--------------------------- Dynamic Array ---------------------------

	cout << "---------  Dynamic Array ---------\n";
	calculation *dynamicArrayCalc = new calculation[count]{};
	for (int i = 0; i < count; i++) {
		dynamicArrayCalc[i].Read();
		dynamicArrayCalc[i].Show();
		cout << fixed << "Hypotenuse = " << dynamicArrayCalc[i].summa() << endl << endl;
	}
	delete[] dynamicArrayCalc;

	//---------------------- func make_calculation() ----------------------

	cout << "\n-------  func make_calculation() -------\n";
	double x{};
	int y{}, z{};
	cout << "Оклад: \n> ";
	cin >> x;
	cout << "Количество отработанных дней: \n> ";
	cin >> y;
	cout << "Количество дней в месяце: \n> ";
	cin >> z;
	calculation C = make_calculation(x, y, z);
	C.Show();
	cout << "Сумма = " << C.summa();

	return 0;
}

calculation make_calculation(const double F, const int S, const int D) {
	calculation tmp{};
	tmp.Init(F, S, D);
	return tmp;
}
