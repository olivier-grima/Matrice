#pragma once
#include "matrice.hpp"


using namespace std;

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
     
        ~matriceDouble()
        {
            delete this->mat;
        }


        virtual double get(const int i, const int j)const override
        {
            return this->mat[i*this->nbC+j];
        }     
        virtual void set(const double &x,const int i, const int j) override
        {
            this->mat[i*this->nbC+j]=x;
            
        }
        string toString() const 
        {
            ostringstream os;
            for(int i=0;i<this->nbC;i++)
            {
                for(int j=0;j<this->nbL;j++)
                {
                    os<< "("<<this->mat[i*this->nbC+j]<<")";
                }
                os<<"\n";
            }

            return os.str();
        }

};