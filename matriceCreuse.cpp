
#include "exceptionMat.hpp"
#include"matriceDouble.hpp"
#include "matriceCreuse.hpp"
#include <sstream>

using namespace std;

//Constructeur de matrice creuse
matriceCreuse::matriceCreuse(const int i,const int j):Matrice<double>(i,j)
{
    this->mc = new double [this->nbElem];
}

//Constructeur de copie de matrice creuse
matriceCreuse::matriceCreuse(const matriceCreuse &MyMc):Matrice<double>(MyMc)
{ 
    this->ancienNbC=MyMc.ancienNbC;
    this->ancienNbL=MyMc.ancienNbL;
    for(int i=0;i<this->nbElem;i++)
    {
        MyMc.mc[i]=this->mc[i];               
    }
}

//destructeur de matrice creuse
matriceCreuse::~matriceCreuse()
{
    delete this->mc;
}

//accesseurs
int matriceCreuse::getAncienL()
{
    return this->ancienNbL;//retourne le parametre ancienL
}

void matriceCreuse::setAncienL(int i)
{
    this->ancienNbL=i;//affecte i au parametre ancienL
}

int matriceCreuse::getAncienC()
{
    return this->ancienNbC;//retourne le parametre ancienC
}

void matriceCreuse::setAncienC(int i)
{
    this->ancienNbC=i;//affecte i au parametre ancienC
}

//methode get de matrice creuse
double matriceCreuse::get(const int i, const int j)const 
{

    if(i>this->nbL || i<0 || j>this->nbC || j<0)
        throw IndexInvalide ("veuillez utilser des indices valides (fonction get) !"); //gestion des erreur liees aux index
    //les indices sont valides
    return this->mc[i*this->nbC+j];//on retourne l'element (i,j)
    

}

//methode set de matrice creuse
void matriceCreuse::set(const double &x,const int i, const int j) 
{
    if(i>this->nbL || i<0 || j>this->nbC || j<0)
        throw IndexInvalide ("veuillez utilser des indices valides (fonction set) !");//gestion des erreur liees aux index
    //les indices sont valides
    this->mc[i*this->nbC+j]=x;//on affecte la valeur x en (i,j)

}

//methode permetant la convertion d'une matrice creuse en matrice double
Matrice<double>* matriceCreuse::MCtoMD()const 
{
    //ceation d'une matrice double de 0 de taille ancienNbL * ancienNbC
    matriceDouble *m= new matriceDouble(this->ancienNbL,this->ancienNbC,0); 
    
    for(int i=0;i<this->nbL;i++)
    {
        m->set(this->get(i,0),this->get(i,1),this->get(i,2));//on restaure les valeurs aux coordonees i,j contenu dans la MC
    }
    return m;
}

//methode permatant la converiton d'une matrice en double en matrice creuse
Matrice<double>* matriceCreuse::MDtoMC()const
{
     matriceCreuse *m = new matriceCreuse(1,1);
     return m;

}


//re definition
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
//conversion en string d'une matrice creuse
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
    return 1;//une matrice creuse est toujours creuse
}


int matriceCreuse::NbrElementNN()const
{
       
    return this->nbElem/3;// le nombre d'element d'une matrice creuse correspond au nombre d'element qu'elle contient/3
}

        





