#ifndef FORMAT_H
#define FORMAT_H

#include <sys/time.h>

/* States for */
typedef enum {
	NOTVALID = 0,
	MILLISECONDS,
	SECONDS,
	DECISECONDS,
	CENTISECONDS,
	MICROSECONDS
} time_unit_t;

#define ASCIINUMBER(c) (c >= '0' && c <= '9')

void timeval_formatstr(struct timeval tv, char *str);
long str_formatusec(char *str);
#endif
