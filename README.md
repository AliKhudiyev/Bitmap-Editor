# Introduction. #
**The Library for Image Processing written in C++.**<br/>
There is not any of OpenGL functions or something like that. All functions have
been written from scratch. This library is to process bitmap images.<br/>
**__[More detailed information(including manual)](https://www.overleaf.com/read/vgvmbbscrhnb "Manual")__**

## Availabilities and options. ##
Fundamentally there are couple of functionalities which the library contains.
- Drawing pixels between 2 given positions without any gaps.
- Storing bitmap image in a significant way.
- Handling any unwanted situations efficiently.

With using the shown functions any shape can be drew. However, there can be some figures which may possibly take significantly long time to draw. Besides, there is a function to draw
a string in the image.

### Error handling. ###
There are several error types used to detect and handle unwanted situations
during the processing. Here is the error table:

|     Error    |    Description    |    Affect on the program flow    |
|--------------|:-----------------:|---------------------------------:|
|    Default   | Any other type of error |         Undefined          |

#### A simple example program. ####
```c++
#include<iostream>
#include"bmp.hpp"

using namespace std;

int main(int argv, char** argv){

    BMP image;

    try{
        image=BMP::blank(720, 720, COLOR::White);
        image.draw(Position2D(150, 150), Position2D(570, 570));
        image.draw(Position2D(150, 570), Position2D(570, 150));
        image.save("processed.bmp");
    } catch(const Exception& exception){
        cout<<exception.what()<<'\n';
    }

    return 0;
}
```
