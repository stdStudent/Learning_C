#include <stdio.h>
#include <termios.h>
#include <string.h>

static struct termios old, new;

void initTermios(int echo) {
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &new);
}

void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

char getch(void) {
    return getch_(0);
}

void deleteChar(char *str, int pos) {
    for (int i = pos; i < strlen(str); ++i)
        str[i]=str[i+1];
}
