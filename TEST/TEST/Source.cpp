#include <iostream>
#include <Windows.h>
using namespace std;


struct Name {
	char fam[30];
};

struct Worker {
	Name men;
	int brigada;
	int hours;
	string work;
	int salary;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N, wwork;
	int sum, maxsum = 0, maxbrigada;
	cout << "Введите количество рабочих: " << endl;
	cin >> N;
	Worker *a = new Worker[N];
	cout << "Введите информацию о рабочих" << endl;

	for (int i = 0; i < N; i++) {
		cout << "\nфамилиния: ";
		cin >> a[i].men.fam;
		cout << "\nБригада: ";
		cin >> a[i].brigada;
		cout << "\nКол-во часов: ";
		cin >> a[i].hours;
		cout << "\nРабота (малярные, сантехника, электрика):";
		cin >> wwork;
		switch (wwork) {
		case 0: a[i].work = "малярные";
			a[i].salary = 400;

		case 1: a[i].work = "сантехника";
			a[i].salary = 650;
			break;
		case 2: a[i].work = "электрика";
			a[i].salary = 700;
			break;
		}

	}

	cout << endl;
	for (int i = 0; i < N; i++) {
		sum = a[i].salary * a[i].hours;;
		for (int j = 0; j < N; j++) {
			if (a[i].brigada == a[j].brigada && a[i].men.fam != a[j].men.fam)
				sum += a[j].salary * a[j].hours;
		}
		if (sum > maxsum) {
			maxsum = sum;
			maxbrigada = a[i].brigada;
		}
		cout << a[i].men.fam << " из " << a[i].brigada << " бригады, проработав " << a[i].hours << " час(ов) " << a[i].work << ", получая за час " << a[i].salary << " в сумме получив " << a[i].salary * a[i].hours << endl;
	}
	cout << "Больше всего заработала бригада №" << maxbrigada << ", заработав " << maxsum << " рублей." << endl;
	return 0;
}