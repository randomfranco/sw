#ifndef FORMAT_H
#define FORMAT_H

#include <sys/time.h>

/* States for */
#define NOTVALID 0
#define MILLISECONDS 1
#define SECONDS 2
#define DECISECONDS 3
#define CENTISECONDS 4
#define MICROSECONDS 5

#define ASCIINUMBER(c) (c >= '0' && c <= '9')

void timeval_formatstr(struct timeval tv, char *str);
long str_formatusec(char *str);
#endif
