#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
Сформировать двоичный файл из элементов, заданной в варианте структуры.
Удалить первый элемент с заданным объемом информации, добавить элемент перед элементом с указанным номером.
*/

const unsigned int strLength = 40;
int structCount;

struct Information {
	char name[strLength];
	char autor[strLength];
	char storage[strLength];
	unsigned int volume;
};

Information info;	//объявляем структуру info вне main, чтобы можно было передать её внутри функции Selection в другую функцию.
void AddDataToStructInformation(Information *info, const unsigned int a);
bool Selection(void);
void SaveToFile(FILE *f, Information info);
void PrintData(FILE *f, const int *count);
int AddElement(int n, int *structCount);
int DeleteElementInStruct(int n, int *structCount);

int main() {
	setlocale(LC_ALL, "ru");
	while (Selection());
	return 0;
}

bool Selection() {
	int choice;
	cout << "\nВыберите желаемое действие:\n";
	cout << "==============================\n";
	cout << "1. Внести данные\n" <<
		"2. Добавить элемент\n" <<
		"3. Удалить элемент\n" <<
		"4. Вывести все данные на экран\n" <<
		"0. Выйти из программы\n";
	(cin >> choice).get();
	//С этого момента начинается то, за что мне стыдно. !!!Передалать когда-нибудь!!!
	switch (choice) {
		case 1: {	//первоначальный ввод данных
			cout << "Количество вносимых элементов не больше 5: \n";
			(cin >> structCount).get();
			while (structCount <= 0 or structCount > 5) {
				cout << "Не корректное количество элементов\n";
				cout << "Введите повторно количество вносимых элементов не больше 5: ";
				(cin >> structCount).get();
			}
			FILE *f = fopen("file.bin", "wb");
			if (f == NULL) {
				cout << "Не удаётся открыть файл";
				return 1;
			}
			for (int i = 0; i < structCount; i++) {
				AddDataToStructInformation(&info, strLength);
				SaveToFile(f, info);
			}
			cout << "\n\nДанные введены и успешно сохранены\n\n";
			fclose(f);
			return true;
		}
		case 2: {	//добавление элемента перед указанной строкой
			cout << "Перед какой строкой нужно ввести данные?\n";
			int number;
			(cin >> number).get();
			AddElement(number, &structCount);
			return true;
		}
		case 3: {	//удалить элемент 
			cout << "Удалить элемент с заданным объёмом информации\n";
			int delVolume;
			(cin >> delVolume).get();
			DeleteElementInStruct(delVolume, &structCount);
			return true;
		}
		case 4: {	//Вывести на экран все данные
			FILE *savedFile = fopen("file.bin", "rb");
			if (savedFile == NULL) {
				cout << "Не удаётся открыть файл";
				return 1;
			}
			PrintData(savedFile, &structCount);
			fclose(savedFile);
			system("pause");
			return true;
		}
		case 0:
			exit(0);
		default:
			cout << "\n!Ошибка! Нужно ввести номер предложенного действия\n";
			return true;
	}
	return true;
}

void SaveToFile(FILE *f, Information info) {
	//Реалицизация в функции, так как того требует задание.
	//Принимаем указатель на текущую структуру, вычисляем её размер, который может изменяться при изменении 
	//значения в переменной str_lenght и указываем файл, куда нужно писать
	fwrite(&info, sizeof(struct Information), 1, f);
}

void PrintData(FILE *f, const int *structCount) {
	//count - общее количество структур 
	Information info_output;
	int num = 1;
	cout << "\nДанные в файле: \n";
	for (int i = 0; i < *structCount; i++) {
		fread(&info_output, sizeof(struct Information), 1, f);
		cout << "\n=========== Элемент номер " << num++ << " ===========\n";
		cout << "Название:  " << info_output.name << endl;
		cout << "Автор:     " << info_output.autor << endl;
		cout << "Носитель:  " << info_output.storage << endl;
		cout << "Объём:     " << info_output.volume << endl;
	}
}

void AddDataToStructInformation(Information *info, const unsigned int strLength) {
	//Условие нужно, потому что без него cin.getline после ввода переноса строки ожидает ещё один перенос. Пока не знаю, как решить без него.
	//cin.clear - сброс флага failbit в дефолтное значение goodbit, если длина строки превысила значение параметра strLength.
	//Шаблон: void clear( std::ios_base::iostate state = std::ios_base::goodbit );
	//https://en.cppreference.com/w/cpp/io/basic_ios/clear
	//cin.ignore() - Игнорируем всё, что вышло за пределы strLength в количестве 111+ символов. Перенос строки - разделитель.
	//https://en.cppreference.com/w/cpp/io/basic_istream/ignore
	cout << "Название: \n";
	if (!cin.getline((*info).name, strLength))
	{
		cin.clear();
		cin.ignore(1111111, '\n');
	}
	cout << "\nАвтор: \n";
	if (!cin.getline((*info).autor, strLength))
	{
		cin.clear();
		cin.ignore(1111111, '\n');
	}
	cout << "\nНоситель: \n";
	if (!cin.getline((*info).storage, strLength))
	{
		cin.clear();
		cin.ignore(1111111, '\n');
	}
	cout << "\nОбъём(число): \n";
	//Вводим число и пропускаем один символ, которым является "\n". Если этого не сделать, то "\n" останется в потоке ввода и получится
	//так, что в gets_s(info[k].name, *a); введётся этот "\n". 
	(cin >> (*info).volume).get(); cout << endl;
}

int AddElement(int n, int *structCount) {
	//параметр n - это номер элемента, перед которым по условию задания, нужно ввести новые данные
	int m = *structCount;
	char TempFile[] = "temp333.bin", currentFile[] = "file.bin";
	FILE *f = fopen(currentFile, "rb");
	FILE *tmpFile = fopen(TempFile, "wb");
	if (tmpFile == NULL || f == NULL) {	//Проверка корректности открытия обоих файлов
		cout << "\nНе удаётся открыть файл\n";
		return 1;
	}
	int k = 1;
	while (k <= m) {
		//m - общее кол-во структур. Пробегаемся по всем элементам, пока не дойдём 
		//до нужного  номера элемента и пишем перед ним новый элемент
		if (k == n) {
			AddDataToStructInformation(&info, strLength);
			SaveToFile(tmpFile, info);
			(*structCount)++;
		}
		fread(&info, sizeof(struct Information), 1, f);
		fwrite(&info, sizeof(struct Information), 1, tmpFile);
		k++;
	}
	fclose(f);
	fclose(tmpFile);
	remove(currentFile);

	int result = rename(TempFile, currentFile);
	if (result != 0) {
		cout << "Не удаётся переименовать файл\n";
	}
	return 0;
}

int DeleteElementInStruct(int n, int *structCount) {
	//m - общее кол-во структур.
	int m = *structCount;
	char TempFile[] = "temp333.bin", currentFile[] = "file.bin";
	FILE *f = fopen(currentFile, "rb");
	FILE *tmpFile = fopen(TempFile, "wb");

	if (tmpFile == NULL || f == NULL) {
		cout << "\nНе удаётся открыть файл\n";
		return 1;
	}

	while (m) {
		fread(&info, sizeof(struct Information), 1, f);
		if (info.volume != n) {
			fwrite(&info, sizeof(struct Information), 1, tmpFile);
		}
		else {
			(*structCount)--;		//уменьшаем счётчик кол-ва структур. 
		}
		m--;
	}

	fclose(f);
	fclose(tmpFile);
	remove(currentFile);

	int result = rename(TempFile, currentFile);
	if (result != 0) {
		cout << "Не удаётся переименовать файл\n";
	}
	return 0;
}