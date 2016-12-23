#include <stdarg.h>
#include "error_functions.h"
#include "common.h"
#include "ename.c.inc"


#ifdef __GNUC__
__attribute__ ((__noreturn__))
#endif
static void terminate(boolean use_exit3)
{
    char *s;

    s = getenv("EF_DUMPCORE");

    if (s != NULL && *s != '\0') {
        abort();
    } else if (use_exit3) {
        exit(EXIT_FAILURE);
    } else {
        _exit(EXIT_FAILURE);
    }
}


static void output_error(boolean use_error, int err, boolean flush_stdout,
                        const char *format, va_list ap) {
#define BUF_SIZ 500
    char buf[BUF_SIZ], user_msg[BUF_SIZ], err_text[BUF_SIZ];

    vsnprintf(user_msg, BUF_SIZ, format, ap);

    if (use_error) {
        snprintf(err_text, BUF_SIZ, " [%s %s]",
                    (err > 0 && err <= MAX_ENAME) ?
                    ename[err] : "?UNKNOWN?", strerror(err));
    } else {
        snprintf(err_text, BUF_SIZ, ":");
    }

    snprintf(buf, BUF_SIZ, "ERROR%s %s\n", err_text, user_msg);

    if (flush_stdout)
        fflush(stdout);
    fputs(buf, stderr);
    fflush(stderr);
}

void error_message(const char *format, ...) {
    va_list arg_list;

    int saved_errno;

    saved_errno = errno;

    va_start(arg_list, format);
    output_error(TRUE,  errno, TRUE, format, arg_list);
    va_end(arg_list);

    errno = saved_errno;
}

void error_exit(const char *format, ...) {
    va_list arg_list;

    va_start(arg_list, format);
    output_error(TRUE, errno, TRUE, format, arg_list);
    va_end(arg_list);

    terminate(TRUE);
}

void error_exit_errno(int errnum, const char *format, ...) {
    va_list arg_list;

    va_start(arg_list, format);
    output_error(TRUE, errnum, TRUE, format, arg_list);
    va_end(arg_list);
    terminate(TRUE);
}

void fatal(const char *format, ...) {
    va_list arg_list;

    va_start(arg_list, format);
    output_error(FALSE, 0, TRUE, format, arg_list);
    va_end(arg_list);

    terminate(TRUE);
}

void usage_error(const char *format, ...) {
    va_list arg_list;

    fflush(stdout);

    fprintf(stderr, "Usage: ");

    va_start(arg_list, format);
    vfprintf(stderr, format, arg_list);
    va_end(arg_list);
    fflush(stderr);
    exit(EXIT_FAILURE);
}

void command_line_error(const char *format, ...) {
    va_list arg_list;

    fflush(stdout);
    fprintf(stderr, "Command line usage error:  ");
    va_start(arg_list, format);
    vfprintf(stderr, format, arg_list);
    va_end(arg_list);
    fflush(stderr);
    exit(EXIT_FAILURE);
}
