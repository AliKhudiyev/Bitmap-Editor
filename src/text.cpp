#include"text.hpp"

/*   Digit shapes initialzing   */
// 6x11 (width x height)

const Shape __0(std::vector<Pixel>{
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9))
});

const Shape __1(std::vector<Pixel>{
    Pixel(Position2D(0, 5)),
    Pixel(Position2D(5, 0)),
    Pixel(Position2D(5, 10))
});

const Shape __2(std::vector<Pixel>{
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(5, 10))
});

const Shape __3(std::vector<Pixel>{
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(5, 4)),
    Pixel(Position2D(4, 4+1)),
    Pixel(Position2D(1, 4+1)),
    Pixel(Position2D(4, 4+1)),
    Pixel(Position2D(5, 4+2)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9)),
});

const Shape __4(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 5)),
    Pixel(Position2D(5, 5)),
    Pixel(Position2D(5, 0)),
    Pixel(Position2D(5, 10)),
});

const Shape __5(std::vector<Pixel>{
    Pixel(Position2D(5, 0)),
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 5)),
    Pixel(Position2D(1, 4)),
    Pixel(Position2D(4, 4)),
    Pixel(Position2D(5, 5)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9))
});

const Shape __6(std::vector<Pixel>{
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(5, 6)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(1, 5))
});

const Shape __7(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(5, 0)),
    Pixel(Position2D(1, 10))
});

const Shape __8(std::vector<Pixel>{
    Pixel(Position2D(1, 1)),
    Pixel(Position2D(2, 0)),
    Pixel(Position2D(3, 0)),
    Pixel(Position2D(4, 1)),
    Pixel(Position2D(4, 3)),
    Pixel(Position2D(3, 4)),
    Pixel(Position2D(2, 4)),
    Pixel(Position2D(1, 3)),
    Pixel(Position2D(1, 1)),

    Pixel(Position2D(1, 3)),
    Pixel(Position2D(2, 4)),

    Pixel(Position2D(1, 4)),
    Pixel(Position2D(0, 5)),
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(5, 5)),
    Pixel(Position2D(4, 4)),
    Pixel(Position2D(2, 4))
});

const Shape __9(std::vector<Pixel>{
    Pixel(Position2D(5, 4)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(1, 5)),
    Pixel(Position2D(0, 4)),
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9))
});

/*   Letter shapes initialzing   */

const Shape __a(std::vector<Pixel>{
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(5, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(0, 5)),
    Pixel(Position2D(1, 4)),
    Pixel(Position2D(5, 4))
});

const Shape __b(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(5, 6)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(0, 5))
});

const Shape __c(std::vector<Pixel>{
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(5, 9))
});

const Shape __d(std::vector<Pixel>{
    Pixel(Position2D(5, 5)),
    Pixel(Position2D(1, 5)),
    Pixel(Position2D(0, 6)),
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(5, 10)),
    Pixel(Position2D(5, 0))
});

const Shape __e(std::vector<Pixel>{
    Pixel(Position2D(0, 5)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(5, 4)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(5, 9))
});

const Shape __f(std::vector<Pixel>{
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(3, 0)),
    Pixel(Position2D(2, 1)),
    Pixel(Position2D(2, 5)),
    Pixel(Position2D(0, 5)),
    Pixel(Position2D(5, 5)),
    Pixel(Position2D(2, 5)),
    Pixel(Position2D(2, 10))
});

const Shape __g(std::vector<Pixel>{
    Pixel(Position2D(5, 4)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(1, 5)),
    Pixel(Position2D(0, 4)),
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9))
});

const Shape __h(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(0, 5)),
    Pixel(Position2D(1, 6)),
    Pixel(Position2D(4, 6)),
    Pixel(Position2D(5, 7)),
    Pixel(Position2D(5, 10))
});

const Shape __i(std::vector<Pixel>{     // needs to be fixed
    Pixel(Position2D(2, 0)),
    Pixel(Position2D(2, 6)),
    Pixel(Position2D(2, 10))
});

const Shape __j(std::vector<Pixel>{     // needs to be fixed
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 6)),
    Pixel(Position2D(4, 6)),
    Pixel(Position2D(4, 9)),
    Pixel(Position2D(3, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9))
});

const Shape __k(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(0, 6)),
    Pixel(Position2D(4, 2)),
    Pixel(Position2D(0, 6)),
    Pixel(Position2D(5, 10))
});

const Shape __l(std::vector<Pixel>{
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(2, 0)),
    Pixel(Position2D(2, 10)),
    Pixel(Position2D(3, 10))
});

const Shape __m(std::vector<Pixel>{
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 2)),
    Pixel(Position2D(1, 1)),
    Pixel(Position2D(2, 1)),
    Pixel(Position2D(3, 2)),
    Pixel(Position2D(3, 10)),
    Pixel(Position2D(3, 2)),
    Pixel(Position2D(4, 1)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(6, 2)),
    Pixel(Position2D(6, 10))
});

const Shape __n(std::vector<Pixel>{
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 2)),
    Pixel(Position2D(1, 1)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(5, 10))
});

const Shape __o(std::vector<Pixel>{
    Pixel(Position2D(1, 5)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(5, 6)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(0, 6)),
    Pixel(Position2D(1, 5))
});

const Shape __p(std::vector<Pixel>{
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(5, 4)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(0, 5))
});

const Shape __q(std::vector<Pixel>{
    Pixel(Position2D(5, 10)),
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(0, 4)),
    Pixel(Position2D(1, 5)),
    Pixel(Position2D(5, 5))
});

const Shape __r(std::vector<Pixel>{
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 2)),
    Pixel(Position2D(1, 1)),
    Pixel(Position2D(3, 1)),
    Pixel(Position2D(4, 2))
});

const Shape __s(std::vector<Pixel>{
    Pixel(Position2D(5, 1)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(1, 0)),
    Pixel(Position2D(0, 1)),
    Pixel(Position2D(0, 4)),
    Pixel(Position2D(1, 5)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(5, 6)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 9))
});

const Shape __t(std::vector<Pixel>{
    Pixel(Position2D(2, 0)),
    Pixel(Position2D(2, 5)),
    Pixel(Position2D(1, 5)),
    Pixel(Position2D(4, 5)),
    Pixel(Position2D(2, 5)),
    Pixel(Position2D(2, 9)),
    Pixel(Position2D(3, 10)),
    Pixel(Position2D(4, 10))
});

const Shape __u(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(0, 9)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(4, 10)),
    Pixel(Position2D(5, 9)),
    Pixel(Position2D(5, 0))
});

const Shape __v(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(3, 10)),
    Pixel(Position2D(6, 0))
});

const Shape __w(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(2, 10)),
    Pixel(Position2D(4, 0)),
    Pixel(Position2D(6, 10)),
    Pixel(Position2D(8, 0))
});

const Shape __x(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(5, 10)),
    Pixel(Position2D(2, 5)),
    Pixel(Position2D(5, 0)),
    Pixel(Position2D(0, 10))
});

const Shape __y(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(3, 5)),
    Pixel(Position2D(5, 0)),
    Pixel(Position2D(1, 10)),
    Pixel(Position2D(0, 10))
});

const Shape __z(std::vector<Pixel>{
    Pixel(Position2D(0, 0)),
    Pixel(Position2D(5, 0)),
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(5, 10))
});

/*   Text   */

void TEXT::magnify(double f){
    for(unsigned i=0;i<26;++i){
        for(unsigned n=0;n<Char_[i].n_side();++n){
            Char_[i].get_pixel(n).get_position().mult_x(f);
            Char_[i].get_pixel(n).get_position().mult_y(f);
        }
    }
}

void TEXT::magnify(unsigned index, double f){
    for(unsigned n=0;n<Char_[index].n_side();++n){
        Char_[index].get_pixel(n).get_position().mult_x(f);
        Char_[index].get_pixel(n).get_position().mult_x(f);
    }
}

void TEXT::rotate(angle_t angle){
    ;
}

void TEXT::rotate(unsigned index, angle_t angle){
    ;
}

void TEXT::init(unsigned font_type){
    if(font_type){}

    Char_[15]=__0;
    Char_[16]=__1;
    Char_[17]=__2;
    Char_[18]=__3;
    Char_[19]=__4;
    Char_[20]=__5;
    Char_[21]=__6;
    Char_[22]=__7;
    Char_[23]=__8;
    Char_[24]=__9;

    Char_[64]=__a;
    Char_[65]=__b;
    Char_[66]=__c;
    Char_[67]=__d;
    Char_[68]=__e;
    Char_[69]=__f;
    Char_[70]=__g;
    Char_[71]=__h;
    Char_[72]=__i;
    Char_[73]=__j;
    Char_[74]=__k;
    Char_[75]=__l;
    Char_[76]=__m;
    Char_[77]=__n;
    Char_[78]=__o;
    Char_[79]=__p;
    Char_[80]=__q;
    Char_[81]=__r;
    Char_[82]=__s;
    Char_[83]=__t;
    Char_[84]=__u;
    Char_[85]=__v;
    Char_[86]=__w;
    Char_[87]=__x;
    Char_[88]=__y;
    Char_[89]=__z;
}

TEXT __Font_Standard;
