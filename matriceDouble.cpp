
#include "matriceDouble.hpp"
//#include "matriceCreuse.hpp"

#include <sstream>



using namespace std;





double matriceDouble::get(const int i, const int j)const 
{
    if(i>this->nbL || i<0 || j>this->nbC || j<0)
        throw IndexInvalide ("veuillez utilser des indices valides (fonction get) !");
    return this->mat[i*this->nbC+j];
    
    
}     
void matriceDouble::set(const double &x,const int i, const int j) 
{
    if(i>this->nbL || i<0 || j>this->nbC || j<0)
        throw IndexInvalide ("veuillez utilser des indices valides (fonction set) !");
    this->mat[i*this->nbC+j]=x;
    
}
string matriceDouble::toString() const 
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
Matrice<double>* matriceDouble::subMat(int i1,int i2, int j1,int j2)const 
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

Matrice<double>* matriceDouble::SomMat(const Matrice<double> &m1)const 
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

Matrice<double>* matriceDouble::MultMat(const Matrice<double> &m1)const 
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
/*Matrice<double>* matriceDouble::MDtoMC()const 
{
        if(this->estCreuse())
            throw InvalideCreuse ("Votre matrice n'est pas \"creuse\", conversion impossible !");
    matriceCreuse *mc = new matriceCreuse(this->nbElem);
    
    int cptj=0;
    mc->setAncienL(this->getL());
    mc->setAncienC(this->getC());
    for(int i=0;i<this->getL();i++)
    {
        for(int j=0;j<this->getC();j++)
        {
            if(this->get(i,j)!=0)
            {
                mc->set(this->get(i,j),0,cptj);
                mc->set(i,1,cptj);
                mc->set(j,2,cptj);
                cptj++;
            }
                
        }
    }
    return mc;
}*/

int matriceDouble::estCreuse()const 
{
    
    double cpt=0;

    for(int i=0;i<this->getL();i++)
    {
        for (int j = 0; j < this->getC(); j++)
        {
            if(this->get(i,j)==0)
                cpt++;
        }
        
    }
    
    if((cpt/this->getNbElem())*100>=90)
        return 1;//la matrice est creuse
    
    return 0;//la matrice n'est pas creuse
        

}





