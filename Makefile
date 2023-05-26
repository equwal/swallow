.POSIX:

CC=cc
CPPFLAGS=-Wall -Wextra -fPIE -O2 -D_FORTIFY_SOURCE=2
LDLIBS=-lX11

TARGET=swallow

PREFIX=/usr/local

build: $(TARGET)

install: build
	cp $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: build install uninstall clean
