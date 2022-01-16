
#include "exception_mat.hpp"
#include"matriceDouble.hpp"
#include "matriceCreuse.hpp"


matriceCreuse::matriceCreuse(const int j):Matrice<double>(3,j)
{
    this->mc = new double [this->nbElem];
}

matriceCreuse::matriceCreuse(const matriceCreuse &MyMc):Matrice<double>(MyMc)
{ 
    

    this->nbNonNul=MyMc.nbNonNul;
    this->ancienNbC=MyMc.ancienNbC;
    this->ancienNbL=MyMc.ancienNbL;
}

//accesseurs
int matriceCreuse::getAncienL()
{
    return this->ancienNbL;
}

void matriceCreuse::setAncienL(int i)
{
    this->ancienNbL=i;
}

int matriceCreuse::getAncienC()
{
    return this->ancienNbC;
}

void matriceCreuse::setAncienC(int i)
{
    this->ancienNbC=i;
}


double matriceCreuse::get(const int i, const int j)const 
{

    if(i>this->nbL || i<0 || j>this->nbC || j<0)
        throw IndexInvalide ("veuillez utilser des indices valides (fonction get) !");
    return this->mc[i*this->nbC+j];
    

}

void matriceCreuse::set(const double &x,const int i, const int j) 
{
    if(i>this->nbL || i<0 || j>this->nbC || j<0)
        throw IndexInvalide ("veuillez utilser des indices valides (fonction set) !");
    this->mc[i*this->nbC+j]=x;

}


Matrice<double>* matriceCreuse::MCtoMD()const 
{
    //céation d'une matrice double de 0 de taille ancienNbL * ancienNbC
    matriceDouble *m= new matriceDouble(this->ancienNbL,this->ancienNbC); 
    for (int j = 0; j <this->nbC; j++)
        m->set(this->get(0,j),this->get(1,j),this->get(2,j)); //on restaure les valeurs aux coordonées i,j contenu dans la MC
    return m;
}

Matrice<double>* matriceCreuse::MDtoMC()const
{
     matriceDouble *m = new matriceDouble(this->nbL,nbC,0);
     return m;

}

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

        
*/




