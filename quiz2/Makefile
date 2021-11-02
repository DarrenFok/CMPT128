# Makefile for RASTER lab by RTV. 

# Makefiles help manage the compilation process.  To use this
# Makefile, run 'make' in the directory containing this file.

# compiler options
CFLAGS = -std=c99 -g -Wall -O3
LDFLAGS = -lm -lpng

# find X11 libraries on most platforms, including Linux in CSIL
LDFLAGS += `pkg-config --libs x11` 
CFLAGS  += `pkg-config --cflags x11`

SRC1 = testDriver.c Quiz2.c draw.c png.c
test: $(SRC1) draw.h
	gcc $(CFLAGS) -o test $(SRC1) $(LDFLAGS)

clean:
	rm -f test *.o
