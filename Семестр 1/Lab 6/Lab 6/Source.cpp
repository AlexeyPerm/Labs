#include <iostream>
using namespace std;

//Задана строка, состоящая из символов. Символы объединяются в слова. 
//Слова друг от друга отделяются  одним или несколькими пробелами. В конце текста ставится точка. 
//Текст содержит не  более 255 символов. Выполнить ввод строки, используя функцию Gets(s).
//Напечатать все слова-палиндромы, которые есть в этой строке.

void Gets(char *s);
bool SearchPalindrom(char str[]);
void insertNullTerminator(char str[], int stringLength);

int main() {
	setlocale(LC_ALL, "ru");
	char str[256]{};
	Gets(str);
	int stringLength = (int)strlen(str);
	insertNullTerminator(str, stringLength);        //Вставляем \0 вместо пробелов. 
	cout << "\nНайденные слова палиндромы: ";
	for (int i = 0; i < stringLength;) {
		//Отдаём в функцию слово по смещению i. Если вернёт true, значит это был не \0, 
		//а значит следующее смещение i будет равно длине переданного слова. Делается так, чтобы не передавать
		//адрес следующего символа в массиве. Если был \0, значит сдвигаем смещение на единичку i++ и проверяем дальше.
		if (SearchPalindrom(str + i)) {
			i += (int)strlen(str + i) + 1;	//прибавляем единичку, так как в конце обработанного слова стоит \0, который нам не интересен.	
		}
		else {
			i++;
		}
	}

	cout << endl;
	return 0;
}

void Gets(char *s) {
	char a;
	int i = 0;
	cout << "Ввод строки. В конце нужно поставить точку\n";
	while ((a = cin.get()) != '.' && i < 255) {        //Считываем символы из потока ввода до тех пор, пока не встретим точку. 
		s[i++] = a;                         //Добавляем в массив каждый считываемый символ
	}
	s[i] = '\0';       //После выполнения цикла, а именно после ввода точки, ставим последним символом нуль-терминатор, означающий конец строки. 
}

bool SearchPalindrom(char str[]) {
	//Функция принимает в себя слово, заканчивающееся \0, либо сам \0. Если же приняли \0, то возвращаем false, 
	//в остальных любых других случаях вернём true. 
	int startSymbolIndex = 0;
	if (str[startSymbolIndex] == '\0') {
		return false;
	}
	int stringLength = strlen(str);
	int endSymbolIndex = stringLength - 1;      //Вычитаем единицу, так как последний элемент в строке \0 . 
	while (startSymbolIndex < endSymbolIndex) {
		//Если начальный и конечный символы разные, то сразу выходим из функции, так как слово не палиндром.
		if (str[startSymbolIndex] != str[endSymbolIndex]) {
			return true;
		}
		else {
			startSymbolIndex++;
			endSymbolIndex--;
		}
	}
	cout << endl << str;
	return true;
}

void insertNullTerminator(char str[], int stringLength) {
	for (int i = 0; i < stringLength; i++) {
		if (str[i] == ' ') {
			str[i] = '\0';
		}
	}
}
