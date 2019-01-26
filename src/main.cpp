#include<iostream>
#include"chdrs.hpp"
#include"bmp.hpp"
#include"text.hpp"

#define USAGE_INFO_ERROR Exception("\
Appropriate usage : [options] [--] [parameters] \
Options : \n\
-s [scaling factor] : scale by [scaling factor]\n\
-r [angle]          : rotate by [angle]\n\
\
", Info)

using namespace std;

extern int input(int argc, char** argv);
void check(int argc, char** argv);

int main(int argc, char *argv[])
{
    
    // try{
    //     check(argc, argv);
    // } catch(const Exception& exception){
    //     cout<<exception.what()<<'\n';
    // }

    Shape shape(vector<Position2D>{
        Position2D(150, 150), Position2D(570, 150),
        Position2D(570, 570), Position2D(150, 570),
        Position2D(150, 150), Position2D(570, 570)
    });

    BMP canvas=BMP::blank(720, 720, COLOR::Green);    
    canvas.set_color(COLOR::Aqua);
    for(unsigned i=0;i<71;++i){
        // canvas.draw_line(Position2D(360, 360), Position2D(10, 10+i*10));
        // canvas.draw_line(Position2D(360, 360), Position2D(709, 10+i*10));

        // canvas.draw_line(Position2D(360, 360), Position2D(10+i*10, 10));
        // canvas.draw_line(Position2D(360, 360), Position2D(10+i*10, 709));
    }
    canvas.draw_text("hello ali 0123456789", Position2D(50, 50));
    canvas.draw_text("i think everythink is good", Position2D(330, 350));

    canvas.save("canvas.bmp");

    return 0;
}

void check(int argc, char** argv){
    if(argc>14){
        throw Exception("Appropriate usage : ", Light);
    }
    
    // char *c_value=nullptr, *r_value=nullptr;
    char opt;
    opterr=0;
    while((opt=getopt(argc,argv,"c:r:s"))!=-1){
        
        switch (opt)
        {
            case 'c':
                cout<<"c selected\n";
                break;
        
            case 'r':
                cout<<"r selected\n";
                break;

            case 's':
                cout<<"s selected\n";
                break;

            default:
                throw USAGE_INFO_ERROR;
                break;
        }
    }
}
