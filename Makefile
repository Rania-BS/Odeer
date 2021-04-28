prog:functions.o main.o
	gcc functions.o main.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g  
functions.o: functions.c
	gcc -c functions.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
