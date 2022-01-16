
#include "exceptionMat.hpp"
#include"matriceDouble.hpp"
#include "matriceCreuse.hpp"
using namespace std;


matriceCreuse::matriceCreuse(const int i,const int j):Matrice<double>(i,j)
{
    this->mc = new double [this->nbElem];
}

matriceCreuse::matriceCreuse(const matriceCreuse &MyMc):Matrice<double>(MyMc)
{ 
    

    this->nbNonNul=MyMc.nbNonNul;
    this->ancienNbC=MyMc.ancienNbC;
    this->ancienNbL=MyMc.ancienNbL;
}
matriceCreuse::~matriceCreuse()
{
    delete this->mc;
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
    return this->mc[i*this->nbC+j];//on retourne l'element (i,j)
    

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
    matriceDouble *m= new matriceDouble(this->ancienNbL,this->ancienNbC,0); 
    
    for(int i=0;i<this->nbL;i++)
    {
        m->set(this->get(i,0),this->get(i,1),this->get(i,2));//on restaure les valeurs aux coordonées i,j contenu dans la MC
    }
    return m;
}

Matrice<double>* matriceCreuse::MDtoMC()const
{
     matriceCreuse *m = new matriceCreuse(1,1);
     return m;

}






Matrice<double>* matriceCreuse::subMat(int i1,int i2, int j1,int j2)const{
    matriceCreuse *m = new matriceCreuse(1,1);
     return m;
}
Matrice<double>* matriceCreuse::SomMat(const Matrice<double> &m1)const 
{
    matriceCreuse *m = new matriceCreuse(1,1);
     return m;
}
Matrice<double>* matriceCreuse::MultMat(const Matrice<double> &m1)const 
{
    matriceCreuse *m = new matriceCreuse(1,1);
     return m;
}

string matriceCreuse::toString() const 
{
    
    ostringstream os;
    for(int i=0;i<this->NbrElementNN();i++)
    {
        for(int j=0;j<3;j++)
        {
            os<< "("<<this->mc[i*3+j]<<")";
            
        }
        os<<"\n";
    }

    return os.str();
}

int matriceCreuse::estCreuse()const
{
    return 1;
}


int matriceCreuse::NbrElementNN()const
{
       
    return this->nbElem/3;
}

        





