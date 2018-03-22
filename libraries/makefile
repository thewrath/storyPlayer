CC = g++ 
CPPFLAGS = -std=c++17 -fpermissive -fPIC
LIBNAME = libkairos.so
LDFLAGS = -shared 

SOURCEDIR = Kairos

all : build clean 

objects :
	$(CC) -c $(SOURCEDIR)/*.cpp $(CPPFLAGS)

build : objects
	$(CC) -o $(LIBNAME) *.o -shared $(CPPFLAGS)

clean :
	rm -f *.o 