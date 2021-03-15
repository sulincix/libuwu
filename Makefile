DESTDIR=/
CC=gcc
CFLAGS=-O3 -s -fpic
all: build


build:
	$(CC) $(CFLAGS) -I. -shared libuwu.c -o libuwu.so
	$(CC) main.c  -L. -luwu -I. $(CFLAGS) -o uwu

clean:
	rm -f libuwu.so uwu || true

install:
	mkdir -p $(DESTDIR)/usr/lib/pkgconfig/
	mkdir -p $(DESTDIR)/usr/include/
	mkdir -p $(DESTDIR)/usr/bin/
	install libuwu.so  $(DESTDIR)/usr/lib/
	install uwu $(DESTDIR)/usr/bin/
	install libuwu.h $(DESTDIR)/usr/include/
	install libuwu.pc $(DESTDIR)/usr/lib/pkgconfig/
	install libuwu.py $(DESTDIR)/`python3 -c 'import sysconfig; print(sysconfig.get_paths()["purelib"])'`/uwu.py
