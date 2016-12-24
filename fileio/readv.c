#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>

#include "../lib/common.h"

int main(int argc, char *argv[])
{
    int fd;
    struct iovec vec[3];

    struct stat myStruct;
    int x;
#define STR_SIZE 100
    char str[100];
    ssize_t num_read, tot_required;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usage_error("%s file\n", argv[0]);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        error_exit("open");
    }

    tot_required = 0;

    vec[0].iov_base = &myStruct;
    vec[0].iov_len = sizeof(myStruct);
    tot_required += vec[0].iov_len;

    vec[1].iov_base = &x;
    vec[1].iov_len = sizeof(int);
    tot_required += vec[0].iov_len;

    vec[2].iov_base = str;
    vec[2].iov_len = STR_SIZE;
    tot_required += STR_SIZE;

    num_read = readv(fd, vec, 3);
    if (num_read == -1)
        error_exit("readv");

    if (num_read < tot_required)
        printf("Read fewer bytes than requested\n");

    printf("Total bytes requested: %ld; bytes read: %ld", (long)tot_required,
            (long)num_read);

    exit(EXIT_SUCCESS);
}
