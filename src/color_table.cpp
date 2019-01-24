#include"color_table.hpp"

void Color_Table::w_init(unsigned width, const std::vector<Color>& color){
    ;
}

void Color_Table::h_init(unsigned height, const std::vector<Color>& color){
    ;
}

void Color_Table::init(unsigned width, unsigned height, const std::vector<Color>& color){
    ;
}

void Color_Table::add_color(const Color& color, const Position2D& position){
    ;
}

void Color_Table::modify_color(const Color& color, const Position2D& position){
    ;
}

void Color_Table::remove_color(const Position2D& position){
    ;
}

void Color_Table::clear(){
    width=height=0;
    n_padding_=0;
    color_.clear();
}
