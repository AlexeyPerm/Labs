#include "money.h"

//------------------- Setters -------------------
void Money::set_ruble(const long r) {
	ruble = r;
	ConvertRubleAndKopeksToTotal(*this);	//функция принимает ссылку на вызывающий эклемпляр класса. Передаём разыменованный указатель на него.
}

void Money::set_kopeks(const int k) {
	kopeks = k;
	ConvertRubleAndKopeksToTotal(*this);	
}
//------------------- Getters -------------------
long Money::get_ruble() const {
	return ruble;
}

int Money::get_kopeks() const {
	return kopeks;
}

//---------------- Constructors -----------------
Money::Money() {
	ruble = 0;
	kopeks = 0;
	ConvertRubleAndKopeksToTotal(*this);
}

Money::Money(const long ruble, const int kopeks) {
	this->ruble = ruble;	//присваиваем заданное кол-во рублей соответствующей переменной в текущем экземпляре класса. 
	if (kopeks < 0 || kopeks > 100) {
		cout << "Не корректное кол-во копеек. Обнуляем значение\n";
	}
	else {
		this->kopeks = kopeks;	//присваиваем заданное кол-во копеек соответствующей переменной в текущем экземпляре класса. 
	}
	ConvertRubleAndKopeksToTotal(*this);
}

Money::Money(const Money &M) {	//Конструктор копирования T::T(const T&) {...}
	ruble = M.ruble;
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
	totalRubleAndKopeks += 0.01;	//Прибавляем копейку. Так как работаем уже с вещественным числом, то и прибавляем одну сотую часть, коей и является копейка. 
	return *this;
}

Money Money::operator++(int) {
	Money tmp(*this);
	this->totalRubleAndKopeks += 0.01;
	return tmp;
}

Money &Money::operator = (const Money &other) {
	this->ruble = other.ruble;
	this->kopeks = other.kopeks;
	ConvertRubleAndKopeksToTotal(*this);
	return *this;
}

istream &operator >> (istream &in, Money &M) {
	string r{}, k{};
	cout << "Введите рубли \n>";
	in >> r;
	cout << "Введите копейки \n>";
	in >> k;
	while (!CorrectInput(r, k, M)) {	//передаём введённые значения рублей, копеек и текущий экземлпляр класса. 
		cout << "Повторите ввод. \nВведите рубли: \n>";
		in >> r;
		cout << "Введите копейки: \n>";
		in >> k;
	}
	ConvertRubleAndKopeksToTotal(M);
	return in;
}

ostream &operator << (ostream &out, Money &M) {
	out.imbue(locale("ru"));	//Разделитель дробный чисел будет в соответствии с указаной локализаций. В данном случае будет запятая. 
	return (out << fixed << setprecision(2) << M.totalRubleAndKopeks << " р." << endl);
}

//--------------- Other functions ---------------
void Money::show() const{
	wcout.imbue(locale("ru"));
	wcout << fixed << setprecision(2) << totalRubleAndKopeks << " р." << endl;
}

bool CorrectInput(string &sRuble, const string &sKopeks, Money &M) {

	if (sRuble[0] == '-') {	//если ввели отриц. значение, то избавляемся от минуса, для проверки строки на числа, иначе all_of() всегда будет возвращать false;
		string tmp = sRuble;
		tmp = tmp.erase(0, 1);
		if (!(all_of(tmp.begin(), tmp.end(), isdigit))) {	//проверяем все элементы строки на число
			cout << "Ошибка при вводе кол-ва рублей. Необходимо ввести число";
			return false;
		}
	}
	else if ((!(all_of(sRuble.begin(), sRuble.end(), isdigit)))) {
		cout << "Ошибка при вводе кол-ва рублей. Необходимо ввести число.\n>";
		return false;
	}
	if (sKopeks[0] == '-') {
		string tmp = sKopeks;
		tmp = tmp.erase(0, 1);
		if ((!(all_of(tmp.begin(), tmp.end(), isdigit)))) {
			cout << "Ошибка при вводе кол-ва копеек.\n";
			return false;
		}
	}
	else if ((!(all_of(sKopeks.begin(), sKopeks.end(), isdigit)))) {
		cout << "Ошибка при вводе кол-ва копеек.\n";
		return false;
	}
	//-------------- - ruble-------------- -
	try {
		M.ruble = stol(sRuble);
	}
	catch (const invalid_argument &e) {
		cout << e.what() << "\nНекорректное значение.";
		return false;
	}
	catch (const out_of_range &e) {
		cout << e.what() << "\nВведите число поменьше.";
		return false;
	}

	//--------------- kopeks ---------------
	try {
		M.kopeks = stoi(sKopeks);
	}
	catch (const invalid_argument &e) {
		cout << e.what() << "\nНекорректное значение.";
		return false;
	}
	catch (const out_of_range &e) {
		cout << e.what() << "\nВведите число поменьше.";
		return false;
	}

	//if (M.kopeks < 0) {
	//	cout << "Количество копеек не может быть меньше нуля.";
	//	return false;
	//}
	//if (M.kopeks >= 100) {
	//	cout << "Количество копеек больше 100. Конвертируем излишки в рубли." << endl;
	//}

	return true;
}

void ConvertRubleAndKopeksToTotal(Money &M) {
	if (M.ruble >= 0 && M.kopeks >=0) {
		M.totalRubleAndKopeks = (M.ruble + M.kopeks / 100.0);
	}
	else if (M.kopeks < 0) {
		M.totalRubleAndKopeks = (M.ruble + M.kopeks / 100.0);
	}
	else if (M.ruble < 0) {
		M.totalRubleAndKopeks = (M.ruble - M.kopeks / 100.0);
	}
}