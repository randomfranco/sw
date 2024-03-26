#include "format.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

static time_unit_t parseprecision(char *str){
	int len = strlen(str);

	if (len == 0){
		return NOTVALID;
	}

	for (int i=0; i<( len - 1 ); i++)
		if (!ASCIINUMBER(str[i])){
			return NOTVALID;
		}

	if (ASCIINUMBER(str[len - 1]))
		return MICROSECONDS;

	switch (str[len - 1]){
		case 's':
		case 'S':
			return SECONDS;
			break;
		case 'd':
		case 'D':
			return DECISECONDS;
			break;
		case 'c':
		case 'C':
			return CENTISECONDS;
			break;
		case 'm':
		case 'M':
			return MILLISECONDS;
			break;
		case 'u':
		case 'U':
			return MICROSECONDS;
			break;
	}

	return NOTVALID;
}

void timeval_formatstr(struct timeval tv, char *str){
	long min, sec, usec, cent;
	short is_usec_neg;

	sec = tv.tv_sec;
	usec = tv.tv_usec;
	// is usec negative?
	is_usec_neg = (usec < 0);

	// for better perfomance, no jump (if)
	sec -= 1 * is_usec_neg;
	usec += 1000000 * is_usec_neg;

	min = sec / 60;
	sec = sec % 60;
	cent = (usec / 10000) % 100 ; // solve this absolutely

	sprintf(str, "%02ld:%02ld:%02ld", min, sec, cent);

}

long str_formatusec(char *str){
	int type = parseprecision(str);
	long usec = atol(str);

	switch (type){
		case SECONDS:
			return usec * 1000000;
			break;
		case DECISECONDS:
			return usec * 100000;
			break;
		case CENTISECONDS:
			return usec * 10000;
			break;
		case MILLISECONDS:
			return usec * 1000;
			break;
		case MICROSECONDS:
			return usec;
			break;
		case NOTVALID:
			// Error, not valid. Handle this
			return -1;
			break;
	}

}

