//!       @file CatTreeLib.h
//!
//!       @mainpage
//!       Эта библиотека помогает вам рисовать котиков и живые деревья \n
//!       \n
//!      - @ref DrawStart ()
//!      - @ref DrawSun ()
//!      - @ref DrawTree ()
//!      - @ref DrawCat ()
//!      - @ref DrawDanceTitre ()
//!      - @ref DrawFinalTitre ()
//!      - @ref DrawTitleBackGround ()
//!

#include "TXLib.h"

const COLORREF SUPER_PURE_YELLOW = RGB (255, 255,   0);
const COLORREF SUPER_TREE        = RGB (100,  52,  52);
const COLORREF SUPER_GLASS       = RGB (  5, 105,  13);
const COLORREF SKY_SKY           = RGB (114, 197, 192);

//!--------------------------------------------------
//!      Функция рисует фон основной сцены
//!--------------------------------------------------

void DrawStart ();



//!--------------------------------------------------------------------------
//!      Функция рисует движущееся солнце
//!
//!  @param t - целочисленный момент времени для расчета положения солнышка
//!  @param x - стартовое положение солнышка по горизонтали
//!  @param y - стартовое положение солнышка по вертикали
//!
//!--------------------------------------------------------------------------

void DrawSun (int t, double x, double y);


//!--------------------------------------------------------------------------
//!      Функция рисует дерево
//{
//!  @param x - горизонтальная координата центра основания дерева
//!  @param y - вертикальная координата центра основания дерева
//!  @param TopRight - толщина ствола сверху справа от центра
//!  @param TopLeft - толщина ствола сверху слева от центра
//!  @param TopHeight - высота ствола от корней до начала кроны
//!  @param BottomRight - расстояние от центра основания дерева до правого корня
//!  @param BottomLeft - расстояние от центра основания дерева до левого корня
//!  @param BottomHeight - высота подъема корней над линией земли
//!  @param widthLeevesRight - толщина кроны справа от центра
//!  @param widthLeevesLeft - толщина кроны слева от центра
//!  @param heightLeeves - высота кроны
//!  @param colorBase - цвет ствола, можно задать типовые, можно использовать функцию RBG(red, green, blue), где цвета - это числа в диапазоне 0-255
//!  @param colorLeeves - цвет листвы, можно задать типовые, можно использовать функцию RBG(red, green, blue), где цвета - это числа в диапазоне 0-255
//}
//!------------------------------------------------------------------------------------------------------------------------------------------------------

void DrawTree  (double x,                double y,
                double TopRight,         double TopLeft,          double TopHeight,
                double BottomRight,      double BottomLeft,       double BottomHeight,
                double widthLeevesRight, double widthLeevesLeft, double heightLeeves,
                COLORREF colorBase,     COLORREF colorLeeves);



//!----------------------------------------------------------------------------------------
//!      Функция рисует котика
//{
//!     @param x  - положение котика по горизонтали (линия земли)
//!     @param y  - положение котика по вертикали (линия земли)
//!     @param catWidth - ширина тела котика
//!     @param catHeight- высота тела котика
//!     @param tailWidth- ширина хвотика
//!     @param tailHeight - длина хвостика
//!     @param legHeight - ширина лапок
//!     @param legWidth- длина лапок
//!     @param EyeRadiusX - горизонтальный радиус глаз
//!     @param EyeRadiusY - вертикальный радиус глаз
//!     @param colorEye - цвет глаз, можно задать типовые, можно использовать функцию RBG(red, green, blue), где цвета - это числа в диапазоне 0-255
//!     @param colorBase - цвет туловища, можно задать типовые, можно использовать функцию RBG(red, green, blue), где цвета - это числа в диапазоне 0-255
//!     @param colorLegs - цвет лапок, можно задать типовые, можно использовать функцию RBG(red, green, blue), где цвета - это числа в диапазоне 0-255
//!     @param colorTail - цвет хвоста, можно задать типовые, можно использовать функцию RBG(red, green, blue), где цвета - это числа в диапазоне 0-255
//!
//!---------------------------------------------------------------------------------
//}

void DrawCat   (double x,          double y,
                double catWidth,   double catHeight,
                double tailWidth,  double tailHeight,
                double legHeight,  double legWidth,
                double EyeRadiusX, double EyeRadiusY,
                COLORREF colorEye, COLORREF colorBase, COLORREF colorLegs, COLORREF colorTail);

//!-----------------------------------------------------------------------------------------
//!      Функция вращает и перемещает текст  слева направо с изменением цвета
//{
//!  @param t - момент времени, целочисленный
//!  @param RightX - горизонтальнаяя координата начала движения текста
//!  @param y - вертикальная координата начала движения текста
//!  @param text[] - текст, который будет перемещаться
//!  @param color - начальный цвет текста
//}
//!-----------------------------------------------------------------------------------------

void DrawDanceTitre (int t, double RightX, double y, const char text[], COLORREF color);


//!------------------------------------------------------------------------------------------
//!      Функция рисует движущиеся вверх титры
//!-------------------------------------------------------------------------------------------
void DrawFinalTitre (int t, double RightX, double y, const char text[], COLORREF color);


//!------------------------------------------------------------------------------------------
//!      Функция рисует фон для титров
//!------------------------------------------------------------------------------------------
void DrawTitleBackGround(COLORREF color);


//=====================
//   @code
//======================


void DrawStart()
    {
    txSetColor (SUPER_GLASS);
    txSetFillColor (SUPER_GLASS);
    txRectangle (  0, 240, 800, 600);

    txSetColor (SKY_SKY);
    txSetFillColor (SKY_SKY);
    txRectangle (  0, 0, 800, 240);
    };


void DrawSun (int t, double x, double y)
    {
    double SunX = x + t;
    double SunY = y-0.03*t*t;
    COLORREF colorSun = RGB (255, 255 - 2*t, 128 + 5*t);

    txSetColor (colorSun);
    txSetFillColor (colorSun);
    txEllipse (SunX - 20, SunY - 20, SunX + 20, SunY + 20);
    }


void DrawTree (double x,              double y,
               double TopRight,        double TopLeft,          double TopHeight,
               double BottomRight,     double BottomLeft,       double BottomHeight,
               double widthLeevesLeft, double widthLeevesRight, double heightLeeves,
               COLORREF colorBase, COLORREF colorLeeves)
    {

    txSetColor (colorBase);
    txSetFillColor (colorBase);
    txLine (x,               y - BottomHeight,             x + BottomRight, y);
    txLine (x + BottomRight, y,                            x + TopRight,    y - BottomHeight - TopHeight);
    txLine (x + TopRight,    y - BottomHeight - TopHeight, x - TopLeft,     y - BottomHeight - TopHeight);
    txLine (x - TopLeft,     y - BottomHeight - TopHeight, x - BottomLeft, y);
    txLine (x - BottomLeft, y,                            x,               y - BottomHeight);
    txFloodFill (x, y - BottomHeight - 1, colorBase, FLOODFILLBORDER);

    txSetColor (colorLeeves);
    txSetFillColor (colorLeeves);
    txEllipse (x-widthLeevesLeft,  y - (TopHeight + BottomHeight + heightLeeves), x + widthLeevesRight, y - 0.9*(TopHeight + BottomHeight));
    }


void DrawCat (double x,          double y,
              double catWidth,   double catHeight,
              double tailWidth,  double tailHeight,
              double legHeight,  double legWidth,
              double EyeRadiusX, double EyeRadiusY,
              COLORREF colorEye, COLORREF colorBase, COLORREF colorLegs, COLORREF colorTail)
    {
    double headWidth = 3*catWidth/5;
    double headHeight = 3*catHeight/5;

    txSetColor (colorLegs);
    txSetFillColor (colorLegs);
    txEllipse (x - 0.8*catWidth/2 - legWidth/2, y - 1.1*legHeight, x - 0.8*catWidth/2 + legWidth/2, y);
    txEllipse (x - 0.7*catWidth/2, y - 1.1*legHeight, x - 0.7*catWidth/2 + legWidth, y);

    txEllipse (x + 0.9*catWidth/2 - legWidth/2, y - 1.3*legHeight, x + 0.9*catWidth/2 + legWidth/2, y);
    txEllipse (x + 0.8*catWidth/2 - legWidth/2, y - 1.3*legHeight, x + 0.8*catWidth/2 + legWidth/2, y);

    txSetColor (colorTail);
    txSetFillColor (colorTail);
    txEllipse (x + catWidth/2 - tailWidth/2, y - 0.8*legHeight - catHeight/2 - tailHeight, x + catWidth/2 + tailWidth/2, y - 0.8*legHeight - catHeight/2);

    txSetColor (colorBase);
    txSetFillColor (colorBase);
    txEllipse (x - catWidth/2, y - 0.9*legHeight - catHeight, x + catWidth/2, y - 0.9*legHeight);

    txEllipse (x - catWidth/2 - headWidth/2, y - 0.9*legHeight - catHeight - 0.9*headHeight, x - catWidth/2 + headWidth/2, y - 0.7*legHeight - catHeight);

    txSetColor (colorEye);
    txSetFillColor (colorEye);
    txEllipse (x - catWidth/2 - EyeRadiusX, y - 0.9*legHeight - catHeight - headHeight/2 - EyeRadiusY, x - catWidth/2 + EyeRadiusX, y - 0.9*legHeight - catHeight - headHeight/2 + EyeRadiusY);
    txSetColor (TX_BLACK, 2);
    txLine (x - catWidth/2, y - 0.9*legHeight - catHeight - headHeight/2 - 0.8*EyeRadiusY, x - catWidth/2, y - 0.9*legHeight - catHeight - headHeight/2 + 0.8*EyeRadiusY);


    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txEllipse (x - catWidth/2 - headWidth/2, y - 0.9*legHeight - catHeight - 0.9*headHeight/2 - EyeRadiusY, x - catWidth/2 - headWidth/2 + EyeRadiusY, y - 0.9*legHeight - catHeight - headHeight/2 + EyeRadiusY);

    };


void DrawDanceTitre (int t, double RightX, double y, const char text[], COLORREF color)
    {
    int red   = txExtractColor (color, TX_RED);
    int green = txExtractColor (color, TX_GREEN);
    int blue  = txExtractColor (color, TX_BLUE);

    txSetColor (RGB(red -2*t, green-2*t, blue));
    txSelectFont ("Comic Sans MS", 20*round(abs(t%40-20)-10), 10*round(abs(t%20-10)-5), false, true, false, false, 15*round(abs(t%360-180)) );
    txTextOut (RightX - t*5, y, text);
    }


 void DrawFinalTitre (int t, double RightX, double y, const char text[], COLORREF color)
    {
    int red   = txExtractColor (color, TX_RED);
    int green = txExtractColor (color, TX_GREEN);
    int blue  = txExtractColor (color, TX_BLUE);

    txSetColor (RGB(red - 2*t, green - 2*t, blue - 2*t));
    txSelectFont ("Comic Sans MS", 40, 20, false, true, true, false, 0);
    txSetTextAlign (TA_CENTER);
    txTextOut (RightX/2, y - t*8, text);
    }

void DrawTitleBackGround(COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);
    txRectangle (0, 0, 800,600);
    }
