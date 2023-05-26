.POSIX:

CC?=cc
CPPFLAGS=-lX11 -Wall -Wextra -fPIE -O2 -D_FORTIFY_SOURCE=2
SOURCE=swallow.c
TARGET=swallow
PREFIX=/usr/local/bin/

build: $(TARGET)
	$(CC) $(CPPFLAGS) $(SOURCE) -o $(TARGET)

install: build
	cp $(TARGET) $(DESTDIR)$(PREFIX)$(TARGET)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: build install uninstall clean
