#include<fstream>
#include"bmp.hpp"
#include"text.hpp"
#include"exception.hpp"
#include<cmath>
#include<iostream>

// extern double calculate(const std::string& function, double x);

Color BMP::def_color=COLOR::Black;
thickness_t BMP::def_thick=1;
bool BMP::fill=false;

void BMP::set_color(const Color& color){
    def_color=color;
}

void BMP::set_thickness(const thickness_t thickness){
    def_thick=thickness;
}

void BMP::set_fill(bool fill){
    ;
}

const BMP_Info& BMP::info() const{
    return info_;
}

const Color& BMP::get_color() const{
    return def_color;
}

thickness_t BMP::get_thickness() const{
    return def_thick;
}

BMP BMP::blank(unsigned width, unsigned height, const Color& color){
    BMP image;

    image.header_.resize(54);
    image.header_[0]=0x42;
    image.header_[1]=0x4D;
    for(unsigned i=2;i<54;++i) image.header_[i]=0;

    image.table_.color_.resize(width*height);
    for(std::vector<Color>::size_type i=0;i<width*height;++i){
        image.table_.color_[i]=color;
    }

    image.info_.width_=width;
    image.info_.height_=0xffffffff-height+1;
    image.info_.header_size_=40;
    image.info_.bits_per_pixel_=32;
    image.info_.offset_size_=54;
    image.info_.image_size_=width*height*4;
    image.info_.file_size_=width*height*4+54;
    image.update();

    return image;
}

BMP& BMP::draw_point(const Position2D& position, const Color& color, const thickness_t thickness){
    unsigned width=thickness-1;
    draw_line(position, Position2D(position.x()+width, position.y()), color, thickness);
    return *this;
}

BMP& BMP::draw_line(const Position2D& position1, const Position2D& position2, const Color& color, const thickness_t thickness){
    draw(position1, position2, color, thickness);
    return *this;
}

BMP& BMP::draw_line(const Position2D position[2], const Color& color, const thickness_t thickness){
    draw(position[0], position[1], color, thickness);
    return *this;
}

BMP& BMP::draw_triangle(const Position2D& position1, const Position2D& position2, const Position2D& position3, const Color& color, const thickness_t thickness){
    draw(position1, position2, color, thickness);
    draw(position2, position3, color, thickness);
    draw(position3, position1, color, thickness);
    return *this;
}

BMP& BMP::draw_triangle(const Position2D position[3], const Color& color, const thickness_t thickness){
    draw(position[0], position[1], color, thickness);
    draw(position[1], position[2], color, thickness);
    draw(position[2], position[0], color, thickness);
    return *this;
}

BMP& BMP::draw_triangle(const Triangle& triangle, const Color& color, const thickness_t thickness){
    draw(triangle[0].position(), triangle[1].position(), color, thickness);
    draw(triangle[1].position(), triangle[2].position(), color, thickness);
    draw(triangle[2].position(), triangle[0].position(), color, thickness);
    return *this;
}

BMP& BMP::draw_rectangle(const Position2D position[4], const Color& color, const thickness_t thickness){
    draw(position[0], position[1], color, thickness);
    draw(position[1], position[2], color, thickness);
    draw(position[2], position[3], color, thickness);
    draw(position[3], position[0], color, thickness);
    return *this;
}

BMP& BMP::draw_rectangle(const Rectangle& rectangle, const Color& color, const thickness_t thickness){
    draw(rectangle[0].position(), rectangle[1].position(), color, thickness);
    draw(rectangle[1].position(), rectangle[2].position(), color, thickness);
    draw(rectangle[2].position(), rectangle[3].position(), color, thickness);
    draw(rectangle[3].position(), rectangle[0].position(), color, thickness);
    return *this;
}

BMP& BMP::draw_circle(const Position2D& position1, const Position2D& position2, const Color& color, const thickness_t thickness){
    // Position2D center=position1-position2;
    // unsigned radius=Position2D::length(position1, position2);
    ;
    return *this;
}

BMP& BMP::draw_circle(const Position2D position[2], const Color& color, const thickness_t thickness){
    // draw_circle(position[0], position[1], color, thickness);
    return *this;
}

BMP& BMP::draw_circle(const Circle& circle, const Color& color, const thickness_t thickness){
    ;
    return *this;
}

BMP& BMP::draw_circle(const Position2D& position, unsigned radius, const Color& color, const thickness_t thickness){
    ;
    return *this;
}
    
BMP& BMP::draw_shape(const Shape& shape, const Color& color, const thickness_t thickness){
    std::vector<Position2D>::size_type i;
    for(i=0;i<shape.n_side();++i){
        // std::cout<<"Positions:\t"<<shape[i].position()<<" - "<<shape[i+1].position()<<'\n';
        draw(shape[i].position(), shape[i+1].position(), color, thickness);
    }
    return *this;
}

BMP& BMP::draw(const std::vector<Position2D>& positions, const Color& color, const thickness_t thickness){
    std::vector<Position2D>::size_type i;
    for(i=0;i<positions.size()-1;++i){
        std::cout<<"Positions:\t"<<positions[i]<<" - "<<positions[i+1]<<'\n';
        draw(positions[i], positions[i+1], color, thickness);
    }
    return *this;
}

BMP& BMP::draw_text(const std::string& text, const Position2D& position, double magnify, const Color& color, const thickness_t thickness){
    Shape tmp;
    position_t x=position.x(), y=position.y();
    __Font_Standard.magnify(magnify);
    
    for(unsigned i=0;i<text.size();++i){
        // std::cout<<"printing.. "<<text[i]<<'\n';
        // std::cout<<"ascii value of "<<(int)text[i]<<'\n';

        if(text[i]==*(char*)&" "){
            x+=8;
            continue;
        }
        tmp=__Font_Standard.Char_[(int)text[i]-33];
        tmp.add_xy(x, y);
        x+=tmp.width()+6;
        draw_shape(tmp, color, thickness);
    }
    return *this;
}

BMP& BMP::draw_function(const std::string& function, double beg_x, double end_x, const Color& color, const thickness_t thickness){
    position_t y1=0, y2=0;
    for(;beg_x<end_x-1;++beg_x){
        // y1=calculate(function, beg_x);
        // y2=calculate(function, beg_x+1);
        draw_line(Position2D(beg_x, y1), Position2D(beg_x+1, y2), color, thickness);
    }
    return *this;
}

BMP& BMP::detect_borders(){
    ;
    return *this;
}

BMP& BMP::scale(double on_axis){
    return scale(on_axis, on_axis);
}

BMP& BMP::scale(double on_x, double on_y){
    unsigned width=(double)info_.width_*on_x;
    unsigned height=(double)(0xffffffff-info_.height_)*on_y;
    return h_crop(height).v_crop(width);
}

BMP& BMP::scale(unsigned char axis, double factor, unsigned beg, unsigned db){
    switch(axis){
        case WIDTH:
            v_scale(factor, beg, db);
            break;
        case HEIGHT:
            h_scale(factor, beg, db);
            break;
        default: break;
    }
    return *this;
}

BMP& BMP::rotate(angle_t angle){
    ;
    return *this;
}

BMP& BMP::crop(unsigned width, unsigned height){
    if(width==0) width=info_.width_;
    if(height==0) height=0xffffffff-info_.height_+1;
    return v_crop(width).h_crop(height);
}

BMP BMP::extract_vertical(unsigned width) const{
    BMP image=*this;
    return image.v_crop(width);
}

BMP BMP::extract_horizontal(unsigned height) const{
    BMP image=*this;
    return image.h_crop(height);
}

void BMP::save() const{
    write(name_);
}

void BMP::save(const std::string& name) const{
    write(name);
}

void BMP::load(const std::string& file_name){
    read(file_name);
}

void BMP::load(const BMP& image){
    header_=image.header_;
    table_=image.table_;
    info_=image.info_;
}

void BMP::remove(){
    header_.clear();
    table_.clear();
    info_.clear();
}

BMP BMP::operator=(const BMP& image){
    load(image);
    return *this;
}

            /* === PRIVATE MATTER === */

void BMP::read(const std::string& file_name){
    std::ifstream image(file_name, std::ios::in | std::ios::binary);

    if(!image){
        throw Exception("File couldn't be opened.", Error::Fatal);
    }

    image.read((char*)&info_.signature_, 2);
    image.read((char*)&info_.file_size_, 4);
    
    image.seekg(4, image.cur);
    image.read((char*)&info_.offset_size_, 4);
    image.read((char*)&info_.header_size_, 4);
    image.read((char*)&info_.width_, 4);

    image.seekg(6, image.cur);
    image.read((char*)&info_.bits_per_pixel_, 2);

    unsigned Bpp=info_.bits_per_pixel_/8;
    info_.image_size_=info_.file_size_-info_.offset_size_;
    info_.height_=0xffffffff-info_.image_size_/info_.width_/Bpp+1;

    try{
        header_.resize(info_.offset_size_);
        table_.color_.resize(info_.image_size_);
    } catch(const std::exception& e){
        throw e;
    }

    image.seekg(0, image.beg);
    image.read((char*)&header_[0], info_.offset_size_);
    image.read((char*)&table_.color_[0], info_.image_size_);
    table_.n_padding_=(4-((info_.width_*Bpp)%4))%4;

    update();

    image.close();
}

void BMP::write(const std::string& file_name) const{
    std::ofstream image(file_name, std::ios::out | std::ios::binary);

    image.write((char*)&header_[0], info_.offset_size_);
    for(unsigned i=0;i<info_.image_size_/4;i+=info_.width_){
        image.write((char*)&table_.color_[i], info_.width_*4);
        if(table_.n_padding_) image.write(&null, table_.n_padding_);
    }

    image.close();
}

void BMP::update(){
    std::vector<byte> u_file_size=info_.byte_vector(FILE_SIZE);
    std::vector<byte> u_width=info_.byte_vector(WIDTH);
    std::vector<byte> u_height=info_.byte_vector(HEIGHT);
    std::vector<byte> u_header_size=info_.byte_vector(HEADER_SIZE);
    std::vector<byte> u_offset_size=info_.byte_vector(OFFSET_SIZE);
    std::vector<byte> u_bits_per_pixel=info_.byte_vector(BITS_PER_PIXEL);

    for(unsigned i=0;i<4;++i){
        header_[2+i]=u_file_size[i];
        header_[10+i]=u_offset_size[i];
        header_[14+i]=u_header_size[i];
        header_[18+i]=u_width[i];
        header_[22+i]=u_height[i];
        header_[28+i]=u_bits_per_pixel[i];
    }
    table_.n_padding_=(4-((info_.width_*info_.bits_per_pixel_/4)%4))%4;
}

bool BMP::draw(const Position2D position[2], const Color& color, const thickness_t thickness){
    int dy=position[1].y()-position[0].y();
    unsigned dx=position[1].x()-position[0].x();
    double k=0;
    if(dx) k=(double)dy/(double)dx;
    bool pass=dx? false : true;
    // std::cout<<"dx : "<<dx<<", dy : "<<dy<<'\n';

    unsigned width=info_.width_;
    // unsigned height=0xffffffff-info_.height_;
    auto cit=table_.color_.begin()+position[0].y()*width+position[0].x();
    auto c_cit=cit;
    position_t y_shift, delta=dx? dx : abs(dy);

    // std::cout<<"\n\n\t === Draw segment activated. ===\n\n";
    // std::cout<<"Default color : Black (...)\n";
    // std::cout<<"Thickness : "<<thickness<<'\n';
    // std::cout<<"Original image width : "<<width<<'\n';
    // std::cout<<"Delta : "<<delta<<'\n';
    // std::cout<<"Positions : ("<<position[0].x()<<", "<<position[0].y()<<"), (";
    // std::cout<<position[1].x()<<", "<<position[1].y()<<")\n";
    // std::cout<<"k : "<<k<<'\n';
    // std::cout<<"pass : "<<pass<<'\n';
    // std::cout<<"abs(k) : "<<(position_t)abs(k)<<'\n';
    // std::cout<<std::endl;

    for(position_t x=0;x<=delta;++x){
        y_shift=floor((double)x*k);
        if(pass) y_shift=1;
        if(x && abs(k>0?ceil(k) : floor(k))>1){
            for(position_t ry=1;ry<(position_t)(abs(k>0?ceil(k) : floor(k)));++ry){
                if(k>0) *(cit+ry*width)=color;
                else *(cit-ry*width)=color;
            }
        }
        if(y_shift>0 && k) cit=c_cit+abs(y_shift)*width;
        else if(y_shift>0 && x) cit+=width;
        else if(y_shift<0 && k) cit=c_cit-abs(y_shift)*width;

        if(!pass && y_shift && x) cit+=x;
        else if(!pass && x) ++cit;
        *cit=color;
    }
    if(thickness-1){
        Position2D post[2]{position[0], position[1]};
        if(dx){
            post[0].set_y(post[0].y()+1);
            post[1].set_y(post[1].y()+1);
        } else{
            post[0].set_x(post[0].x()+1);
            post[1].set_x(post[1].x()+1);
        }
        draw(post, color, thickness-1);
    }

    return true;
}

bool BMP::draw(const Position2D& position1, const Position2D& position2, const Color& color, const thickness_t thickness){
    Position2D position[2];
    if(position1.x()<position2.x()){
        position[0]=position1;
        position[1]=position2;
    } else if(position1.x()>position2.x()){
        position[0]=position2;
        position[1]=position1;
    } else{
        if(position1.y()<position2.y()){
            position[0]=position1;
            position[1]=position2;
        } else{
            position[0]=position2;
            position[1]=position1;
        }
    }
    draw(position, color, thickness);
    return true;
}

BMP& BMP::v_scale(double factor, unsigned width, unsigned dw){
    ;
    return *this;
}

BMP& BMP::h_scale(double factor, unsigned height, unsigned dh){
    unsigned height1=height;
    unsigned height2=height+dh;
    unsigned n_height=height2-height1;
    unsigned n_width=(double)info_.width_/factor;
    std::vector<Color> color(n_width*n_height);

    BMP image=*this;;
    image.v_crop(n_width);
    
    {
        auto it=image.table_.color_.begin()+height1*n_width;
        auto cit=color.begin();
        for(auto c_it=it;it<c_it+n_height*n_width;++it, ++cit){
            *cit=*it;
        }
    }
    
    {
        auto it=color.begin();
        auto c_it=it;
        auto cit=table_.color_.begin()+height1*info_.width_;
        double cfactor=factor;
        unsigned owidth=0;
        for(unsigned h=height1;h<height2;++h){
            cfactor=factor;
            owidth=0;
            for(unsigned w=0;w<n_width;++w, ++it){
                for(unsigned i=0;i<floor(cfactor);++i, ++cit, ++owidth){
                    *cit=*it;
                }
                if(cfactor-floor(cfactor)<0.000001){
                    cfactor=factor;
                    continue;
                }
                ++owidth;
                *(cit++)=(*it)*(cfactor-floor(cfactor))+(*(it+1))*(ceil(cfactor)-cfactor);
                cfactor=factor-ceil(cfactor)+cfactor;
                if(owidth>=info_.width_){
                    it=c_it+n_width;
                    c_it+=n_width;
                    break;
                }
            }
        }
    }

    return *this;
}

BMP& BMP::v_crop(unsigned width){
    double crop_size=(double)(info_.width_-width)/2;
    unsigned height=0xffffffff-info_.height_;
    std::cout<<"v crop size : "<<crop_size<<'\n';
    info_.width_=width;
    info_.image_size_=width*(height+1)*4;
    info_.file_size_=info_.image_size_+info_.offset_size_;
    update();

    auto it=table_.color_.begin()+floor(crop_size);
    std::vector<Color> color(info_.image_size_/4);
    auto cit=color.begin();

    for(auto c_it=it;it<c_it+width;++it, ++cit) *cit=*it;
    for(unsigned h=1;h<height;++h){
        it+=(floor(crop_size)+ceil(crop_size));
        for(auto c_it=it;it<c_it+width;++it, ++cit) *cit=*it;
    }
    // for(auto c_it=it;it<c_it+width;++it, ++cit) *cit=*it;
    table_.color_=color;    

    return *this;
}

BMP& BMP::h_crop(unsigned height){
    double crop_size=(double)(0xffffffff-info_.height_+1-height)/2.0;
    std::cout<<"h crop size : "<<crop_size<<'\n';

    info_.height_=0xffffffff-height+1;
    info_.image_size_=info_.width_*height*4;
    info_.file_size_=info_.image_size_+info_.offset_size_;
    update();

    auto it=table_.color_.begin();
    table_.color_.erase(it, it+floor(crop_size)*info_.width_);
    it=table_.color_.end();
    table_.color_.erase(it-ceil(crop_size)*info_.width_, it);

    return *this;
}
