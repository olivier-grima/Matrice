#pragma once
#include "matrice.hpp"
#include <cassert>

using namespace std;

class matriceDouble:public Matrice <double>
{
    protected : 
        double *mat;

    public:
         matriceDouble(const int i,const int j, double v=0):Matrice<double>(i,j)
        {
            this->mat = new double [nbElem];
        
            for(int i=0;i<this->nbElem;i++)
            {
                mat[i]=0;
            }
        }

        matriceDouble(const matriceDouble &md)
        { 
            for(int i=0;i<this->nbElem;i++)
            {
                mat[i]=this->mat[i];               
            }

        }
     
        ~matriceDouble()
        {

        }


        virtual double get(const int i, const int j) const
        {
            return this->mat[i*this->nbC+j+1];
        }     
        virtual void set(double x,int i, int j)
        {
            this->mat[i*this->nbC+j+1]=x;
        }
        string toString() const 
        {
            for(int i=0;i<this->nbElem;i++)
            {
                
            }
        }

};