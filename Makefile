output: main.o
	gcc main.o -o Maze_3D

main.o: main.c
	gcc -c main.c

graphics.o: graphics.c graphics.h
	gcc -c graphics.c

menu.o: menu.c menu.h
	gcc -c menu.c

mazemove.o: mazemove.c mazemove.h
	gcc -c mazemove.c

wincom.o: wincom.c wincom.h
	gcc -c wincom.c

clean:
	rm *.o output
