#include<iostream>
#include"bmp_info.hpp"

std::vector<unsigned char> byte_vector(unsigned value, unsigned n_byte){
    std::vector<unsigned char> byte(n_byte);
    for(unsigned i=0;i<n_byte;++i){
        byte[i]=value%256;
        value=(value-byte[i])/256;
    }
    return byte;
}

std::vector<unsigned char> BMP_Info::byte_vector(unsigned char type, unsigned n_byte) const{
    unsigned value;
    switch(type){
        case FILE_SIZE:
            value=file_size_;
            break;
        case WIDTH:
            value=width_;
            break;
        case HEIGHT:
            value=height_;
            break;
        case IMAGE_SIZE:
            value=image_size_;
            break;
        case HEADER_SIZE:
            value=header_size_;
            break;
        case OFFSET_SIZE:
            value=offset_size_;
            break;
        case BITS_PER_PIXEL:
            value=bits_per_pixel_;
            break;
        default: break;
    }
    return ::byte_vector(value, n_byte);
}

void BMP_Info::clear(){
    signature_=0;
    file_size_=0;
    offset_size_=0;
    header_size_=0;
    width_=0;
    height_=0;
    image_size_=0;
}

void BMP_Info::Info() const{
    std::cout<<"File size: "<<file_size_<<'\n';
    std::cout<<"Offset size: "<<offset_size_<<'\n';
    std::cout<<"Header size: "<<header_size_<<'\n';
    std::cout<<"Width size: "<<width_<<'\n';
    std::cout<<"Height size: "<<height_<<'\n';
    std::cout<<"Bits per pixel: "<<bits_per_pixel_<<'\n';
    std::cout<<"Image size: "<<image_size_<<'\n';
}
