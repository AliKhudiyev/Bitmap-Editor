#include<iostream>
#include<vector>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_N_CHARS 30

using namespace std;

using cmd_t=int;

static char *maxX, *maxY;
static char *r, *g, *b;
static char* thickness;
static char* magnify;
static char* filler;
static char* image_name;
static int* exit_stat;
static bool* is_in_commander;

const string commands[27]{
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
    "horizontal crop",
    "vertical crop",
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
    "set color",

    "set coordinates",
    "info"
};

vector<string> process(const std::string& proc, const std::string& text);
cmd_t get_help(const std::string& command);
size_t matched_length(const std::string& cmd, const std::string& command);

int main(int argc, char const *argv[])
{
    pid_t pid;
    maxX=(char*)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    maxY=(char*)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    r=(char*)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    g=(char*)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    b=(char*)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    thickness=(char*)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    magnify=(char*)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    filler=(char*)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    image_name=(char*)mmap(NULL, MAX_N_CHARS*sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    exit_stat=(int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    is_in_commander=(bool*)mmap(NULL, sizeof(bool), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    cout<<"The program has been started.\n";

    *maxX='0';
    *maxY='0';
    *r='0';
    *g='0';
    *b='0';
    *thickness='1';
    *magnify='1';
    *filler='0';
    image_name[0]='\0';
    *exit_stat=0;
    *is_in_commander=false;
    bool STPmode=atoi(argv[1]);
    bool proc=true;

    while(proc){
        pid=fork();
        switch(pid){
            case -1:
                exit(1);
            
            case 0:
            {
                string command;
                cmd_t index=-1;
                *exit_stat=0;

                cout<<"Command : ";
                getline(cin, command);
                for(cmd_t in=0;in<28;++in){
                    if(commands[in]==command.substr(0, commands[in].size())){
                        index=in;
                        break;
                    }
                }
                if(index==-1){                     // ERR: no such a command
                    cout<<"No such a command!\n";
                    if(!*is_in_commander){
                        char c;
                        cout<<"Do you want to get commander help? [y/n] ";
                        cin>>c;
                        if(c=='y') *is_in_commander=true;
                    }
                    if(*is_in_commander){
                        index=get_help(command);
                    }
                    if(index==-1){
                        cout<<" :( Couldn't find an appropriate command.\n";
                        exit(2);
                    }
                    cout<<"Command has been changed to : "<<commands[index]<<'\n';
                    cout<<"Please enter the appropriate parameter(s) now: ";
                    string param;
                    cin>>param;
                    command+=(" "+param);
                }

                vector<string> params;
                size_t pos=commands[index].size();
                string param_list=command.substr(pos, command.size()-pos);

                if(index==0){               // quit
                    exit(1);
                } else if(index==1){        // remove
                    strcpy(r, "255");
                    strcpy(g, "255");
                    strcpy(b, "255");
                    strcpy(thickness, "1");
                    strcpy(magnify, "1");
                    *exit_stat=1;
                } else if(index==2){        // detect borders
                    ;
                } else if(index==3){        // undo
                    ;
                } else if(index==4){        // redo
                    ;
                } else if(index==5){        // hide ruler
                    ;
                } else if(index==6){        // save
                    params=process(" `", param_list);
                } else if(index==7){        // load
                    params=process(" `", param_list);
                    strcpy(image_name, (char*)&params[0][0]);
                    exit(0);
                } else if(index==8){
                    ;
                } else if(index==9){        // crop
                    params=process("[ ]", param_list);
                } else if(index==10){       // horizontal crop
                    params=process(" `", param_list);
                } else if(index==11){       // vertical crop
                    params=process(" `", param_list);
                } else if(index==12){       // rotate
                    params=process(" `", param_list);
                } else if(index==13){       // draw point
                    params=process("[ ]", param_list);
                } else if(index==14){       // set thickness
                    params=process(" `", param_list);
                    strcpy(thickness, (char*)&params[0][0]);
                    exit(0);
                } else if(index==15){       // set fill
                    params=process(" `", param_list);
                    strcpy(filler, (char*)&params[0][0]);
                    exit(0);
                } else if(index==16){       // magnify
                    params=process(" `", param_list);
                    strcpy(magnify, (char*)&params[0][0]);
                    exit(0);
                } else if(index==17){       // scale
                    params=process("[ ]", param_list);
                } else if(index==18){       // draw line
                    params=process("[ ]%[ ]", param_list);
                } else if(index==19){       // draw cicle
                    params=process("[ ]% `", param_list);
                } else if(index==20){       // draw text
                    params=process("''%[ ]", param_list);
                } else if(index==21){       // draw function
                    params=process("  `", param_list);
                } else if(index==22){       // create canvas
                    params=process("[ ]", param_list);
                    image_name[0]='\0';
                    *exit_stat=2;
                } else if(index==23){       // draw triangle
                    params=process("[ ]%[ ]%[ ]", param_list);
                } else if(index==24){       // set color
                    params=process("[  ]", param_list);
                    strcpy(r, (char*)&params[0][0]);
                    strcpy(g, (char*)&params[1][0]);
                    strcpy(b, (char*)&params[2][0]);
                    exit(0);
                } else if(index==25){       // set coordinates
                    params=process("[ ]", param_list);
                    strcpy(maxX, (char*)&params[0][0]);
                    strcpy(maxY, (char*)&params[1][0]);
                    exit(0);
                }

                // preparing to call execvp
                char* args[30];
                unsigned i=0;
                args[i++]=(char*)"./main";
                args[i++]=(char*)&to_string(-index)[0];
                for(;i<params.size()+2;++i){
                    // cout<<"init : "<<params[i-2]<<'\n';
                    args[i]=(char*)&(params[i-2][0]);
                }
                args[i++]=maxX;
                args[i++]=maxY;
                args[i++]=filler;
                args[i++]=r;
                args[i++]=g;
                args[i++]=b;
                args[i++]=thickness;
                args[i++]=magnify;
                args[i++]=image_name;
                args[i]=(char*)NULL;
                
                execvp(args[0], args);
            }
            
            default:
            {
                int why;
                wait(&why);
                int stat=WEXITSTATUS(why);
                if(stat==1 || STPmode) proc=false;
                if(stat==2) cout<<"Visit the wiki of commands.\n";
                else if(*exit_stat==1) strcpy(image_name, "");
                else if(*exit_stat==2) strcpy(image_name, "__tmp_img_01.bmp");
            }
        }
    }

    return 0;
}

vector<string> process(const std::string& proc, const std::string& text){
    vector<string> str;
    size_t beg=0, end;

    // unsigned in=0;
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
        // std::cout<<beg<<", "<<end<<'\n';
        str.push_back(text.substr(beg+1, end-beg-1));
        // cout<<str[in++]<<'\n';
    }

    return str;
}

cmd_t get_help(const std::string& command){
    cmd_t index=-1;
    double similarity[25];
    unsigned n_same;
    double max=0.;

    for(unsigned i=0;i<25;++i){
        n_same=0;
        similarity[i]=0.;
        for(unsigned j=0;j<commands[i].size();++j){
            for(unsigned t=0;t<command.size();++t){
                if(command[t]==commands[i][j]) ++n_same;
            }
        }
        similarity[i]=(double)n_same;
        if(max<similarity[i]){
            max=similarity[i];
            index=i;
        }
    }

    return index;
}

size_t matched_length(const std::string& cmd, const std::string& command){
    // size_t length=0;
    size_t max_length=0;
    // string curr_cmd=cmd.substr();

    for(unsigned i=0;i<command.length();++i){
        for(unsigned j=0;;++j){
            for(unsigned t=0;;++t){
                ;
            }
        }
    }

    return max_length;
}
