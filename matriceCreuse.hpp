#pragma once
#include "matrice.hpp"
#include "matriceDouble.hpp"
#include "exception_mat.hpp"

class matriceDouble;
class matriceCreuse : public Matrice<double>
{
    protected :
        double *mc;
        double nbNonNul;
        int ancienNbL,ancienNbC;
    
      

    public :
        matriceCreuse(const int j):Matrice<double>(3,j)
        {
            this->mc = new double [this->nbElem];
        }

        matriceCreuse(const matriceCreuse &mc):Matrice<double>(mc)
        { 
            this->nbNonNul=mc.nbNonNul;
            this->ancienNbC=mc.ancienNbC;
            this->ancienNbL=mc.ancienNbL;
        }
        virtual ~matriceCreuse(){
            delete this->mc;
        };
        //accesseurs
        int getAncienL()
        {
            return this->ancienNbL;
        }

        void setAncienL(int i)
        {
            this->ancienNbL=i;
        }

        int getAncienC()
        {
            return this->ancienNbC;
        }
        
        void setAncienC(int i)
        {
            this->ancienNbC=i;
        }



        virtual double get(const int i, const int j)const override
        {

            if(i>this->nbL || i<0 || j>this->nbC || j<0)
                throw IndexInvalide ("veuillez utilser des indices valides (fonction get) !");
            return this->mc[i*this->nbC+j];

        }

        virtual void set(const double &x,const int i, const int j) override
        {
            if(i>this->nbL || i<0 || j>this->nbC || j<0)
                throw IndexInvalide ("veuillez utilser des indices valides (fonction set) !");
            this->mc[i*this->nbC+j]=x;
    
        }

        virtual Matrice<double>* subMat(int i1,int i2, int j1,int j2)const override;
        virtual Matrice<double>* SomMat(const Matrice<double> &m1)const override;
        virtual Matrice<double>* MultMat(const Matrice<double> &m1)const override; 

        virtual string toString() const;
        virtual Matrice<double>* MDtoMC()const override;
        virtual int estCreuse()const override;

       /*

        
        virtual int NbrElementNN()
        {
            int cpt;
            for(int i=0;i<this->getL();i++)
            {
                for(int j=0;j<this->getC();j++)
                {
                    if(this->get(i,j)!=0)
                        cpt++;
                }
            }
            this->nbNonNul=cpt;
            return cpt;
        }

       
        virtual int estCreuse()const
        {
            int cpt;
            if(((this->getNbElem()-this->nbNonNul)/this->getNbElem())*100<90)
           
                return 0;// la matrice est non creuse
            return 1;//matrice creuse

        }

        
        virtual void MCtoMD()
        {
           
            //céation d'une matrice double de 0 de taille ancienNbL * ancienNbC
            Matrice<double> md(this->ancienNbL,this->ancienNbC); 
            for (int j = 0; j <this->getC(); j++)
                md.set(this->get(0,j),this->get(1,j),this->get(2,j)); //on restaure les valeurs aux coordonées i,j contenu dans MC
            
        }*/
    
};