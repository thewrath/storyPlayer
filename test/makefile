CFLAGS = -std=c++17 -fpermissive
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRCS_DIR = ../sources/
INCLUDES_DIR = ../includes/

all: sfml-app clean

storyPlayer.o: $(SRCS_DIR)StoryPlayer.cpp 
	g++ -c $(SRCS_DIR)StoryPlayer.cpp -o storyPlayer.o $(CFLAGS)

main.o: main.cpp
	g++ -c main.cpp -o main.o $(CFLAGS)

sfml-app: main.o storyPlayer.o
	@echo "** Building the exec"
	g++ -o sfml-app.out main.o storyPlayer.o $(LIBS) $(CFLAGS)

clean:
	@echo "** Removing object files ..."
	rm -f *.o

install:
	@echo '** Installing...'
	cp sfml-app /usr/bin

uninstall:
	@echo '** Uninstalling...'
	rm -f /usr/bin/sfml-app