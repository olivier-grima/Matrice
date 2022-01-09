#pragma once


using namespace std;

template <typename T>

class Matrice{

    protected :
        int nbElem, nbL,nbC;

    public :
        //constructeur de 2 paramètres -> intitialisation des 3 variables membres
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
        virtual T get(const int i, const int j)const=0;
        virtual void set(const T &x, int i, int j)=0;
        virtual string toString() const =0;
        friend ostream& operator <<(ostream &f, const Matrice<T> &m)
        {
            return f << m.toString();
        }
}; 