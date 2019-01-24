#include"shape.hpp"

/*  Shape  */

unsigned Shape::n_side() const{
    return n_side_;
}

std::string Shape::type() const{
    std::string type="Shape";
    return type;
}

unsigned Shape::total_inside_angle() const{
    unsigned tia=0;
    return tia;
}

double Shape::area() const{
    double area=0;
    return area;
}

double Shape::perimeter() const{
    double perimeter=0;
    return perimeter;
}

void Shape::rotate(angle_t angle){
    ;
}

void Shape::move(position_t dx, position_t dy){
    std::vector<Pixel>::size_type i;
    for(i=0;i<pixel_.size();++i){
        pixel_[i].get_position().add_x(dx);
        pixel_[i].get_position().add_y(dy);
    }
}

void Shape::set_width(unsigned width){
    width_=width;
}

void Shape::set_height(unsigned height){
    height_=height;
}

unsigned Shape::width() const{
    return width_;
}

unsigned Shape::height() const{
    return height_;
}

void Shape::add_xy(position_t x, position_t y){
    for(auto& pixel: pixel_){
        pixel.get_position().add_x(x);
        pixel.get_position().add_y(y);
    }
}

Pixel& Shape::get_pixel(unsigned i){
    return pixel_[i];
}

const Pixel& Shape::operator[](unsigned i) const{
    return pixel_[i];
}

bool Shape::operator==(const Shape& shape) const{
    if(pixel_.size()!=shape.pixel_.size()) return false;
    std::vector<Pixel>::size_type i;
    for(i=0;i<pixel_.size();++i){
        if(pixel_[i]!=shape.pixel_[i]) return false;
    }
    return true;
}

bool Shape::operator!=(const Shape& shape) const{
    return !(*this==shape);
}

Shape& Shape::operator=(const Shape& shape){
    pixel_=shape.pixel_;
    type_=shape.type_;
    n_side_=shape.n_side_;
    
    update();
    return *this;
}

Similarity_T Shape::compare(const Shape& shape) const{
    std::vector<Pixel>::size_type i;
    unsigned cmp=0;
    for(i=0;i<pixel_.size();++i){
        if(pixel_[i].compare(shape.pixel_[i])==Medium && cmp<1){
            cmp=1;
        } else if(pixel_[i].compare(shape.pixel_[i])==Weak){
            cmp=2;
            break;
        }
    }
    if(!cmp) return Strong;
    if(cmp==1) return Medium;
    if(cmp==2) return Weak;
    return Different;
}

void Shape::update(){
    position_t min_x=pixel_[0].get_position().x();
    position_t min_y=pixel_[0].get_position().y();
    position_t max_x=0, max_y=0;

    std::vector<Pixel>::size_type i;
    for(i=0;i<pixel_.size();++i){
        if(pixel_[i].get_position().x()<min_x){
            min_x=pixel_[i].get_position().x();
        }
        if(pixel_[i].get_position().x()>max_x){
            max_x=pixel_[i].get_position().x();
        }
        if(pixel_[i].get_position().y()<min_y){
            min_y=pixel_[i].get_position().y();
        }
        if(pixel_[i].get_position().y()>max_y){
            max_y=pixel_[i].get_position().y();
        }
    }

    width_=max_x-min_x;
    height_=max_y-min_y;
}

/*  Triangle  */

unsigned Triangle::n_side() const{
    return n_side_;
}

std::string Triangle::type() const{
    std::string type="Shape";
    return type;
}

unsigned Triangle::total_inside_angle() const{
    unsigned tia=0;
    return tia;
}

double Triangle::area() const{
    double area=0;
    return area;
}

double Triangle::perimeter() const{
    double perimeter=0;
    return perimeter;
}

void Triangle::rotate(angle_t angle){
    ;
}

void Triangle::move(position_t dx, position_t dy){
    ;
}

const Pixel& Triangle::operator[](unsigned i) const{
    return pixel_[i];
}

bool Triangle::operator==(const Shape& shape) const{
    return true;
}

bool Triangle::operator!=(const Shape& shape) const{
    return true;
}

Similarity_T Triangle::compare(const Shape& shape) const{
    return Different;
}

/*   Rectangle   */

unsigned Rectangle::n_side() const{
    return n_side_;
}

std::string Rectangle::type() const{
    std::string type="Shape";
    return type;
}

unsigned Rectangle::total_inside_angle() const{
    unsigned tia=0;
    return tia;
}

double Rectangle::area() const{
    double area=0;
    return area;
}

double Rectangle::perimeter() const{
    double perimeter=0;
    return perimeter;
}

void Rectangle::rotate(angle_t angle){
    ;
}

void Rectangle::move(position_t dx, position_t dy){
    ;
}

const Pixel& Rectangle::operator[](unsigned i) const{
    return pixel_[i];
}

bool Rectangle::operator==(const Shape& shape) const{
    return true;
}

bool Rectangle::operator!=(const Shape& shape) const{
    return true;
}

Similarity_T Rectangle::compare(const Shape& shape) const{
    return Different;
}

/*   Circle   */

unsigned Circle::n_side() const{
    return n_side_;
}

std::string Circle::type() const{
    std::string type="Shape";
    return type;
}

unsigned Circle::total_inside_angle() const{
    unsigned tia=0;
    return tia;
}

double Circle::area() const{
    double area=0;
    return area;
}

double Circle::perimeter() const{
    double perimeter=0;
    return perimeter;
}

void Circle::rotate(angle_t angle){
    ;
}

void Circle::move(position_t dx, position_t dy){
    ;
}

const Pixel& Circle::operator[](unsigned i) const{
    return pixel_[i];
}

bool Circle::operator==(const Shape& shape) const{
    return true;
}

bool Circle::operator!=(const Shape& shape) const{
    return true;
}

Similarity_T Circle::compare(const Shape& shape) const{
    return Different;
}
