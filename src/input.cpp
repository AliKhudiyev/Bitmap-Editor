#include<vector>
#include<string>
#include<string.h>
#include"exception.hpp"

using namespace std;

static const vector<string> CMD{
    "create canvas",
    "set fill",
    "set thickness",
    "vertical cut", "horizontal cut",
    "rotate",
    "draw point",
    "draw line",
    "draw triangle",
    "draw rectangle",
    "draw circle",
    "draw point fill",
    "draw line fill",
    "draw triangle fill",
    "draw rectangle fill",
    "draw circle fill",
    "detect borders",
    "scale",
    "crop",
    "save", "load", "undo", "redo", "quit"
};

static const vector<int> n_arg{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

typedef int command_t;

vector<string> trash_token(const string& str, char tk1, char tk2){
    vector<string> wt_token(str.size());
    unsigned index=0, beg=0, end=0;
    bool pass=false;
    for(unsigned i=0;i<str.size();++i){
        if(str[i]!=tk1 && str[i]!=tk2 && !pass){
            beg=i;
            pass=true;
        }
        if((str[i]==tk1 || str[i]==tk2) && pass){
            end=i-1;
            pass=false;

            wt_token[index++]=str.substr(beg,end-beg);
        }
    }
    return wt_token;
}

command_t cmd_index(int argc, char** argv){
    command_t cmd=-1;
    string args;
    for(unsigned index=0;index<CMD.size();++index){
        if(CMD[index].compare(argv[1])==0){
            cmd=index;
            if(argc<n_arg[index]-1) return -1;
            break;
        }
    }
    return cmd;
}

vector<string> cmd_arg(int argc, char** argv){
    if(argc==1) exit(1);
    vector<string> command;
    command_t cmd=cmd_index(argc, argv);
    if(cmd==-1){
        ;   // throw an exception!
    }
    if(cmd){
        ;
    } else if(cmd){
        ;
    }
    return command;
}
