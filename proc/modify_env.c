#define _GNU_SOURCE
#include "../lib/common.h"
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[])
{
    int j;
    char **ep;

    clearenv();
    for (j = 1; j < argc; j++)
        if (putenv(argv[j]) != 0)
            error_exit("putenv: %s", argv[j]);

    if (setenv("GREET", "Hello World", 0) == -1)
        error_exit("setenv");

    unsetenv("BYE");

    for (ep = environ; *ep != NULL; ep++)
        puts(*ep);

    return 0;
}
