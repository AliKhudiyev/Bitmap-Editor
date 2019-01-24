#include"shape.hpp"
#include"pixel.hpp"

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
    Pixel(Position2D(0, 10)),
    Pixel(Position2D(5, 0)),
    Pixel(Position2D(5, 20))
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
