#include "mazemove.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

struct MAZER input(int map[][MSZ], struct MAZER advent)
{
    int input = getch();
    if(input == 224)
    {
        int key = getch();
        switch(key)
        {
            case UP:
                if(map[advent.y-1][advent.x] != 1)
                {
                    advent.y -= 1; 
                }
                else
                {
                    Beep(500,200);   
                }
                break;
            case DOWN:
                if(map[advent.y+1][advent.x] != 1)
                {
                    advent.y += 1; 
                }
                break;
            case LEFT:
                advent = rotateMap('R', map, advent);
                break;
            case RIGHT:
                advent = rotateMap('L', map, advent);
                break;
            default:
                break;   
        } 
    }
    else
    {
        switch(input)
        {
            case ENTER:
                printf("> ");
                getchar();
                emptyBuffer();
                break;
            case ESC:
                PlaySound(NULL,NULL,SND_ASYNC | SND_LOOP);
                break;
        }
    }
    return advent;
}

struct REND search(int map[][MSZ], struct MAZER advent)
{
    struct REND rend = {4,3,3,3,4};
    system("cls");
    int i = 3;
    for(int y = -2; y <= 0; y++)
    {
        if(map[advent.y+y][advent.x-1] == 1)
        {
            rend.R1 = i;
            if(y != 0)
            {
                rend.R2 = i-1;   
            }   
        }
        i--;
    }
    /* R3 */
    int j = 2;
    for(int y = -2; y < 0; y++)
    {
        if(map[advent.y+y][advent.x] == 1)
        {
            rend.R3 = j;
        }
        j--;
    }
    /*R4R5 render */
    int t = 3;
    for(int y = -2; y <= 0; y++)
    {
        if(map[advent.y+y][advent.x+1] == 1)
        {
            rend.R5 = t;
            if(y != 0)
            {
                rend.R4 = t-1;
            }   
        }
        t--;
    }
    return rend;
}

struct MAZER rotateMap(char rot, int map[][MSZ], struct MAZER advent)
{
    int temp[MSZ][MSZ] = {0};
    int yb, xb;
    int locX, locY;
    if(rot == 'R')
    {
        xb = MSZ-1;
        for(int y = 0; y < MSZ; y++)
        {
            yb = 0;
            for(int x = 0; x < MSZ; x++)
            {
                temp[yb][xb] = map[y][x];
                if(advent.y == y && advent.x == x)
                {
                    locX = xb;
                    locY = yb;
                }
                yb++;
            }
            xb--;
        }   
    }
    else if(rot == 'L')
    {
        xb = 0;
        for(int y = 0; y < MSZ; y++)
        {
            yb = MSZ-1;
            for(int x = 0; x < MSZ; x++)
            {
                temp[yb][xb] = map[y][x];
                if(advent.y == y && advent.x == x)
                {
                    locX = xb;
                    locY = yb;
                }
                yb--;
            }
            xb++;
        }   
    }
    for(int y = 0; y < MSZ; y++)
    {
        for(int x = 0; x < MSZ; x++)
        {
            map[y][x] = temp[y][x];
        }
    }
    advent.x = locX;
    advent.y = locY;
    return advent;
}

void emptyBuffer(void)
{
    while(getchar() != '\n')
    {
        ;
    }
}

void rendering(int map[][MSZ], struct MAZER advent, char display[][HEI])
{
    
    struct REND rend = search(map, advent);
    blank(1,1,WID-2,HEI-2, display);
    render1(rend.R1, display); 
    render2(rend.R2, display);
    render3(rend.R3, display);
    if(rend.R3 != 1)
    {
        render4(rend.R4, display);   
    }
    render5(rend.R5, display);
    finalR(display);
}
