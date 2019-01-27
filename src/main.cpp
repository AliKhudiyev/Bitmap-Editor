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

/*
argv[1] - the command index
argv[2] ... argv[argc-7] - the command parameters
argv[argc-6] ... argv[argc-4] - the color parameter given with unsigned r, g and b
argv[argc-3] - the thickness parameter given with unsigned t
argv[argc-2] - the magnify parameter given with double f
argv[argc-1] - the image name given with string
*/

int main(int argc, char *argv[])
{
    BMP image;
    image.load("mtp.bmp");
    if(strcmp(argv[1], "-22")==0){  // create canvas
        image=BMP::blank(atoi(argv[2]), atoi(argv[3]));
    } else if(strcmp(argv[1], "-18")==0){     // draw line
        cout<<"Drawing line positions : ("<<atoi(argv[2])<<", "<<atoi(argv[3])<<"), (";
        // cout<<atoi(argv[4])<<", "<<atoi(argv[5])<<")\n";
        image.draw_line(Position2D(atoi(argv[2]), atoi(argv[3])), Position2D(atoi(argv[4]), atoi(argv[5])));
    } else if(strcmp(argv[1], "-20")==0){   // draw text
        image.draw_text(argv[2], Position2D(atoi(argv[3]), atoi(argv[4])));
    } else if(0){
        ;
    }
    image.save("mtp.bmp");

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
