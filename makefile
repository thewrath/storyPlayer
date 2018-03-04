
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SRCS_DIR = sources/
INCLUDES_DIR = includes/

all: sfml-app clean

storyMap.o: $(SRCS_DIR)StoryMap.cpp 
	g++ -c $(SRCS_DIR)StoryMap.cpp -o storyMap.o

storyPlayer.o: $(SRCS_DIR)StoryPlayer.cpp 
	g++ -c $(SRCS_DIR)StoryPlayer.cpp -o storyPlayer.o 

main.o: $(SRCS_DIR)main.cpp
	g++ -c $(SRCS_DIR)main.cpp -o main.o

sfml-app: main.o storyMap.o storyPlayer.o
	@echo "** Building the exec"
	g++ -o sfml-app main.o storyMap.o storyPlayer.o $(LIBS)

clean:
	@echo "** Removing object files ..."
	rm -f *.o

install:
	@echo '** Installing...'
	cp sfml-app /usr/bin

uninstall:
	@echo '** Uninstalling...'
	rm -f /usr/bin/sfml-app