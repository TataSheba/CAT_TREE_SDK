#include "TXLib.h"
#include "CatTreeLib.h"

void ScenaBegin ();
void ScenaBase ();
void ScenaEnd ();

//----------------------------------------------------------------------------


int main()
    {
    txCreateWindow (800, 600);
    txBegin();

    ScenaBegin();

    ScenaBase();

    ScenaEnd();

    txEnd();

    return 0;
    }


//----------------------------------------------------------------------------

void ScenaBegin ()
    {
    int t = 0;
    while (t <= 140)
        {
        DrawTitleBackGround (TX_BLACK);
        DrawDanceTitre (t, 800, 270, "Однажды в домике у леса...", RGB(147, 147, 255));

        txSleep (40);
        t++;
        };
    }


void ScenaBase ()
    {
    int t = 0;
    while (t <=100)
        {
        int shift    = abs (t%12 - 6) -3;
        int shiftEye = abs (t% 4 - 2) - 1;

        DrawStart ();
        DrawSun (t, 0, 200);
        DrawTree (  65 + t*5, 380, 15,  20, 100, 70, 50, 10, 70, 50, 100, SUPER_TREE,        TX_GREEN);
        DrawTree ( 755 - 3*t, 500, 10,  10,  70, 40, 40,  2, 85, 45, 150, RGB( 64,  0,   0), TX_LIGHTGREEN);
        DrawTree (       115, 480, 15,   5,  45, 45, 70, 25, 78, 90 + abs (t%20 - 10) - 5, 120 + abs (t%32 - 16) - 8, RGB(128,128, 128), TX_CYAN);
        DrawCat (300, 500, 50 + shift, 30 + shift, 15 + shift, 45, 25, 8, 4, 3, TX_YELLOW, TX_GRAY,  TX_BLACK, TX_DARKGRAY);
        DrawCat (480, 550, 70, 40, 10 + shift, 65, 15*abs (t%8 - 4) - 2, 8, 6 + shiftEye, 6 + shiftEye, TX_GREEN,  TX_WHITE, TX_GRAY, TX_GRAY);

        txSleep(20);
        t++;
        }
    }


void ScenaEnd()
        {
        int t = 0;
        while (t <= 80)
            {
            DrawTitleBackGround(TX_BLACK);
            DrawFinalTitre (t, 800, 450, "Берегите", RGB(147, 147, 255));
            DrawFinalTitre (t, 800, 500, "нервы котиков", RGB(167, 147, 255));
            DrawFinalTitre (t, 800, 550, "и природу!", RGB(187, 147, 255));

            txSleep (40);
            t++;
            };
        }

