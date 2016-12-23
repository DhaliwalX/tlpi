#ifndef COMMON_H_
#define COMMON_H_

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "getnum.h"

#include "error_functions.h"

typedef enum { TRUE, FALSE } boolean;

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))

#endif /* common.h included */
