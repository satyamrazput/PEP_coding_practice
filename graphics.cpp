#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int gdriver = DETECT, gmode;
    int errorcode;
    int xmax, ymax;

    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");

    errorcode = graphresult();

    if (errorcode != grOk)
    {
        printf("Graphics error: %s", grapherrormsg(errorcode));
        getch();
        return 1;
    }

    xmax = getmaxx();
    ymax = getmaxy();

    setcolor(getmaxcolor());

    line(0, 0, 0, 200);
    line(0, 0, 200, 0);
    line(200, 0, 200, 200);
    line(0, 200, 200, 200);

    setcolor(YELLOW);
    line(100, 100, 100, 100);

    getch();
    closegraph();

    return 0;
}