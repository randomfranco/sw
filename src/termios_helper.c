#include <unistd.h>
#include <termios.h>

void termios_init(struct termios *original_settings){
	struct termios new_settings;
	tcgetattr(STDIN_FILENO, original_settings);
	new_settings = *original_settings;
	new_settings.c_lflag &= ~(ICANON | ECHO);
	new_settings.c_cc[VMIN] = 0;
	new_settings.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

void termios_restore(struct termios *original_settings){
	tcsetattr(STDIN_FILENO, TCSANOW, original_settings);
}
