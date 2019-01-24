
#pragma once

#include<exception>
#include<string>

enum Error{
    Default=0,
    Light,
    Fatal,
    Memory,
    Logic,
    Info,
};

class Exception: public std::exception{
    private:
    std::string msg_;
    Error error_=Error::Default;

    public:
    Exception(const std::string& msg): 
        msg_(msg), error_(Error::Default) {}
    Exception(const std::string& msg, const Error& error=Error::Default): 
        error_(error) 
    {
        switch(error){
            case Error::Light:
                msg_="Light Error: "+msg;
                msg_+="\tInitializing default values to continue..";
                break;
            case Error::Fatal:
                msg_="Fatal Error: "+msg;
                break;
            case Error::Memory:
                msg_="Memory Error: "+msg;
                break;
            case Error::Logic:
                msg_="Logic Error: "+msg;
                break;
            case Error::Info:
                msg_="Info: "+msg;
                break;
            default: break;
        }
    }
    const char* what() const noexcept{
        return msg_.c_str();
    }
};
