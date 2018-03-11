CC = g++ 
CFLAGS = -std=c++17 -fpermissive
LIBNAME = libkairos.so

SOURCES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all : objects

objects : $(SOURCES)
	$(CC) -c $(SOURCES)