#ifndef TERMIOS_HELPER_H
#define TERMIOS_HELPER_H

void termios_init(struct termios *original_settings);
void on_exit_termios_restore(int status, void *arg);


#endif
