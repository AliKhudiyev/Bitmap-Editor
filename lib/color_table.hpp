/*
 * Color table is to store bitmap file's color table and its padding information.
 * Of course, there are couple more attributes in this simple struct such as width and height.
*/

#pragma once

#include<vector>
#include"position2D.hpp"
#include"color.hpp"

typedef unsigned char byte;
typedef short int byte2;
typedef unsigned int byte4;

struct Color_Table{
    unsigned int width, height;
    unsigned short int n_padding_;
    std::vector<Color> color_;

    void w_init(unsigned width, const std::vector<Color>& color);
    void h_init(unsigned height, const std::vector<Color>& color);
    void init(unsigned width, unsigned height, const std::vector<Color>& color);

    void add_color(const Color& color, const Position2D& position);
    void modify_color(const Color& color, const Position2D& position);
    void remove_color(const Position2D& position);
    void clear();

    private:
    ;
};
