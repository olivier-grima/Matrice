#pragma once
#include "matrice.hpp"


class matriceCreuse;

class matriceDouble:public Matrice <double>
{
    
    protected : 
        double *mat;


    public:
        //constructeur de matriceDouble 
         matriceDouble(const int i,const int j, double v=0.0):Matrice<double>(i,j)
        {
            this->mat = new double [this->nbElem];
        
            for(int i=0;i<this->nbElem;i++)
            {
                this->mat[i]=v;
            }
        }
        //constructeur de copie
        matriceDouble(const matriceDouble &md):Matrice<double>(md)
        { 
             this->mat = new double [this->nbElem];

            for(int i=0;i<this->nbElem;i++)
            {
                md.mat[i]=this->mat[i];               
            }

        }
        //destructeur virtuel -> on supprime la matrice
        virtual ~matriceDouble()
        {
            delete this->mat;
        }


        virtual double get(const int i, const int j)const override;
        
        virtual void set(const double &x,const int i, const int j) override;

        virtual string toString() const override;
        
        virtual Matrice<double>* subMat(int i1,int i2, int j1,int j2)const override;
        
        virtual Matrice<double>* SomMat(const Matrice<double> &m1)const override;

        virtual Matrice<double>* MultMat(const Matrice<double> &m1)const override;

        //méthode de conversion d'une matriceDouble à une matriceCreuse
        virtual Matrice<double>* MDtoMC()const override;
        //méthode de conversion d'une matriceCreuse à une matriceDouble
        virtual Matrice<double>* MCtoMD()const override;
        //méthode de test de matrice, on compte le nombre de 0, si il est supérieur à 90% de la matrice, elle est creuse
        virtual int estCreuse()const ;


       
      

};