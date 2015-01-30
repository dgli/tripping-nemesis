#
#
#

CC=g++

PKG=`pkg-config --cflags --libs gtkmm-3.0`

all: base 

base: base.o ScreenDrawingArea.o
	$(CC) base.o ScreenDrawingArea.o -o base $(PKG) 

base.o: base.cpp 
	$(CC) -c base.cpp $(PKG)

ScreenDrawingArea.o:
	$(CC) -c ScreenDrawingArea.cpp $(PKG)

clean:
	rm -rf *.o base
