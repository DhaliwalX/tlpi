#ifndef ERROR_FUNCTIONS_H_
#define ERROR_FUNCTIONS_H_

#ifdef __GNUC__
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void error_exit(const char *format, ...) NORETURN;

void error_message(const char *format, ...);

void error_exit_errno(int errnum, const char *format, ...) NORETURN;

void fatal(const char *format, ...) NORETURN;

void usage_error(const char *format, ...) NORETURN;

void command_line_error(const char *format, ...) NORETURN;



#endif
