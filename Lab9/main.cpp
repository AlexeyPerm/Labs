#include "List.h"
#include "Error.h"

int main() {

    try {
        std::cout << "List l[-1];" << std::endl;
//        List l(0);
//        List l(-1);
        List l{2, 3, 4, 5, 6};
//        l[5];
//        l[-1];
        l - 10;
//        std::cout << l.getCurrent();
    }
#if OPTION == 2     //Вариант реализации (2 или 3). Необходимо сменить и в Error.h
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