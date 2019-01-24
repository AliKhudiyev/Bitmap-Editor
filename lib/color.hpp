/*
 * This header file is one of the most necessary parts of the whole library.
 * Because it stores raw color segment values(which are r, g, b and alpha or opacity).
 * It supports both rgba and bgra formats in order to write or read from .bmp files in more user-friendly way.
 * It has couple of functionalities which help to do some arithmetic operations among colors.
 * The header file contains color palette with 16 colors as well. (Source : https://en.wikipedia.org/wiki/Web_colors).
*/

#pragma once

#include"exception.hpp"

#define Pick(r,g,b) Color(r,g,b,255,true)
#define Pick4(r,g,b,a) Color(r,g,b,a,true)

typedef unsigned char uchar;

class Color{
    private:
    uchar r_, g_, b_, a_=255;

    public:
    Color()=default;
    explicit Color(uchar rgb): 
        Color(rgb, rgb, rgb) {}
    Color(uchar r, uchar g, uchar b, uchar a=255, bool rvrs=false): 
        r_(r), g_(g), b_(b), a_(a) 
    {
        if(rvrs) reverse();
    }

    void reverse();
    double mean() const;

    uchar operator[](unsigned i);
    Color operator+(const Color& color) const;
    Color operator-(const Color& color) const;
    Color operator*(double coef) const;
    Color& operator+=(const Color& color);
    Color& operator-=(const Color& color);
    Color& operator*=(double coef);
    void operator=(const Color& color);
    bool operator==(const Color& color) const;
};

/*  Color palette  */

struct COLOR{
    static const Color White;
    static const Color Black;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Grey;
    static const Color Purple;
    static const Color Yellow;
    static const Color Silver;
    static const Color Lime;
    static const Color Navy;
    static const Color Fuchsia;
    static const Color Aqua;
    static const Color Maroon;
    static const Color Olive;
    static const Color Teal;
};
