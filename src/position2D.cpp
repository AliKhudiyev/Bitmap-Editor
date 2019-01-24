#include<iostream>
#include"position2D.hpp"

void Position2D::set_x(position_t x){
    x_=x;
}

void Position2D::add_x(position_t x){
    x_+=x;
}

void Position2D::mult_x(double k){
    x_=(double)x_*k;
}

void Position2D::set_y(position_t y){
    y_=y;
}

void Position2D::add_y(position_t y){
    y_+=y;
}

void Position2D::mult_y(double k){
    y_=(double)y_*k;
}

position_t Position2D::x() const{
    return x_;
}

position_t Position2D::y() const{
    return y_;
}

std::ostream& operator<<(std::ostream& out, const Position2D& position){
    out<<"("<<position.x()<<", "<<position.y()<<")";
    return out;
}

std::istream& operator>>(std::istream& in, Position2D& position){
    position.read(in);
    return in;
}

position_t Position2D::operator[](unsigned i){
    if(i>1){
        throw Exception("Attempt to pull out the third position in 2D.", Logic);
    }
    if(i==0) return x_;
    return y_;
}

Position2D Position2D::operator+(const Position2D& position) const{
    Position2D Position;

    Position.x_=x_+position.x_;
    Position.y_=x_+position.y_;
    Position.type_=Default_Pos;

    return Position;
}

Position2D Position2D::operator-(const Position2D& position) const{
    Position2D Position;

    Position.x_=x_-position.x_;
    Position.y_=x_-position.y_;
    Position.type_=Default_Pos;

    return Position;
}

Position2D Position2D::operator*(double coef) const{
    Position2D Position;

    Position.x_=(double)x_*coef;
    Position.y_=(double)y_*coef;
    Position.type_=Default_Pos;

    return Position;
}

Position2D Position2D::operator/(double coef) const{
    if(coef==0){
        throw Exception("Dividing by 0.", Logic);
    }

    Position2D Position;

    Position.x_=(double)x_/coef;
    Position.y_=(double)y_/coef;
    Position.type_=Default_Pos;

    return Position;
}

Position2D& Position2D::operator+=(const Position2D& position){
    x_+=position.x_;
    y_+=position.y_;
    return *this;
}

Position2D& Position2D::operator-=(const Position2D& position){
    x_-=position.x_;
    y_-=position.y_;
    return *this;
}

Position2D& Position2D::operator*=(double coef){
    x_=(double)x_*coef;
    y_=(double)y_*coef;
    return *this;
}

Position2D& Position2D::operator/=(double coef){
    x_=(double)x_/coef;
    y_=(double)y_/coef;
    return *this;
}

Position2D& Position2D::operator=(const Position2D& position){
    x_=position.x_;
    y_=position.y_;
    type_=position.type_;
    return *this;
}

bool Position2D::operator==(const Position2D& position) const{
    if(x_==position.x_ && y_==position.y_) return true;
    return false;
}

Similarity_T Position2D::compare(const Position2D& position) const{
    if(*this==position) return Strong;
    if((x_==position.x_ && y_!=position.y_) || 
       (y_==position.y_ && x_!=position.x_)) return Medium;
    if((x_-position.x_==y_-position.y_) || 
       (x_-position.x_==position.y_-y_)) return Linear;
    return Different;
}

void Position2D::read(std::istream& in){
    in>>x_>>y_;
}
