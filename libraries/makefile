CFLAGS = -std=c++17 -fpermissive
LIBNAME = libkairos.so

objects := $(patsubst %.c,%.o,$(wildcard *.cpp))

all : $(objects)
        cc -o foo $(objects)
