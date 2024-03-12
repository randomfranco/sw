#ifndef SW_H
#define SW_H

#include <sys/time.h>

#ifndef MAXSTOPS
#define MAXSTOPS 64
#endif

#define SWITCH(running) ((running) == 0 ? 1 : 0)

struct stopwatch{
	struct timeval tv, running_tv, acc;
	struct timeval stops[MAXSTOPS];
	short running;
	unsigned short nstops;
	unsigned int precision;
};

void sw_init(struct stopwatch *sw);
void sw_update(struct stopwatch *sw);
void sw_reset(struct stopwatch *sw);
void sw_show(struct stopwatch *sw);
void sw_stop(struct stopwatch *sw);
void sw_run(struct stopwatch *sw);
void timeval_formatstr(struct timeval tv, char *str);

#endif
