/*
 * The shape header file helps user to store any kind of shape with its positions(and possibly colors).
 * This class has 3 child classes which are triangle, rectangle and circle.
 * These 3 subclasses are here to ease the job, however, any shape(including these 3) can be stored under the name of shape.
 * This class is not an abstract class so it can have objects as well.
 * Supports several virtual functions to be able to extend the functionality in case of individual problems.
*/

#pragma once

#include<vector>
#include"pixel.hpp"

enum Shape_T{
    Triangle_t=0,
    Rectangle_t,
    Circle_t,
    Figure_t
};

class Shape{
    private:
    std::vector<Pixel> pixel_;

    protected:
    Shape_T type_;
    unsigned n_side_;
    unsigned width_, height_;

    public:
    Shape()=default;
    Shape(const std::vector<Pixel>& pixel): 
        pixel_(pixel), n_side_(pixel.size()-1) 
    {
        update();
    }
    Shape(const std::vector<Position2D>& position): 
        n_side_(position.size()-1) 
    {   
        pixel_.resize(n_side_+1);
        for(unsigned i=0;i<=n_side_;++i) pixel_[i]=Pixel(position[i]);
        update();
    }

    virtual unsigned n_side() const;
    virtual std::string type() const;
    virtual unsigned total_inside_angle() const;
    virtual double area() const;
    virtual double perimeter() const;
    virtual void rotate(angle_t angle);
    virtual void move(position_t dx, position_t dy);
    virtual void set_width(unsigned width);
    virtual void set_height(unsigned height);
    virtual unsigned width() const;
    virtual unsigned height() const;
    virtual void add_xy(position_t x, position_t y);
    virtual Pixel& get_pixel(unsigned i);

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape);
    virtual const Pixel& operator[](unsigned i) const;
    virtual bool operator==(const Shape& shape) const;
    virtual bool operator!=(const Shape& shape) const;
    Shape& operator=(const Shape& shape);

    virtual Similarity_T compare(const Shape& shape) const;

    private:
    void update();
};

class Triangle: public Shape{
    private:
    Pixel pixel_[3];

    public:
    Triangle()=default;
    Triangle(const Pixel pixel[3]): 
        pixel_{pixel[0], pixel[1], pixel[2]} {}
    Triangle(const Pixel& pixel1, const Pixel& pixel2, const Pixel& pixel3): 
        pixel_{pixel1, pixel2, pixel3} {}
    Triangle(const Position2D position[3]){}
    Triangle(const Position2D& position1, const Position2D& position2, const Position2D& position3){}

    unsigned n_side() const;
    std::string type() const;
    unsigned total_inside_angle() const;
    double area() const;
    double perimeter() const;
    void rotate(angle_t angle);
    void move(position_t dx, position_t dy);

    const Pixel& operator[](unsigned i) const;
    bool operator==(const Shape& shape) const;
    bool operator!=(const Shape& shape) const;

    Similarity_T compare(const Shape& shape) const;
};

class Rectangle: public Shape{
    private:
    Pixel pixel_[4];

    public:
    Rectangle()=default;
    Rectangle(position_t x){}
    Rectangle(const Pixel pixel[4]){}
    Rectangle(const Pixel& pixel, int width, int height, angle_t rotate=0){}
    Rectangle(const Pixel& pixel1, const Pixel& pixel2, const Pixel& pixel3){}
    Rectangle(const Position2D position[4]){}
    Rectangle(const Position2D& position, int width, int height, angle_t rotate=0){}
    Rectangle(const Position2D& position1, const Position2D& position2, const Position2D& position3){}

    unsigned n_side() const;
    std::string type() const;
    unsigned total_inside_angle() const;
    double area() const;
    double perimeter() const;
    void rotate(angle_t angle);
    void move(position_t dx, position_t dy);

    const Pixel& operator[](unsigned i) const;
    bool operator==(const Shape& shape) const;
    bool operator!=(const Shape& shape) const;

    Similarity_T compare(const Shape& shape) const;
};

class Circle: public Shape{
    private:
    unsigned radius;
    Pixel pixel_[4];

    public:
    Circle()=default;
    Circle(const Pixel pixel[2]){}
    Circle(const Pixel& pixel1, const Pixel& pixel2);
    Circle(const Pixel& pixel, unsigned radius);
    Circle(const Position2D& position, unsigned radius){}
    Circle(const Position2D& position1, const Position2D& position2){}
    Circle(const Position2D position[2]){}

    unsigned n_side() const;
    std::string type() const;
    unsigned total_inside_angle() const;
    double area() const;
    double perimeter() const;
    void rotate(angle_t angle);
    void move(position_t dx, position_t dy);

    const Pixel& operator[](unsigned i) const;
    bool operator==(const Shape& shape) const;
    bool operator!=(const Shape& shape) const;

    Similarity_T compare(const Shape& shape) const;
};
