#pragma once
//

using namespace std;

template <typename T>

class Matrice{

    protected :
        const int nbElem, nbL,nbC;

    public :
        //constructeur de 2 paramètres -> intitialisation des 3 variables membres
        Matrice(int nbLignes=0,int nbColonnes=0):nbElem(nbLignes*nbColonnes),nbL(nbLignes),nbC(nbColonnes){}
        //constructeur de copie
        Matrice(const Matrice &m)
        {
            nbElem=m.nbElem;
            nbC=m.nbC;
            nbL=m.nbL;
        }
        //destructeur virtual
        virtual ~Matrice();
        virtual T get(int i, int j)=0;
        virtual void set(T x, int i, int j)=0;
        virtual string toString() const =0;
        friend ostream& operator <<(ostream &f, const Matrice &m)
        {
            return f << m.toString();
        }
}; 