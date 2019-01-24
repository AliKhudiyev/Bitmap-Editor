#include"pixel.hpp"

Color& Pixel::get_color(){
    return color_;
}

Position2D& Pixel::get_position(){
    return position_;
}

const Color& Pixel::color() const{
    return color_;
}

const Position2D& Pixel::position() const{
    return position_;
}

bool Pixel::operator==(const Pixel& pixel) const{
    if(color_==pixel.color_ && position_==pixel.position_) return true;
    return false;
}

bool Pixel::operator!=(const Pixel& pixel) const{
    return !(*this==pixel);
}

Similarity_T Pixel::compare(const Pixel& pixel) const{
    if(color_==pixel.color_ && position_==pixel.position_)
        return Strong;
    if(position_==pixel.position_)
        return Medium;
    if(color_==pixel.color_ && position_.compare(pixel.position_)==Weak)
        return Weak;
    return Different;
}
