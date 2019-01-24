#include"color.hpp"
#include<iostream>

/* Color palette */
/* Source : https://en.wikipedia.org/wiki/Web_colors */

const Color COLOR::White=Pick(255, 255, 255);
const Color COLOR::Black=Pick(0, 0, 0);
const Color COLOR::Red=Pick(255, 0, 0);
const Color COLOR::Green=Pick(0, 128, 0);
const Color COLOR::Blue=Pick(0, 0, 255);
const Color COLOR::Grey=Pick(128, 128, 128);
const Color COLOR::Purple=Pick(128, 0, 128);
const Color COLOR::Yellow=Pick(255, 255, 0);
const Color COLOR::Silver=Pick(192, 192, 192);
const Color COLOR::Lime=Pick(0, 255, 0);
const Color COLOR::Navy=Pick(0, 0, 128);
const Color COLOR::Fuchsia=Pick(255, 0, 255);
const Color COLOR::Aqua=Pick(0, 255, 255);
const Color COLOR::Maroon=Pick(128, 0, 0);
const Color COLOR::Olive=Pick(128, 128, 0);
const Color COLOR::Teal=Pick(0, 128, 128);

/* Color */

void Color::reverse(){
    uchar r_tmp=r_;
    r_=b_;
    b_=r_tmp;
}

double Color::mean() const{
    return (double)(r_+g_+b_)/3;
}

uchar Color::operator[](unsigned i){
    uchar value=0;
    switch(i){
        case 0:
            value=r_;
            break;
        case 1:
            value=g_;
            break;
        case 2:
            value=b_;
            break;
        case 3:
            value=a_;
            break;
        default: break;
    }
    return value;
}

Color Color::operator+(const Color& color) const{
    Color tmp;
    tmp.r_=r_+color.r_;
    tmp.g_=g_+color.g_;
    tmp.b_=b_+color.b_;
    return tmp;
}

Color Color::operator-(const Color& color) const{
    Color tmp;
    tmp.r_=r_-color.r_;
    tmp.g_=g_-color.g_;
    tmp.b_=b_-color.b_;
    return tmp;
}

Color Color::operator*(double coef) const{
    Color tmp;
    tmp.r_=r_*coef;
    tmp.g_=g_*coef;
    tmp.b_=b_*coef;
    return tmp;
}

Color& Color::operator+=(const Color& color){
    r_+=color.r_;
    g_+=color.g_;
    b_+=color.b_;
    return *this;
}

Color& Color::operator-=(const Color& color){
    r_-=color.r_;
    g_-=color.g_;
    b_-=color.b_;
    return *this;
}

Color& Color::operator*=(double coef){
    r_*=coef;
    g_*=coef;
    b_*=coef;
    return *this;
}

void Color::operator=(const Color& color){
    r_=color.r_;
    g_=color.g_;
    b_=color.b_;
    a_=color.a_;
}

bool Color::operator==(const Color& color) const{
    if(r_==color.r_ && g_==color.g_ && b_==color.b_ && a_==color.a_) return true;
    return false;
}
