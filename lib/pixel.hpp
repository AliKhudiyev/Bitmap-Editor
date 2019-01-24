/*
 * Pixel header file is to store pixels with its 2 important attributes: colors and positions in 2D space.
 * The Pixel class is simple enough to interact with, it does not have many functionalities.
 * Just store pixels simply and safely.
*/

#pragma once

#include"color.hpp"
#include"position2D.hpp"

#define Point Pixel

class Pixel{
    private:
    Color color_=COLOR::Black;
    Position2D position_=ORIGIN;

    public:
    Pixel()=default;
    Pixel(const Color& color): 
        color_(color) {}
    Pixel(const Position2D& position): 
        position_(position) {}
    Pixel(const Color& color, const Position2D& position): 
        color_(color), position_(position) {}

    void set_color(const Color& color);
    void set_position(const Position2D& position);
    Color& get_color();
    Position2D& get_position();

    const Color& color() const;
    const Position2D& position() const;

    bool operator==(const Pixel& pixel) const;
    bool operator!=(const Pixel& pixel) const;

    Similarity_T compare(const Pixel& pixel) const;
};
