#include <stdio.h>
#include <pwd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct passwd *id;

    if (argc < 2 || !strcmp(argv[1], "--help")) {
        printf("Usage: %s username\n", argv[0]);
        return 0;
    }
    id = getpwnam(argv[1]);

    if (id == NULL) {
        printf("username: %s: Not found\n", argv[1]);
        return -1;
    }
    printf("Login Name: %s\n", id->pw_name);
    printf("Password: %s\n", id->pw_passwd);
    printf("UID: %ld\n", (long)id->pw_uid);
    printf("GID: %ld\n", (long)id->pw_gid);
    printf("Login Shell: %s\n", id->pw_shell);
    return 0;
}
