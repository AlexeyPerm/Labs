#include "List.h"
#include "Error.h"

int main() {

    try {
        List l(1000);
        List z;
        l[800] = 4444;
        l - 1000;
        std::cout << l.getCurrent();
    }
#if OPTION == 2     //������� ���������� (2 ��� 3). ���������� ������� � � Error.h
    catch (Error e) {
        e.what();
    }
#elif OPTION == 3
    catch (Error & error){
        error.what();
    }
#endif

    return 0;
}