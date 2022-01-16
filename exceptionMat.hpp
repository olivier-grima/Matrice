#pragma once
#include <exception>
#include <iostream>

using namespace std;


//class permetant de gérer les erreur d'incides donnée en paramètre des méthodes
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

//class permetant de gérer les erreur lié à la taille des matrices où l'on souhaite faire des opérations
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

//class permetant de gérer les erreur lié à une matrice creuse 
//impossible de convertir une matrice en matrice creuse si elle comporte 50% délément non nul par exempel
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
