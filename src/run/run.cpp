#include<iostream>
#include<vector>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<string.h>

using namespace std;

using cmd_t=int;

static char *r, *g, *b;
static char *thickness;
static char *magnify;
static char *image_name;

const string commands[25]{
    "quit",
    "remove",
    "detect borders",
    "undo",
    "redo",
    "hide ruler",
    
    "save",
    "load",
    "show ruler",
    "crop",
    "horizontal cut",
    "vertical cut",
    "rotate",
    "draw point",
    "set thickness",
    "set fill",
    "magnify",
    
    "scale",
    "draw line",
    "draw circle",
    "draw text",
    "draw function",
    
    "create canvas",
    "draw triangle",
    "set color"
};

vector<string> process(const std::string& proc, const std::string& text);

int main(int argc, char const *argv[])
{
    pid_t pid;
    r=(char*)mmap(NULL, 3, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    g=(char*)mmap(NULL, 3, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    b=(char*)mmap(NULL, 3, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    thickness=(char*)mmap(NULL, 2, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    magnify=(char*)mmap(NULL, 2, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    image_name=(char*)mmap(NULL, 30, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    cout<<"The program has been started.\n";

    r[0]='0';
    g[0]='0';
    b[0]='0';
    thickness[0]='1';
    magnify[0]='1';
    image_name[0]='\0';

    std::cout<<"forking..\n";
    bool pass=true;

    for(;pass;){
        pid=fork();
        switch(pid){
            case -1:
                exit(1);
            
            case 0:
            {
                string command;
                cmd_t index=-1;
                // string r="0", g="0", b="0";
                // string thickness="1";
                // string magnify="1";
                // string image_name="";

                getline(cin, command);
                for(cmd_t in=0;in<25;++in){
                    if(commands[in]==command.substr(0, commands[in].size())){
                        index=in;
                        break;
                    }
                }
                vector<string> params;
                size_t pos=commands[index].size();
                string param_list=command.substr(pos, command.size()-pos);
                cout<<"Parameter list : "<<param_list<<'\n';
                
                cout<<"\tchild\n";
                cout<<"\tindex : "<<index<<'\n';

                if(index==0){               // quit
                    exit(1);
                } else if(index==1){
                    ;
                } else if(index==2){
                    ;
                } else if(index==3){
                    ;
                } else if(index==4){
                    ;
                } else if(index==5){
                    ;
                } else if(index==6){        // save
                    params=process(" `", param_list);
                    strcpy(image_name, (char*)&params[0][0]);
                } else if(index==7){        // load
                    params=process(" `", param_list);
                    // image_name=(char*)&params[0][0];
                    strcpy(image_name, (char*)&params[0][0]);
                } else if(index==8){
                    ;
                } else if(index==9){
                    ;
                } else if(index==10){
                    ;
                } else if(index==11){
                    ;
                } else if(index==12){
                    ;
                } else if(index==13){
                    ;
                } else if(index==14){       // set thickness
                    params=process(" `", param_list);
                    strcpy(thickness, (char*)&params[0][0]);
                } else if(index==15){       // set fill
                    params=process("[  ]", param_list);
                    strcpy(r, (char*)&params[0][0]);
                    strcpy(g, (char*)&params[1][0]);
                    strcpy(b, (char*)&params[2][0]);
                } else if(index==16){       // magnify
                    params=process(" `", param_list);
                    strcpy(magnify, (char*)&params[0][0]);
                } else if(index==17){
                    ;
                } else if(index==18){       // draw line
                    params=process("[ ]%[ ]", param_list);
                } else if(index==19){
                    ;
                } else if(index==20){       // draw text
                    params=process("''%[ ]", param_list);
                } else if(index==21){
                    ;
                } else if(index==22){
                    ;
                } else if(index==23){
                    ;
                } else if(index==24){
                    ;
                }

                // preparing to call execvp
                char* args[30];
                args[0]=(char*)"./main";
                args[1]=(char*)&to_string(-1*index)[0];
                for(unsigned i=1;i<=params.size();++i){
                    cout<<"init : "<<params[i-1]<<'\n';
                    args[i+1]=(char*)&(params[i-1][0]);
                }
                unsigned in=2+params.size();
                args[in++]=(char*)&r[0];
                args[in++]=(char*)&g[0];
                args[in++]=(char*)&b[0];
                args[in++]=(char*)&thickness[0];
                args[in++]=(char*)&magnify[0];
                args[in++]=(char*)&image_name[0];
                args[in++]=(char*)NULL;
                
                cout<<"current image name : "<<image_name[0]<<image_name[1]<<image_name[2]<<"...\n";

                execvp(args[0], args);
                exit(0);
            }
            
            default:
            {
                int why;
                wait(&why);
                int stat=WEXITSTATUS(why);
                if(stat==1) pass=false;
                if(stat==0){
                    cout<<"parent pid : "<<getppid()<<"\n";
                }
                break;
            }
        }
    }

    return 0;
}

vector<string> process(const std::string& proc, const std::string& text){
    vector<string> str;
    size_t beg=0, end;

    unsigned in=0;
    for(unsigned i=0;i<proc.size()-1;++i, beg=end){
        if(proc[i+1]=='%'){
            ++i;
            continue;
        }
        beg=text.find(proc[i], beg);
        if(proc[i+1]=='`'){
            if(text.find(" ", beg+1)==std::string::npos){
                end=text.size();
            } else{
                end=text.find(" ", beg+1);
            }
        }
        else end=text.find(proc[i+1], beg+1);
        std::cout<<beg<<", "<<end<<'\n';
        str.push_back(text.substr(beg+1, end-beg-1));
        cout<<str[in++]<<'\n';
    }

    return str;
}
