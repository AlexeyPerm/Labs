#include <iostream>
#include <iomanip>
using namespace std;

//прототипы функций
bool FindNegativeNumber(int *pArray, int col);
void RemoveNegativeRow(int *pArray, int staticArrRows, int rows, int cols);

int main() {
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));

	const int staticArrRows(50), staticArrCol(50);
	bool correctInput = false;
	int arr[staticArrRows][staticArrCol]{};
	int rows, cols;	//Переменные, где хранятся заданные пользователем размеры массива

	cout << "Введите количество строк и столбцов двумерного массива до 10:\n";
	cin >> rows >> cols;
	while (!correctInput) {		//В цикле проверяем корректность ввода реального размера массива.
		if (rows > 10 || cols > 10 || rows <= 0 || cols <= 0) {
			cout << "Введёна некорректная длина массива. \nПопробуйте ещё раз.\n";
			cin >> rows >> cols;
		}
		else {
			correctInput = true;	//Инвертируем значение correctInputSize для выхода из цикла. 
		}
	}
	cout << "\nКоличество строк: " << rows << endl << "Количество столбцов: " << cols << endl;
	cout << "Сгенерированный массив:\n";

	for (int i = 0; i < rows; i++) {		//Генерируем случайным образом элементы массива и выводим на экран в виде матрицы
		for (int k = 0; k < cols; k++) {
			arr[i][k] = (rand() % 10) - 2;		//Генерация положительных и отрицательных чисел
			if (k % cols != 0) {			//Если остаток от деления равен нулю, то делаем перенос строки
				cout << setw(3) << arr[i][k];	//setw(3) - выдяляемая ширина поля для выводимого каждого числа
			}
			else {
				cout << setw(3) << endl << arr[i][k];
			}
		}
	}

	cout << endl;

	for (int i = 0; i < rows; i++) {
		if (FindNegativeNumber(&arr[i][0], cols)) {
			RemoveNegativeRow(&arr[i][0], staticArrRows, rows, cols);	//передаём в массив адрес первого элемента строки i
			i--;	//Возвращаемся строке, которая заменила обнулёную строку и проверяем её на отриц. элементы. 
		}
	}

	cout << "\nОтредактированны массив: " << endl;
	//Выводим на экран массив после всех манипуляций
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < cols; k++) {
				cout << setw(3) << arr[i][k];
		}
		cout << endl;
	}
	return 0;
}

bool FindNegativeNumber(int*pRowIndex, int currentCol) {
	//Функция ищет отрицательные элементы в строке. 
	//Параметры принимают адрес начала строки и кол-во элементов в строке.
	for (int j = 0; j < currentCol; j++) {
		if (pRowIndex[j] < 0) {
			return true;
		}
	}
	return false;
}

void RemoveNegativeRow(int* pRowIndex, int staticArrRows, int rows, int cols) {
	//Функция зануляет строку, в которой нашли отрицательный элемент и двигает её в конец массива.
	for (int k = 0; k < cols; k++) {
		pRowIndex[k] = 0;
	}
	if (*pRowIndex == rows - 1)
		return; //Если строка последняя в массиве, то выходим из функции.
	for (int i = 0; i < rows - 1; i++) {
		for (int n = 0; n < cols; n++) {
			pRowIndex[staticArrRows * i + n] = pRowIndex[(i + 1) * staticArrRows + n];	//Берём значение из "нижней" ячейки и перекидываем в текущую
			pRowIndex[(i + 1) * staticArrRows + n] = 0;		//Нижнюю ячейку зануляем. 
		}
	}
}