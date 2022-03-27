#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int **CreateAndFillArray(const int rows, const int cols, bool FillArray = true);
int **ChangeArray(int **arr, int m, int n, const int row, const int col);
void PrintArray(int **arr, const int row, const int col);
void DeleteArray(int **arr, const int rows);

int main() {
    srand((int)time(NULL));
    setlocale(LC_ALL, "rus");
    int col(0), row(0);
    cout << "Введите количество строк и столбцов массива от двух до 10\n";
    cin >> row >> col;
    while (col > 10 || col <= 1 || row > 10 || row <= 1) {
        cout << "Введено некорректное значение. Повторите попытку:\n";
        cin >> row >> col;
    }

    int **array = CreateAndFillArray(row, col);
    PrintArray(array, row, col);
    int delrow, delcol;
    cout << "Введите строку и столбец, которые необходимо удалить:\n";
    cin >> delrow >> delcol;

    while (delcol > col || delrow > row || delcol == 0 || delrow == 0) {
        cout << "Введено некорректное значение. Повторите попытку:\n";
        cin >> delrow >> delcol;
    }
    cout << "\nУдалены строка " << delrow << " и столбец " << delcol << ":\n";
    array = ChangeArray(array, delrow, delcol, row, col);
    PrintArray(array, row - 1, col - 1);
    DeleteArray(array, row - 1);

    return 0;
}

int **CreateAndFillArray(const int rows, const int cols, bool FillArray) {
    //Если флаг true, то заполняем матрицу рандомными значениями. 
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    if (FillArray) {
        for (int k = 0; k < rows; k++) {
            for (int j = 0; j < cols; j++) {
                arr[k][j] = rand() % 10;
            }
        }
    }
    return arr;
}

int **ChangeArray(int **arr, int m, int n, const int row, const int col) {
    //Так как удаляем по одной строке и одному столбцу, то создаём матрицу с размерами на единицу меньшей исходной
    int **newArray = CreateAndFillArray(row - 1, col - 1, false);
    m--;
    n--;
    //Цикл игнорирует удалённые строку и столбец и перепрыгивает через них, в свою очередь в новом массиве нумерация 
    //строк и столбов должна продолжиться идти по порядку, поэтому вводятся новые переменные x,y
    for (int i = 0, x = 0; i < row; i++) {
        if (i != m) {
            for (int k = 0, y = 0; k < col; k++) {
                if (k != n) {
                    newArray[x][y] = arr[i][k];
                    y++;
                }
            }
            x++;
        }
    }
    DeleteArray(arr, row);
    return newArray;
}

void PrintArray(int **arr, const int row, const int col) {
    string z(col * 3 - 2, '=');         //выводим символы для небольшого оформления вывода матрицы
    cout << z << endl;
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < col; k++) {
            cout << arr[i][k] << "  ";
        }
        cout << endl;
    }
    cout << z << endl;
}

void DeleteArray(int **arr, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}