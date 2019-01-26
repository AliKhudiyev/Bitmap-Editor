#include<iostream>
#include<vector>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

using cmd_t=int;

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

    for(unsigned i=0;i>=0;++i){
        pid=fork();
        switch(pid){
            case -1:
                exit(1);
            
            case 0:
            {
                string command;
                cmd_t index=-1;

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
                cout<<param_list<<" - "<<'\n';
                if(index==6){
                    params=process(" `", param_list);
                } else if(index<=16){
                    ;
                } else if(index<=21){
                    params=process("~~%[ % ]", command);
                } else if(index<=24){
                    ;
                }

                cout<<"\tchild\n";
                cout<<"\tindex : "<<index<<'\n';

                char* args[3];
                args[0]=(char*)"./tell";
                for(unsigned i=1;i<2;++i){
                    cout<<"init : "<<params[i-1]<<'\n';
                    args[i]=(char*)&(params[i-1][0]);
                }   args[2]=(char*)NULL;
                execvp(args[0], args);
                exit(0);
            }
            
            default:
            {
                int why;
                wait(&why);
                int stat=WEXITSTATUS(why);
                if(stat==1) exit(0);
                if(stat==0){
                    cout<<"parent : "<<"\n";
                }
                break;
            }
        }
    }

    return 0;
}

vector<string> process(const std::string& proc, const std::string& text){
    vector<string> str_;
    size_t beg=0, end;

    // std::cout<<"proc : "<<proc<<'\n';
    // std::cout<<"text : "<<text<<'\n';
    unsigned in=0;
    for(unsigned i=0;i<proc.size()-1;++i, beg=end){
        if(proc[i+1]=='%'){
            ++i;
            continue;
        }
        // std::cout<<"current procs : "<<proc[i]<<" and "<<proc[i+1]<<'\n';
        // std::cout<<"beg pos : "<<beg<<'\n';
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
        str_.push_back(text.substr(beg+1, end-beg-1));
        cout<<str_[in++]<<'\n';
    }

    return str_;
}
