#pragma once


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
        virtual T get(const int i, const int j)const=0;
        virtual void set(const T &x, int i, int j)=0;
        //accesseurs car nbElem, nbC, nbL sont protégés
        int getC()const
        {
            return this->nbC;
        }
        int getL()const
        {
            return this->nbL;

        }
        int getNbElem()const
        {
            return this->nbElem;
        }
        virtual Matrice<T>* subMat(int i1,int i2, int j1,int j2)const =0;
        virtual Matrice<T>* SomMat(const Matrice<T> &m1)const =0;
        virtual Matrice<T>* MultMat(const Matrice<T> &m1)const =0; 

        virtual string toString() const =0;
        friend ostream& operator <<(ostream &f, const Matrice<T> &m)
        {
            return f << m.toString();
        }
        virtual Matrice<T> &operator +(const Matrice<T> &m)
        {
            return *this->SomMat(m);
        }
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