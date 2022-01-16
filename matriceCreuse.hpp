#pragma once
#include "matrice.hpp"


class matriceDouble;
class matriceCreuse : public Matrice<double>
{
    protected :
        double *mc;
        double nbNonNul;
        int ancienNbL,ancienNbC;
        
    
      

    public :
        matriceCreuse(const int i,const int j);

        matriceCreuse(const matriceCreuse &MyMc);

        virtual ~matriceCreuse();
        //accesseurs
        virtual int getAncienL();

        virtual void setAncienL(int i);

        virtual int getAncienC();
        
        virtual void setAncienC(int i);



        virtual double get(const int i, const int j)const override;

        virtual void set(const double &x,const int i, const int j) override;

        virtual Matrice<double>* subMat(int i1,int i2, int j1,int j2)const override;
        virtual Matrice<double>* SomMat(const Matrice<double> &m1)const override;
        virtual Matrice<double>* MultMat(const Matrice<double> &m1)const override; 

        virtual string toString() const override;



        virtual Matrice<double>* MDtoMC()const override ;
        virtual int estCreuse()const override;


        virtual Matrice<double>* MCtoMD()const override ;
        
        virtual int NbrElementNN()const override;
      
    
};