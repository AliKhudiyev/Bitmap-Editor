
#pragma once

#include"bmp.hpp"
#include"shape.hpp"

/*   Digits   */

// extern const Shape __0;
// extern const Shape __1;
// extern const Shape __2;
// extern const Shape __3;
// extern const Shape __4;
// extern const Shape __5;
// extern const Shape __6;
// extern const Shape __7;
// extern const Shape __8;
// extern const Shape __9;

/*  Letters    */

// extern const Shape __a;
// extern const Shape __b;
// extern const Shape __c;
// extern const Shape __d;
// extern const Shape __e;
// extern const Shape __f;
// extern const Shape __g;
// extern const Shape __h;
// extern const Shape __i;
// extern const Shape __j;
// extern const Shape __k;
// extern const Shape __l;
// extern const Shape __m;
// extern const Shape __n;
// extern const Shape __o;
// extern const Shape __p;
// extern const Shape __q;
// extern const Shape __r;
// extern const Shape __s;
// extern const Shape __t;
// extern const Shape __u;
// extern const Shape __v;
// extern const Shape __w;
// extern const Shape __x;
// extern const Shape __y;
// extern const Shape __z;

// extern const Shape __A;
// extern const Shape __B;
// extern const Shape __C;
// extern const Shape __D;
// extern const Shape __E;
// extern const Shape __F;
// extern const Shape __G;
// extern const Shape __H;
// extern const Shape __I;
// extern const Shape __J;
// extern const Shape __K;
// extern const Shape __L;
// extern const Shape __M;
// extern const Shape __N;
// extern const Shape __O;
// extern const Shape __P;
// extern const Shape __Q;
// extern const Shape __R;
// extern const Shape __S;
// extern const Shape __T;
// extern const Shape __U;
// extern const Shape __V;
// extern const Shape __W;
// extern const Shape __X;
// extern const Shape __Y;
// extern const Shape __Z;

/*   Special characters   */

// extern const Shape __add;
// extern const Shape __sbtr;
// extern const Shape __mult;
// extern const Shape __div;
// extern const Shape __equal;
// extern const Shape __gt;        // >
// extern const Shape __lt;        // <
// extern const Shape __parant;    // ()
// extern const Shape __brack;     // []
// extern const Shape __pow;
// extern const Shape __dollar;
// extern const Shape __and;
// extern const Shape __mod;
// extern const Shape __percent;
// extern const Shape __question;
// extern const Shape __colon;
// extern const Shape __comma;
// extern const Shape __exclamation;   // !
// extern const Shape __point;

/*   All characters in one place   */

#define STANDARD_FONT 0
#define CLASSIC_FONT 1

class TEXT{
    static const unsigned n_char_=94;
    friend BMP& BMP::draw_text(const std::string& text, const Position2D& position, double magnify, const Color& color, const thickness_t thickness);
    
    private:
    Shape Char_[n_char_];

    public:
    TEXT(){
        init(STANDARD_FONT);
    }
    TEXT(unsigned font_type){
        init(font_type);
    }

    void magnify(double f);
    void magnify(unsigned index, double f);
    void rotate(angle_t angle);
    void rotate(unsigned index, angle_t angle);

    // Shape& get_char_(unsigned i);
    // Shape& Char(unsigned i);

    private:
    void init(unsigned font_type);
};

extern TEXT __Font_Standard;
extern TEXT __Font_Classic;
