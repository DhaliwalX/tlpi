#include <stdio.h>


int main(int argc, char *argv[])
{
    char **a;

    for (a = argv; *a != NULL; a++) {
        puts(*a);
    }

    return 0;
}