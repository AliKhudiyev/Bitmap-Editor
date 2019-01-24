#include<iostream>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

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
                cout<<"\tchild\n";
                cin>>command;
                if(command.compare("cut")==0){
                    cout<<"cut\n";
                } else if(command.compare("rotate")==0){
                    cout<<"rotate\n";
                } else if(command.compare("quit")==0){
                    exit(1);
                } else{
                    cout<<"ERR: command not found!\n";
                }
                char *args[]={"./main", (char*)NULL};
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

