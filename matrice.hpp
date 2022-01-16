#pragma once
#include<sstream>

using namespace std;

template <typename T>

class Matrice{

    protected :
        int nbElem, nbL,nbC;

    public :
        //constructeur à 2 paramètres -> intitialisation des 3 variables membres
        Matrice(int nbLignes=0,int nbColonnes=0):nbElem(nbLignes*nbColonnes),nbL(nbLignes),nbC(nbColonnes){}
        //constructeur de copie
        Matrice(const Matrice<T> &m)
        {
            nbElem=m.nbElem;
            nbC=m.nbC;
            nbL=m.nbL;
        }
        //destructeur virtual
        virtual ~Matrice(){};

        //accesseurs
        virtual int getNbL()const
        {
            return this->nbL;
        }

        virtual int getNbC()const
        {
            return this->nbC;
        }

        virtual int getNbElem()const
        {
            return this->nbElem;
        }
        
        //methode get : retourne l'element T contenu en (i,j) 
        virtual T get(const int i, const int j)const=0;
        //methode set : affecte l'element T en (i,j)
        virtual void set(const T &x, int i, int j)=0;
       //re-declaration des fonction des classes filles pour qu'elles soient bien defini
        virtual Matrice<T>* subMat(int i1,int i2, int j1,int j2)const =0;
        virtual Matrice<T>* SomMat(const Matrice<T> &m1)const =0;
        virtual Matrice<T>* MultMat(const Matrice<T> &m1)const =0; 
        virtual Matrice<T>* MDtoMC()const=0;
        virtual Matrice<T>* MCtoMD()const=0;
        virtual int estCreuse()const=0;
        virtual int NbrElementNN()const=0;

        
        virtual string toString() const =0;
        //surcharge de l'operateur << pour permettre l'ecriture de matrice
        friend ostream& operator <<(ostream &f, const Matrice<T> &m)
        {
            return f << m.toString();
        }
        //surcharge de l'operateur + pour l'addition de matrices
        virtual Matrice<T> &operator +(const Matrice<T> &m)
        {
            return *this->SomMat(m);
        }
        //surcharge de l'operateur * pour la multiplication de matrices
        virtual Matrice<T> &operator *(const Matrice<T> &m)
        {
            return *this->MultMat(m);
        }
        
        /*virtual Matrice<T> &operator =(const Matrice<T> &m)
        {
            this->nbElem=m.nbElem;
            this->nbC=m.nbC;
            this->nbL=m.nbL;
            return *this->Matrice<T>(m);
        }*/

       

       
}; 