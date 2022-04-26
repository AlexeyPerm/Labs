#include <string>
#include <iomanip>	//setw(), setfill()
#include <algorithm>	//replace()
#include "money.h"

//------------------- Setters -------------------
void Money::set_ruble(const long r) {
    rubles = r;
//Функция принимает ссылку на вызывающий экземпляр класса. Передаём разыменованный указатель на него.
	ConvertRubleAndKopeksToTotal(*this);
}

void Money::set_kopeks(const int k) {
	kopeks = k;
	ConvertRubleAndKopeksToTotal(*this);	
}
//------------------- Getters -------------------
long Money::get_ruble() const {
	return rubles;
}

int Money::get_kopeks() const {
	return kopeks;
}

//---------------- Constructors -----------------
Money::Money() {
    rubles = 0;
	kopeks = 0;
	ConvertRubleAndKopeksToTotal(*this);
}

Money::Money(const long ruble, const int kopeks) {
	this->rubles = ruble;	//присваиваем заданное кол-во рублей соответствующей переменной в текущем экземпляре класса.
	if (kopeks < 0 || kopeks > 100) {
        std::cout << "Не корректное кол-во копеек. Обнуляем значение\n";
	}
	else {
		this->kopeks = kopeks;	//присваиваем заданное кол-во копеек соответствующей переменной в текущем экземпляре класса. 
	}
	ConvertRubleAndKopeksToTotal(*this);
}

Money::Money(const Money &M) {	//Конструктор копирования T::T(const T&) {...}
	rubles = M.rubles;
	kopeks = M.kopeks;
}

//---------------- Overloadings -----------------
bool Money::operator < (const Money &other) const {
	return (this->totalRubleAndKopeks < other.totalRubleAndKopeks);
}

bool Money::operator > (const Money &other) const {
	return (this->totalRubleAndKopeks > other.totalRubleAndKopeks);
}

Money &Money::operator++() {
//Прибавляем копейку. Так как работаем уже с вещественным числом, то и прибавляем одну сотую часть, коей и является копейка.


	return *this;
}

Money Money::operator++(int) {
	Money tmp(*this);
	this->totalRubleAndKopeks += 0.01;
	return tmp;
}

Money &Money::operator = (const Money &other) {
	this->rubles = other.rubles;
	this->kopeks = other.kopeks;
	ConvertRubleAndKopeksToTotal(*this);
	return *this;
}

std::istream &operator >> (std::istream &in, Money &M) {
    std::string r{}, k{};
    std::cout << "Введите рубли \n>";
	in >> r;
    std::cout << "Введите копейки \n>";
	in >> k;
	while (!CorrectInput(r, k, M)) {	//передаём введённые значения рублей, копеек и текущий экземлпляр класса. 
        std::cout << "Повторите ввод. \nВведите рубли: \n>";
		in >> r;
        std::cout << "Введите копейки: \n>";
		in >> k;
	}
	ConvertRubleAndKopeksToTotal(M);
	return in;
}

std::ostream& operator<<(std::ostream& out,  const Money& m) {
    std::cout << m.rubles << ",";
    if (m.kopeks < 10) {
        std::cout << "0";
    }
    std::cout << m.kopeks;
    return out;
}

//--------------- Other functions ---------------
void Money::show() const{
    std::cout << rubles << ",";
    if (kopeks < 10) {
        std::cout << "0";
    }
    std::cout << kopeks;
//    std::wcout.imbue(std::locale("ru"));
//    std::wcout << std::fixed << std::setprecision(2) << totalRubleAndKopeks << " р." << std::endl;
}

bool CorrectInput(std::string &sRuble, const std::string &sKopeks, Money &M) {

	if (sRuble[0] == '-') {	//если ввели отриц. значение, то избавляемся от минуса, для проверки строки на числа, иначе all_of() всегда будет возвращать false;
        std::string tmp = sRuble;
		tmp = tmp.erase(0, 1);
		if (!(all_of(tmp.begin(), tmp.end(), isdigit))) {	//проверяем все элементы строки на число
            std::cout << "Ошибка при вводе кол-ва рублей. Необходимо ввести число";
			return false;
		}
	}
	else if ((!(all_of(sRuble.begin(), sRuble.end(), isdigit)))) {
        std::cout << "Ошибка при вводе кол-ва рублей. Необходимо ввести число.\n>";
		return false;
	}
	if (sKopeks[0] == '-') {
        std::string tmp = sKopeks;
		tmp = tmp.erase(0, 1);
		if ((!(all_of(tmp.begin(), tmp.end(), isdigit)))) {
            std::cout << "Ошибка при вводе кол-ва копеек.\n";
			return false;
		}
	}
	else if ((!(all_of(sKopeks.begin(), sKopeks.end(), isdigit)))) {
        std::cout << "Ошибка при вводе кол-ва копеек.\n";
		return false;
	}
	//-------------- - rubles-------------- -
	try {
		M.rubles = stol(sRuble);
	}
	catch (const std::invalid_argument &e) {
        std::cout << e.what() << "\nНекорректное значение.";
		return false;
	}
	catch (const std::out_of_range &e) {
        std::cout << e.what() << "\nВведите число поменьше.";
		return false;
	}

	//--------------- kopeks ---------------
	try {
		M.kopeks = stoi(sKopeks);
	}
	catch (const std::invalid_argument &e) {
        std::cout << e.what() << "\nНекорректное значение.";
		return false;
	}
	catch (const std::out_of_range &e) {
        std::cout << e.what() << "\nВведите число поменьше.";
		return false;
	}
	return true;
}

void ConvertRubleAndKopeksToTotal(Money &M) {
	if (M.rubles >= 0 && M.kopeks >= 0) {
		M.totalRubleAndKopeks = (M.rubles + M.kopeks / 100.0);
	}
	else if (M.kopeks < 0) {
		M.totalRubleAndKopeks = (M.rubles + M.kopeks / 100.0);
	}
	else if (M.rubles < 0) {
		M.totalRubleAndKopeks = (M.rubles - M.kopeks / 100.0);
	}
}

