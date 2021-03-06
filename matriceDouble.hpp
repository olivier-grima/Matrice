#pragma once
#include "matrice.hpp"


class matriceCreuse;

class matriceDouble:public Matrice <double>
{
    
    protected : 
        double *mat;

    public:
        //constructeur de matriceDouble 
        matriceDouble(const int i,const int j, double v);
        //constructeur de copie
        matriceDouble(const matriceDouble &md);
        //destructeur virtuel -> on supprime la matrice
        virtual ~matriceDouble();

        virtual double get(const int i, const int j)const override;
        virtual void set(const double &x,const int i, const int j) override;

        virtual string toString() const override;

        virtual Matrice<double>* subMat(int i1,int i2, int j1,int j2)const override;
        virtual Matrice<double>* SomMat(const Matrice<double> &m1)const override;
        virtual Matrice<double>* MultMat(const Matrice<double> &m1)const override;
        //methode de conversion d'une matriceDouble a une matriceCreuse
        virtual Matrice<double>* MDtoMC()const override;
        //methode de conversion d'une matriceCreuse a une matriceDouble
        virtual Matrice<double>* MCtoMD()const override;
        //methode de test de matrice, on compte le nombre de 0, si il est superieur a 90% de la matrice est creuse
        virtual int estCreuse()const override;//test si une matrice est creuse
        virtual int NbrElementNN()const override;//renvoi le nombre d'elements non nul de la matrice
};