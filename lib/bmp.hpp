/*
 * Bitmap header file is the "core file" which contains lots of public functions.
 * It has over 15 public functions and it is a big class.
 * Pretty much every functionality has been put here.
*/

#pragma once

#include<string>
#include"color_table.hpp"
#include"bmp_info.hpp"
#include"shape.hpp"

class BMP{
    static Color def_color;
    static thickness_t def_thick;

    private:
    std::string name_;
    std::vector<byte> header_;
    Color_Table table_;
    BMP_Info info_;

    public:
    BMP()=default;
    BMP(const std::string& name);
    BMP(const std::string& name, const std::string& file_name);

    void set_color(const Color& color);
    void set_thickness(const thickness_t thickness);

    static BMP blank(unsigned width, unsigned height, const Color& color=COLOR::White);
    BMP& draw_point(const Position2D& position, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_line(const Position2D& position1, const Position2D& position2, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_line(const Position2D position[2], const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_triangle(const Position2D& position1, const Position2D& position2, const Position2D& position3, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_triangle(const Position2D position[3], const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_triangle(const Triangle& triangle, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_rectangle(const Position2D position[4], const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_rectangle(const Rectangle& rectangle, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_circle(const Position2D& position1, const Position2D& position2, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_circle(const Position2D position[2], const Color& color=def_color, const thickness_t thickness=BMP::def_thick);
    BMP& draw_circle(const Circle& circle, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_circle(const Position2D& position, unsigned radius, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_shape(const Shape& shape, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw(const std::vector<Position2D>& positions, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_text(const std::string& text, const Position2D& position, double magnify=1, const Color& color=def_color, const thickness_t thickness=def_thick);
    BMP& draw_function(const std::string& function, const Color& color=def_color, const thickness_t thickness=def_thick);

    BMP& detect_borders();
    BMP& scale(double on_axis=1);
    BMP& scale(double on_x, double on_y);
    BMP& scale(unsigned char axis, double factor, unsigned height, unsigned dh);
    BMP& scale(double h_factor, unsigned height, double w_factor, unsigned width);
    BMP& rotate(angle_t angle);
    BMP& crop(unsigned width, unsigned height);
    BMP extract_vertical(unsigned width) const;
    BMP extract_horizontal(unsigned height) const;

    void save() const;
    void save(const std::string& name) const;
    void load(const std::string& file_name);
    void load(const BMP& image);
    void remove();

    BMP operator=(const BMP& image);

    private:
    void read(const std::string& file_name);
    void write(const std::string& file_name) const;
    void update();

    bool draw(const Position2D position[2], const Color& color, const thickness_t thickness);
    bool draw(const Position2D& position1, const Position2D& position2, const Color& color, const thickness_t thickness);
    BMP& v_scale(double factor, unsigned width, unsigned dw);
    BMP& h_scale(double factor, unsigned height, unsigned dh);
    BMP& v_crop(unsigned width);
    BMP& h_crop(unsigned height);
};
