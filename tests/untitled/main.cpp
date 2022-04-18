#include <stdio.h>
#include <iostream>
#include <string.h>
#include <locale.h>



int main()
{
char *s = "123";

    for (int i = strlen(s); i >= 0; i--) {
        std::cout << s[i];
    }


    return 0;
}
