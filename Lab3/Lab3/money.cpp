#include <string>
#include <iomanip>	//setw(), setfill()
#include <algorithm>	//replace()
#include "money.h"

//------------------- Setters -------------------
void Money::set_ruble(const long r) {
    rubles = r;
//������� ��������� ������ �� ���������� ��������� ������. ������� �������������� ��������� �� ����.
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
	this->rubles = ruble;	//����������� �������� ���-�� ������ ��������������� ���������� � ������� ���������� ������.
	if (kopeks < 0 || kopeks > 100) {
        std::cout << "�� ���������� ���-�� ������. �������� ��������\n";
	}
	else {
		this->kopeks = kopeks;	//����������� �������� ���-�� ������ ��������������� ���������� � ������� ���������� ������. 
	}
	ConvertRubleAndKopeksToTotal(*this);
}

Money::Money(const Money &M) {	//����������� ����������� T::T(const T&) {...}
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
//���������� �������. ��� ��� �������� ��� � ������������ ������, �� � ���������� ���� ����� �����, ���� � �������� �������.


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
    std::cout << "������� ����� \n>";
	in >> r;
    std::cout << "������� ������� \n>";
	in >> k;
	while (!CorrectInput(r, k, M)) {	//������� �������� �������� ������, ������ � ������� ���������� ������. 
        std::cout << "��������� ����. \n������� �����: \n>";
		in >> r;
        std::cout << "������� �������: \n>";
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
//    std::wcout << std::fixed << std::setprecision(2) << totalRubleAndKopeks << " �." << std::endl;
}

bool CorrectInput(std::string &sRuble, const std::string &sKopeks, Money &M) {

	if (sRuble[0] == '-') {	//���� ����� �����. ��������, �� ����������� �� ������, ��� �������� ������ �� �����, ����� all_of() ������ ����� ���������� false;
        std::string tmp = sRuble;
		tmp = tmp.erase(0, 1);
		if (!(all_of(tmp.begin(), tmp.end(), isdigit))) {	//��������� ��� �������� ������ �� �����
            std::cout << "������ ��� ����� ���-�� ������. ���������� ������ �����";
			return false;
		}
	}
	else if ((!(all_of(sRuble.begin(), sRuble.end(), isdigit)))) {
        std::cout << "������ ��� ����� ���-�� ������. ���������� ������ �����.\n>";
		return false;
	}
	if (sKopeks[0] == '-') {
        std::string tmp = sKopeks;
		tmp = tmp.erase(0, 1);
		if ((!(all_of(tmp.begin(), tmp.end(), isdigit)))) {
            std::cout << "������ ��� ����� ���-�� ������.\n";
			return false;
		}
	}
	else if ((!(all_of(sKopeks.begin(), sKopeks.end(), isdigit)))) {
        std::cout << "������ ��� ����� ���-�� ������.\n";
		return false;
	}
	//-------------- - rubles-------------- -
	try {
		M.rubles = stol(sRuble);
	}
	catch (const std::invalid_argument &e) {
        std::cout << e.what() << "\n������������ ��������.";
		return false;
	}
	catch (const std::out_of_range &e) {
        std::cout << e.what() << "\n������� ����� ��������.";
		return false;
	}

	//--------------- kopeks ---------------
	try {
		M.kopeks = stoi(sKopeks);
	}
	catch (const std::invalid_argument &e) {
        std::cout << e.what() << "\n������������ ��������.";
		return false;
	}
	catch (const std::out_of_range &e) {
        std::cout << e.what() << "\n������� ����� ��������.";
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

