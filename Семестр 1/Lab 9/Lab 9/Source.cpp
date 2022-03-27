#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool OpenFiles(ifstream &fin, ofstream &fout);
void CloseAllFiles(ifstream &fin, ofstream &fout);
void PrintResultFile();
void CopyLines(ifstream &fin, ofstream &fout);
void ShortWordSearch(string &w, int &n);

const string srcFile = "F1";
const string dstFile = "F2";

int main() {
	ifstream fin;
	ofstream fout;

	int wordlength = 999;
	string shortestWord = " ";

	if (!OpenFiles(fin, fout)) {
		cout << "Cannot open the file. ";
		return 0;
	}
	CopyLines(fin, fout);
	CloseAllFiles(fin, fout);

	cout << "======================================================" << endl;
	PrintResultFile();
	cout << "======================================================" << endl;

	ShortWordSearch(shortestWord, wordlength);
	cout << "Shortest word = " << shortestWord << endl;
	return 0;
}

bool OpenFiles(ifstream &fin, ofstream &fout) {
	fin.open(srcFile, ios::in);
	fout.open(dstFile, ios::out);
	if (!fin.is_open() || !fout.is_open()) {
		return false;
	}
	return true;
}

void CloseAllFiles(ifstream &fin, ofstream &fout) {
	fin.close();
	fout.close();
}

void PrintResultFile() {
	ifstream fin;
	fin.open(dstFile, ios::in);
	while (!fin.eof()) {
		string str = "";
		getline(fin, str);
		cout << str << endl;
	}
	fin.close();
}

void CopyLines(ifstream &fin, ofstream &fout) {
	while (!fin.eof()) {
		string str = "";	//строка из файла
		string s = "";		//хранения первых символов слов в строке
		string tmp = "";
		getline(fin, str);
		istringstream w(str);
		string words;
		bool flag = false;
		w >> words;
		//В каждую итерацию прибавляем к строке по первому символу в слове, которую потом будет сравнивать
		//с первым символом текущего слова.
		s += words[0];
		//Перебираем строку в буфере, автоматически разбивая строку на отдельные слова.
		//Разделителем является пробел.
		for (; w >> words;) {
			tmp = words[0];
			if (!tmp.find_first_of(s)) {		//Сравниваем первый символ в слове со строкой из символов.
				flag = true;
				break;
			}
			s += words[0];
		}
		if (!flag) {
			fout << str << endl;
		}
	}
}

void ShortWordSearch(string &w, int &n) {
	ifstream fin;
	fin.open(dstFile, ios::in);
	while (!fin.eof()) {
		string str = "";
		getline(fin, str);
		istringstream wString(str);
		string word;
		for (; wString >> word;) {
			if ((int)word.length() < n) {
				n = word.length();
				w = word;
			}
		}
	}
}