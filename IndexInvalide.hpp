#pragma once
#include <exception>

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