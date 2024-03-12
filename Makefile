TARGET = sw
CC = gcc
CFLAGS = -Iinclude

INSTALL_DIR = /usr/bin


SOURCES = $(wildcard src/*.c)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	    cp $(TARGET) $(INSTALL_DIR)

.PHONY: clean


