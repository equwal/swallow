.POSIX:

CC?=cc
CPPFLAGS=-lX11 -Wall -Wextra -fPIE -O2 -D_FORTIFY_SOURCE=2
SOURCE=swallow.c
TARGET=swallow

PREFIX=/usr/local

build: $(TARGET)
	$(CC) $(CPPFLAGS) $(SOURCE) -o $(TARGET)

install: build
	cp $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: build install uninstall clean
