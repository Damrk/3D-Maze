#include "graphics.h"
#include <stdio.h>


void drawH(char type, int x, int y, int endx, char display[][HEI])
{
    for(int i = x; i <= endx; i++)
    {
        display[i][y] = type;
    }
}
void drawV(char type, int x, int y, int endy, char display[][HEI])
{
    for(int i = y; i <= endy; i++)
    {
        display[x][i] = type;
    }
}
void drawDR(int xe, int ye, char display[][HEI])
{
    char tile[2][4] = {{' ', ' ', BK, BK},
                       {BK, BK, ' ', ' '}};
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 2; y++)
        {
            display[x+xe][y+ye] = tile[y][x];
        }
    }
}
void drawDL(int xe, int ye, char display[][HEI])
{
    char tile[2][4] = {{BK, BK, ' ', ' '},
                       {' ', ' ', BK, BK}};
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 2; y++)
        {
            display[x+xe][y+ye] = tile[y][x];
        }
    }
}

void blank(int sx, int sy, int ex, int ey, char display[][HEI])
{
    for(int x = sx; x <= ex; x++)
    {
        for(int y = sy; y <= ey; y++)
        {
            display[x][y] = ' ';
        }
    }
}

/* draw border */
void border(char display[][HEI], int wid, int hei)
{
    blank(0, 0, wid-1, hei-1, display);
    for(int y = 0; y < hei; y++)
    {
        for(int x = 0; x < wid; x++)
        {
            display[x][y] = ' ';
        }
    }
    display[0][0] = TL;
    display[wid-1][0] = TR;
    display[0][hei-1] = BL;
    display[wid-1][hei-1] = BR;
    drawV(VT, 0, 1, hei-2, display);
    drawV(VT, wid-1, 1, hei-2, display);
    drawH(HZ, 1, 0, wid-2, display);
    drawH(HZ, 1, hei-1, wid-2, display);
}

/* Render first cell 1 - 5*/
void render1(int view, char display[][HEI])
{
    switch(view)
    {
        case 1:
            drawDL(1, 1, display);
            drawDR(1,13, display);
            drawV(BK, 5, 3, 12, display);
            break;
        case 2:
            drawH(BK, 1, 3, 5, display);
            drawH(BK, 1, 12, 5, display);
            break;
        case 3:
            drawH(LT, 1, 5, 5, display);
            drawH(LT, 1, 10, 5, display);
            break;
        case 4:
            blank(1, 1, 5, 14, display);
            break;
        default:
            break;
    }
}

/* Render second cell 6 - 9*/
void render2(int view, char display[][HEI])
{
    switch(view)
    {
        case 1:
            drawDL(5, 3, display);
            drawDR(5,11, display);
            drawV(BK, 5, 3, 12, display);
            drawV(MD, 9, 5, 10, display);
            break;
        case 2:
            drawH(LT, 6, 5, 9, display);
            drawH(LT, 6, 10, 9, display);
            drawV(LT, 9, 5, 10, display);
            break;
        case 3:
            blank(6,1,9,14,display);
            break;
        default:
            break;
    }
}

/* Render third cell 10 - 19*/
void render3(int view, char display[][HEI])
{
    switch(view)
    {
        case 1:
            blank(6,3,23,14,display);
            drawH(BK,6,3,24,display);
            drawH(BK,6,12,24,display);
            drawV(BK, 5, 3, 12, display);
            drawV(BK, 25, 3, 12, display);
            break;
        case 2:
            drawV(LT, 9, 5, 10, display);
            drawH(LT,10,5,20,display);
            drawH(LT,10,10,20,display);
            drawV(LT, 21, 5, 10, display);
            break;
        case 3:
            blank(10,1,19,14,display);
        default:
            break;
    }
}

/* Render fourth cell 20 - 24*/
void render4(int view, char display[][HEI])
{
    switch(view)
    {
        case 1:
            drawV(LT, 21, 5, 10, display);
            drawDR(22, 3, display);
            drawDL(22, 11, display);
            break;
        case 2:
            drawH(LT, 22, 5, 24, display);
            drawH(LT, 22, 10, 24, display);
            drawV(LT, 21, 5, 10, display);
            break;
        case 3:
            blank(22, 1, 23, 14, display);
        default:
            break;
    }
}

/* Render fifth cell 25 - 29*/
void render5(int view, char display[][HEI])
{
    switch(view)
    {
        case 1:
            drawDL(26, 13, display);
            drawDR(26, 1, display);
            drawV(BK, 25, 3, 12, display);
            break;
        case 2:
            drawV(BK, 25, 3, 12, display);
            drawH(BK, 25, 3, 29, display);
            drawH(BK, 25, 12, 29, display);
            break;
        case 3:
            drawH(LT, 25, 5, 29, display);
            drawH(LT, 25, 10, 29, display);
            break;
        case 4:
            blank(26, 1, 29, 14, display);
            break;
        default:
            break;
    }
}

/* display screen */
void finalR(char display[][HEI])
{
    for(int y = 0; y < HEI; y++)
    {
        for(int x = 0; x < WID; x++)
        {
            printf("%c", display[x][y]);
        }
        printf("\n");
    }
}
