/*
 * 2D(2 dimensional) (cartesian) space.
 * Header file contains all necessary attributes to store 2D positions.
 * It also supports some extra functions in order to process positions in even better way.
*/

#pragma once

#include<cmath>
#include"exception.hpp"

#define ORIGIN Position2D(0, 0)

typedef int position_t;
typedef unsigned int thickness_t;
typedef double angle_t;

enum Position_T{
    Default_Pos=0,
    Corner,
    Edge,
    Local_Min,
    Local_Max,
    Global_Min,
    Global_Max,
    Root
};

enum Similarity_T{
    Strong=0,
    Medium,
    Weak,
    Different,
    Relative,
    Linear
};

class Position2D{
    private:
    position_t x_=0, y_=0;
    Position_T type_=Position_T::Default_Pos;

    public:
    Position2D()=default;
    Position2D(position_t x, position_t y,const Position_T& position_type =Position_T::Default_Pos): 
        x_(x), y_(y), type_(position_type) {}
    explicit Position2D(const Position_T& position_type): 
        type_(position_type) {}

    void set_x(position_t x);
    void add_x(position_t x);
    void mult_x(double k);
    void set_y(position_t y);
    void add_y(position_t y);
    void mult_y(double k);
    position_t x() const;
    position_t y() const;
    static double length(const Position2D& position1, const Position2D& postion2=ORIGIN);

    friend std::ostream& operator<<(std::ostream& out, const Position2D& position);
    friend std::istream& operator>>(std::istream& out, Position2D& position);
    position_t operator[](unsigned i);
    Position2D operator+(const Position2D& position) const;
    Position2D operator-(const Position2D& position) const;
    Position2D operator*(double coef) const;
    Position2D operator/(double coef) const;
    Position2D& operator+=(const Position2D& position);
    Position2D& operator-=(const Position2D& position);
    Position2D& operator*=(double coef);
    Position2D& operator/=(double coef);
    Position2D& operator=(const Position2D& position);
    bool operator==(const Position2D& position) const;

    Similarity_T compare(const Position2D& position) const;

    private:
    void read(std::istream& in);
};
