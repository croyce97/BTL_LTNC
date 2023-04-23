CC = g++
CFLAGS = -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers  -F/Library/Frameworks -framework SDL2 -framework SDL2_image

all: main

main: main.cpp game.cpp game.h 
	$(CC) $(CFLAGS) main.cpp game.cpp  -o main

clean:
	rm -f main

