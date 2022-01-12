#pragma once
#include "matrice.hpp"
#include "IndexInvalide.hpp"

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



        /*friend Matrice<double> operator =(const Matrice<double> &m)
        {
            this->nbElem=m.nbElem;
            this->nbC=m.nbC;
            this->nbL=m.nbL;
            return *this->Matrice(m);
        }*/

        virtual double get(const int i, const int j)const override
        {
            if(i>this->nbL || i<0 || j>this->nbC || j<0)
                throw IndexInvalide ("veuillez utilser des indices valides (fonction get) !");
            return this->mat[i*this->nbC+j];
            
            
        }     
        virtual void set(const double &x,const int i, const int j) override
        {
            if(i>this->nbL || i<0 || j>this->nbC || j<0)
               throw IndexInvalide ("veuillez utilser des indices valides (fonction set) !");
            this->mat[i*this->nbC+j]=x;
            
        }
        string toString() const 
        {
            ostringstream os;
            for(int i=0;i<this->nbL;i++)
            {
                for(int j=0;j<this->nbC;j++)
                {
                    os<< "("<<this->mat[i*this->nbC+j]<<")";
                }
                os<<"\n";
            }

            return os.str();
        }
        virtual Matrice<double>* subMat(int i1,int i2, int j1,int j2)const override
        {
            
           
                if(i1>=i2 || i1<0 || i1>this->nbL)
                    throw IndexInvalide ("erreur sur l'indice i1 (fonction subMat)");
                if(j1>=j2 || j1<0 || j1>this->nbC)
                    throw IndexInvalide ("erreur sur l'indice j1 (fonction subMat)");

                if(i2<0 || i2>=this->nbL)
                    throw IndexInvalide ("erreur sur l'indice i2 (fonction subMat)");
                if(j2<0 || j2>=this->nbC)
                    throw IndexInvalide ("erreur sur l'indice j2 (fonction subMat)");

                
                matriceDouble *m = new matriceDouble(i2-i1+1,j2-j1+1);
                for(int i=i1;i<=i2;i++)
                {
                    for(int j=j1;j<=j2;j++)
                    {
                        m->set(this->get(i,j),i-i1,j-j1);
    
                    }
                }
            

            return m;
        }
        
        Matrice<double>* SomMat(const Matrice<double> &m1)const override
        {

            if(this->nbC!=m1.getC() || this->nbL!=m1.getL())
                throw TailleInvalide("Les 2 matrices n'ont pas la même taille, somme impossible");
            matriceDouble *m = new matriceDouble(m1.getL(),m1.getC());
            for(int i=0;i<m1.getL();i++)
            {
                for(int j=0;j<m1.getC();j++)
                {
                    m->set(this->get(i,j)+m1.get(i,j),i,j);
                }
            }
            return m;
        }

        Matrice<double>* MultMat(const Matrice<double> &m1)const override
        {
            if(this->nbC!=m1.getL())
                throw TailleInvalide("Les 2 matrices ne sont pas compatible, multiplication impossible");
            matriceDouble *m = new matriceDouble(this->nbL,m1.getC(),0);
            for(int i=0;i<this->nbL;i++)
            {
                for(int j=0;j<m1.getC();j++)
                {
                    for(int c=0;c<this->nbC;c++ )
                    {
                        m->set(m->get(i,j)+this->get(i,c)*m1.get(c,j),i,j);
                    }
                        
                }
            }
            return m;
        }

};