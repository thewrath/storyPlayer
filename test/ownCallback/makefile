CFLAGS = -std=c++17 -fpermissive
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
SRCS_DIR = ../../sources/
LIB_DIR = lib/
FIND_RECUR = $(shell find . -type f -name "*.cpp")
INCLUDES_DIR = ../includes/

all: sfml-app

objects :  
	g++ -c $(SRCS_DIR)*.cpp  $(FIND_RECUR) $(CFLAGS)

sfml-app: objects
	@echo "** Building the exec"
	g++ -o sfml-app.out *.o $(LIBS) $(CFLAGS)

clean:
	@echo "** Removing object files ..."
	rm -f *.o

install:
	@echo '** Installing...'
	cp sfml-app /usr/bin

uninstall:
	@echo '** Uninstalling...'
	rm -f /usr/bin/sfml-app