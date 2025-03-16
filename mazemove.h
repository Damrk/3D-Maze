#ifndef MAZEMOVE_H
#define MAZEMOVE_H

#include "graphics.h" 

#define MAX 50 /* maze size of array*/
#define MSZ 10 /* Map size*/
#define KEY 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27


struct MAZER
{
    int x;
    int y;
    enum dir_t {north, west, south, east} dir;
    char compas;
};

struct REND
{
    int R1; /* close 1 to 4 far*/
    int R2; /* close 1 to 3 far*/
    int R3; /* close 1 to 3 far*/
    int R4; /* close 1 to 3 far*/
    int R5; /* close 1 to 4 far*/
};

struct MAZER input(int map[][MSZ], struct MAZER advent);
struct REND search(int map[][MSZ], struct MAZER advent);
struct MAZER rotateMap(char rot, int map[][MSZ], struct MAZER advent);
void emptyBuffer(void);
void rendering(int map[][MSZ], struct MAZER advent, char display[][HEI]);
#endif
