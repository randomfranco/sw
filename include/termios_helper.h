#ifndef TERMIOS_HELPER_H
#define TERMIOS_HELPER_H

void termios_init(struct termios *original_settings);
void termios_restore(struct termios *original_settings);

#endif
