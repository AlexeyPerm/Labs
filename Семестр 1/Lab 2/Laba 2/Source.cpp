#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	unsigned int i = 1, k = 1, n = 1, fact_n = 1, fact_2n = 1;
	double factResult, sum(0.0);

	do {
		//��������� n!
		for (; k <= n; k++) {
			fact_n *= k;
		}

		//��������� 2n!
		for (; i <= (2 * n); i++) {
			fact_2n *= i;
		}
		factResult = double (fact_n) / double (fact_2n);
		sum += factResult;
		n++;
	} while (factResult > 1E-4);

	cout << "����� ���� � ��������� e=10^(-4) �����: " << sum << endl;

	return 0;
}

