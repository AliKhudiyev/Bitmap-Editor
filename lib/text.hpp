
#pragma once

#include"bmp.hpp"
#include"shape.hpp"

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

    private:
    void init(unsigned font_type);
};

extern TEXT __Font_Standard;
extern TEXT __Font_Classic;
