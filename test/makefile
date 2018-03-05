CFLAGS = -std=c++14 -fpermissive
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRCS_DIR = ../sources/
INCLUDES_DIR = ../includes/

all: sfml-app clean

storyMap.o: $(SRCS_DIR)StoryMap.cpp 
	g++ -c $(SRCS_DIR)StoryMap.cpp -o storyMap.o $(CFLAGS)

storyPlayer.o: $(SRCS_DIR)StoryPlayer.cpp 
	g++ -c $(SRCS_DIR)StoryPlayer.cpp -o storyPlayer.o $(CFLAGS)

main.o: main.cpp
	g++ -c main.cpp -o main.o $(CFLAGS)

sfml-app: main.o storyMap.o storyPlayer.o
	@echo "** Building the exec"
	g++ -o sfml-app main.o storyMap.o storyPlayer.o $(LIBS) $(CFLAGS)

clean:
	@echo "** Removing object files ..."
	rm -f *.o

install:
	@echo '** Installing...'
	cp sfml-app /usr/bin

uninstall:
	@echo '** Uninstalling...'
	rm -f /usr/bin/sfml-app