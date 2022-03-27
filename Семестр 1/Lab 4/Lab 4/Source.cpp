#include <iostream>
#include <ctime>
using namespace std;
/*
1)	������������ ���������� ������ ����� �����, ��������� ������ ��������� �����.
2)	����������� ���������� ������.
3)	������� 5 ������ �������� �������.
4)	�������� � ����� ������� 3 ����� ��������.
5)	����������� ���������� ������.
*/

int main() {

	setlocale(LC_ALL, "Ru");
	srand(time(NULL));				//��� ����, ����� � ����� ������ ������� �������������� ������ ��������� �����;

	const int sizeArrayA = 100;		//����� ������ �������, ������ ������������ ���������;
	int a[sizeArrayA];				//������ ������ ��������� ������� sizeArrayA;
	int realSizeArrayA = 0;			//�������� �������� ������ �������, � ������� ����� ��������;
	bool correctInputSize = false;	//�������� �� ������������ ����� ������� �������. 5 <= realSizeArrayA <= 100;

	cout << "������� ����� ������� �� 5 �� 100:\n";
	cin >> realSizeArrayA;

	while (!correctInputSize) {		//� ����� ��������� ������������ ����� ��������� ������� �������.
		if (realSizeArrayA < 5 or realSizeArrayA > 100) {	//�������� �� 5 <= realSizeArrayA <= 100;
			cout << "������ ������������ ����� �������. \n���������� ��� ���.\n";
			cin >> realSizeArrayA;
		}
		else {
			correctInputSize = true;	//����������� �������� correctInputSize ��� ������ �� �����. 
		}
	}
	cout << "\n�������� ����� �������: " << realSizeArrayA << endl;

	//��������� ������ �������
	for (int i = 0; i < realSizeArrayA; i++) {
		a[i] = rand() % 10;		//��������� ������ ���������� ������� �� 0 �� 10
		cout << a[i] << " ";	//����������� ������� ��������
	}
	cout << endl;

	//��� �������� ������ 5 ���������, ������� ������ ����� �� 5 
	for (int i = 0; i < (realSizeArrayA - 5); i++) {
		a[i] = a[i + 5];	//���������, ����������� �� ������� �������� � �������� a[i + 5], ��� ����� "������" ��� ������ 5 ���������
	}
	int newSizeArrayA = realSizeArrayA - 5 + 3;		//������������ ������ ������� ����� �������� 5 ������ ��������� � ���������� 3 ����� � �����
	
	//���������� �� ������������� ������� a[] � ������� ��� �������.
	for (int i = 0; i < newSizeArrayA; i++) {
		if (i < (newSizeArrayA - 3)) {		//������� ����������� ������� ��������
			cout << a[i] << " ";
		}
		else {								//���������� ��� ��������� ��������� � ����� �� �� �����.
			a[i] = rand() % 10;
			cout << a[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
