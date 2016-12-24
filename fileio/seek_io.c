#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include "../lib/common.h"

int main(int argc, char *argv[])
{
    size_t len;
    off_t offset;
    int fd, ap, j;
    char *buf;
    ssize_t num_read, num_write;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        usage_error("%s file {r<length>|R<length>|w<string>|s<offset>}...\n",
            argv[0]);

    fd = open(argv[1], O_RDWR | O_CREAT,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (fd == -1)
        error_exit("open");

    for (ap = 2; ap < argc; ap++) {
        switch(argv[ap][0]) {
            case 'r':
            case 'R':
                len = get_long(&argv[ap][1], GN_ANY_BASE, argv[ap]);
                buf = malloc(len);

                if (buf == NULL)
                    error_exit("malloc");

                num_read = read(fd, buf, len);
                if (num_read == -1) {
                    error_exit("read");
                }

                if (num_read == 0) {
                    printf("%s: end of file\n", argv[ap]);
                } else {
                    printf("%s: ", argv[ap]);
                    for (j = 0; j < num_read; j++) {
                        if (argv[ap][0] == 'r')
                            printf("%c", isprint((unsigned char)buf[j]) ? buf[j] : '?');
                        else
                            printf("%0x", (unsigned int)buf[j]);
                    }
                    printf("\n");
                }
                break;

            case 'w':
                num_write = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
                if (num_write == -1)
                    error_exit("write");

                printf("%s: wrote %ld bytes\n", argv[ap], (long)num_write);
                break;

            case 's':
                len = get_long(&argv[ap][1], GN_ANY_BASE, argv[ap]);
                if (lseek(fd, len, SEEK_SET) == -1)
                    error_exit("seek");

                printf("%s: seek succeeded\n", argv[ap]);
                break;

            default:
                command_line_error("Argument must start with [rRws]: %s\n", argv[ap]);            
        }
    }

    exit(EXIT_SUCCESS);
}
