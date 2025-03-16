#ifndef GRAPHICS_H
#define GRAPHICS_H

#define WID 31
#define HEI 16

#define TL 201
#define TR 187
#define BL 200
#define BR 188
#define HZ 205
#define VT 186

#define BK 178
#define MD 177
#define LT 176

void drawH(char type, int x, int y, int endx, char display[][HEI]);
void drawV(char type, int x, int y, int endy, char display[][HEI]);
void drawDR(int xe, int ye, char display[][HEI]);
void drawDL(int xe, int ye, char display[][HEI]);
void blank(int sx, int sy, int ex, int yx, char display[][HEI]);
void border(char display[][HEI], int wid, int hei);
void render1(int view, char display[][HEI]);
void render2(int view, char display[][HEI]);
void render3(int view, char display[][HEI]);
void render4(int view, char display[][HEI]);
void render5(int view, char display[][HEI]);
void finalR(char display[][HEI]);

#endif
