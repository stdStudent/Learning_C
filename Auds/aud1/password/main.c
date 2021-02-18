#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #include <conio.h>
#elif __unix__
    #include "getchEmul.h"
#endif


int main(int argc, char** argv)
{
    //char c;
    //c = getch();
    //printf("\n %d \n\n", c);

    char user[101], pass[101], ch;

    printf("Enter user name: ");
    fgets(user, 100, stdin);

    printf("Enter your password: ");
    int i = 0;
    while ((ch = getch()) != '\n') {
        if (ch == 127) {
            deleteChar(pass, i-1);
            printf("\b \b");
            i -= 2;
        } else {
            pass[i] = ch;
            printf("*");

        }

        ++i;
    }

    if ((argc > 1) && (strcmp(argv[1], "--show-password") == 0))
        printf("\n\n Your password: %s", pass);

    return 0;
}
