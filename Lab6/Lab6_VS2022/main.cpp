#include <iostream>
#include "List.h"
#include <ctime>

//#define DEBUG
using namespace std;


int main() {
	//srand(static_cast<unsigned int>(time(NULL)));
	List list{ 21, 32, 234, 234098, 9999 };
	Iterator i = list.first();
	
	for (int k = 0; k < 3; k++) {	//Для тестирования. Переход к элементу l[4]
		++i;
	}

	cout << *i << endl;
	i -= 1;
	cout << *i << endl;




#ifdef DEBUG
	for (int i = 0; i < int(list); i++) {
		list[i] = rand() % 100;
		cout << list[i] << endl;
	}
	for (size_t k = 0; k < 3; k++) {	//Для тестирования. Переход к элементу l[4]
		++i;
	}
	list.Erase();
#endif // DEBUG

	return 0;
}
