#pragma once
#include <exception>
#include <iostream>

using namespace std;



class IndexInvalide : public exception
{
    private:
        string msg;
        
    public:

        IndexInvalide(string mess):msg(mess){}
        virtual const char* what() const noexcept override
        {
            return this->msg.c_str();

            
        }

};

class TailleInvalide :public exception
{
    private:
        string msg;
        
    public:

        TailleInvalide(string mess):msg(mess){}
        virtual const char* what() const noexcept override
        {
            return this->msg.c_str();

            
        }
};


class InvalideCreuse :public exception
{
    private:
        string msg;
        
    public:

        InvalideCreuse(string mess):msg(mess){}
        virtual const char* what() const noexcept override
        {
            return this->msg.c_str();

            
        }
};
