#pragma once
#include "matrice.hpp"
#include "exception_mat.hpp"


using namespace std;

class matriceCreuse;

class matriceDouble:public Matrice <double>
{
    
    protected : 
        double *mat;


    public:
         matriceDouble(const int i,const int j, double v=0.0):Matrice<double>(i,j)
        {
            this->mat = new double [this->nbElem];
        
            for(int i=0;i<this->nbElem;i++)
            {
                this->mat[i]=v;
            }
        }

        matriceDouble(const matriceDouble &md):Matrice<double>(md)
        { 
             this->mat = new double [this->nbElem];

            for(int i=0;i<this->nbElem;i++)
            {
                md.mat[i]=this->mat[i];               
            }

        }
     
        virtual ~matriceDouble()
        {
            delete this->mat;
        }

        virtual double get(const int i, const int j)const override;
        
        virtual void set(const double &x,const int i, const int j) override;

        virtual string toString() const ;
        
        virtual Matrice<double>* subMat(int i1,int i2, int j1,int j2)const override;
        
        virtual Matrice<double>* SomMat(const Matrice<double> &m1)const override;

        virtual Matrice<double>* MultMat(const Matrice<double> &m1)const override;

        virtual Matrice<double>* MDtoMC()const override;
        
       
        virtual int estCreuse()const override;

        /*friend Matrice<double> operator =(const Matrice<double> &m)
        {
            this->nbElem=m.nbElem;
            this->nbC=m.nbC;
            this->nbL=m.nbL;
            return this->Matrice(m);
        }*/

      

};