prog:integration.o mainInteg.o
	gcc integration.o mainInteg.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
mainInteg.o:mainInteg.c
	gcc -c mainInteg.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g  
integration.o: integration.c
	gcc -c integration.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
