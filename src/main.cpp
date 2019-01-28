#include<iostream>
#include"chdrs.hpp"
#include"bmp.hpp"
#include"text.hpp"

#define STR2LEN(x) atoi(x)
#define STR2POS(x,y) Position2D(STR2LEN(x),STR2LEN(y))

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
    Color color(atoi(argv[argc-4]), atoi(argv[argc-5]), atoi(argv[argc-6]));
    thickness_t thickness=atoi(argv[argc-3]);
    unsigned magnify=atof(argv[argc-2]);
    string image_name=argv[argc-1];

    BMP image;
    
    if(!image_name.empty()) image.load(image_name);
    else{
        cout<<"tmp image name has been selected.\n";
        image_name="__tmp_img_01.bmp";
    }

    if(strcmp(argv[1], "-0")==0){               // quit
        ;   // nothing to do for now
    } else if(strcmp(argv[1], "-1")==0){        // remove
        ;
    } else if(strcmp(argv[1], "-2")==0){        // detect borders
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-3")==0){        // undo
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-4")==0){        // redo
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-5")==0){        // hide ruler
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-6")==0){        // save
        image_name=argv[2];
    } else if(strcmp(argv[1], "-7")==0){        // load
        ;   // nothing to do for now
    } else if(strcmp(argv[1], "-8")==0){        // show ruler
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-9")==0){        // crop
        ;
    } else if(strcmp(argv[1], "-10")==0){       // horizontal cut
        ;
    } else if(strcmp(argv[1], "-11")==0){       // vertical cut
        ;
    } else if(strcmp(argv[1], "-12")==0){       // rotate
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-13")==0){       // draw point
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-14")==0){       // set thickness
        ;   // nothing to do for now
    } else if(strcmp(argv[1], "-15")==0){       // set fill
        ;   // nothing to do for now
    } else if(strcmp(argv[1], "-16")==0){       // magnify
        ;   // nothing to do for now
    } else if(strcmp(argv[1], "-17")==0){       // scale
        ;
    } else if(strcmp(argv[1], "-18")==0){       // draw line
        image.draw_line(STR2POS(argv[2],argv[3]), STR2POS(argv[4],argv[5]), color, thickness);
    } else if(strcmp(argv[1], "-19")==0){       // draw circle
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-20")==0){       // draw text
        image.draw_text(argv[2], STR2POS(argv[3],argv[4]), magnify, color, thickness);
    } else if(strcmp(argv[1], "-21")==0){       // draw function
        ;   // isn't prepared
    } else if(strcmp(argv[1], "-22")==0){       // create canvas
        image=BMP::blank(STR2LEN(argv[2]), STR2LEN(argv[3]), color);
    } else if(strcmp(argv[1], "-23")==0){       // draw triangle
        ;
    } else if(strcmp(argv[1], "-24")==0){       // set color
        ;   // nothing to do for now
    }
    
    image.save(image_name);

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
