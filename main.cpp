#include <cstdlib>
#include <iostream>
#include <cstring>
#include <sstream>

#include "matrice.hpp"
#include "matriceDouble.hpp"
#include "matriceCreuse.hpp"
#include "exceptionMat.hpp"

using namespace std;

int main(){

    cout<<"--------------- Manipulation de matrices en C++ ---------------"<<endl<<endl;
    
    //Matrices double de même dimensions pouvant être additionées 
    matriceDouble m1(10,10,4);
    matriceDouble m2(10,10,1);

    //Matrices double de dimensions compatibles pour un produit de matrices
    matriceDouble m3(3,2,6);
    matriceDouble m4(2,3,2);
    
    //matrice pouvant être additionnée avec m3 mais pas m4
    matriceDouble m5(3,2,8);

    matriceDouble m6(10,10,0);




//--------------------------SOMME--------------------------//

    cout<<"--------------------------SOMME--------------------------"<<endl<<endl;

    //SOMME DE 2 MATRICES : CAS ERREUR
    try{
        cout<<"m1+m3"<<endl;
        cout<<m1+m3<<endl;
        //erreur les 2 matrices ne sont pas de la meme taille
    }
    catch(const TailleInvalide& e){cerr<<e.what()<<endl<<endl;}

    //SOMME DE 2 MATRICES : CAS FONCTIONNEL
    try{
        cout<<"m1+m2"<<endl;
        cout<<m1+m2<<endl;
    }
    catch(const TailleInvalide& e){cerr<<e.what()<<endl<<endl;}

    //SOMME DE 2 MATRICES : CAS FONCTIONNEL
    try{
        cout<<"m3+m5"<<endl;
        cout<<m3+m5<<endl;
    }
    catch(const TailleInvalide& e){cerr<<e.what()<<endl<<endl;}



//--------------------------PRODUIT--------------------------//

    cout<<"--------------------------PRODUIT--------------------------"<<endl<<endl;

    //produit DE 2 MATRICES : CAS ERREUR
    try{
        cout<<"m2*m4"<<endl;
        cout<<m2*m4<<endl;
        //erreur les 2 matrices ne sont pas de la meme taille
    }
    catch(const TailleInvalide& e){cerr<<e.what()<<endl<<endl;}

    //produit DE 2 MATRICES : CAS FONCTIONNEL
    try{
        cout<<"m3*m4"<<endl;
        cout<<m3*m4<<endl;
    }
    catch(const TailleInvalide& e){cerr<<e.what()<<endl<<endl;}
    



//------------------MODIFICATION DE MATRICE------------------//

    cout<<"------------------MODIFICATION DE MATRICE------------------"<<endl<<endl;

    //modification d'un élement : CAS ERREUR
    try{
        cout<<"affectation de 8 en (-1,4) de la matrice m1"<<endl;
        m1.set(8,-1,4);
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}

    //modification d'un élement : CAS FONCTIONNEL
    try{
        cout<<"affectation de 8 en (4,4) de la matrice m1"<<endl<<endl;
        m1.set(8,4,4);
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;} 



    //récupération d'un élément : CAS ERREUR
    try{
        cout<<"élément (4,12) de la matrice m1"<<endl;
        cout<<m1.get(4,12)<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;} 
    
    //récupération d'un élément : CAS FONCTIONNEL
    try{
        cout<<"élément (4,4) de la matrice m1"<<endl;
        cout<<m1.get(4,4)<<endl<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;} 

    //somme de 2 matrices après modificatin d'un élément: CAS FONCTIONNEL
    try{
        cout<<"m1+m2 après modification d'un élément de m2"<<endl;
        cout<<m1+m2<<endl;
    }
    catch(const TailleInvalide& e){cerr<<e.what()<<endl<<endl;}



    //modification d'un élement : CAS FONCTIONNEL
    try{
        cout<<"affectation de 8 en (1,2) de la matrice m3"<<endl<<endl;
        m3.set(8,1,2);
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}

    try{
        cout<<"élément (1,2) de la matrice m3"<<endl;
        cout<<m3.get(1,2)<<endl<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}

    //produit DE 2 MATRICES : CAS FONCTIONNEL
    try{
        cout<<"m3*m4 après modification d'un élément de m3"<<endl;
        cout<<m3*m4<<endl;
    }
    catch(const TailleInvalide& e){cerr<<e.what()<<endl<<endl;}




//------------------SUBDIVISION DE MATRICE-------------------//

    cout<<"------------------SUBDIVISION DE MATRICE-------------------"<<endl<<endl;

    //subdivision d'une matrice : CAS ERREUR
    try{
        cout<<"subMat de m1 avec i1=-5, i2=7 j1=4 et j2=7"<<endl;
        Matrice<double> *mDOUBLE1 = m1.subMat(-5,7,10,7);
        cout<<*mDOUBLE1<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}

    //subdivision d'une matrice : CAS ERREUR
    try{
        cout<<"subMat de m1 avec i1=4, i2=7 j1=4 et j2=10"<<endl;
        Matrice<double> *mDOUBLE1 = m1.subMat(4,7,4,10);
        cout<<*mDOUBLE1<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}

    //subdivision d'une matrice : CAS FONCTIONNEL
    try{
        cout<<"subMat de m1 avec i1=4, i2=7 j1=4 et j2=7"<<endl;
        Matrice<double> *mDOUBLE1 = m1.subMat(4,7,4,7);
        cout<<*mDOUBLE1<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}



//----------------------MATRICE CREUSE----------------------//

    cout<<"----------------------MATRICE CREUSE----------------------"<<endl<<endl;

    try{
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                m1.set(0,i,j);
            }
        }
        cout<<"Nouvelle matrice m1"<<endl;
        cout<<m1<<endl; 

        if(m1.estCreuse()==1)
            cout<<"La matrice m1 est creuse"<<endl<<endl;
        else
            cout<<"La matrice m1 n'est pas creuse"<<endl<<endl;

        cout<<"m1.MDtoMC mD2 :"<<endl;
        Matrice<double> *mDOUBLE3 = m1.MDtoMC();
        cout<<*mDOUBLE3<<endl;

    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}
    catch(const InvalideCreuse& e){cerr<<e.what()<<endl<<endl;}
    

    try{
        cout<<"Matrice m6 :"<<endl;
        cout<<m6<<endl; 
        if(m6.estCreuse()==1)
            cout<<"La matrice est creuse"<<endl<<endl;
        else
            cout<<"La matrice n'est pas creuse"<<endl<<endl;
        m6.set(3,3,3);
        m6.set(3,5,7);
        m6.set(3,3,1);
        cout<<"m6 apres set de 3 en (3,1),(3,3) et (5,7) "<<endl;
        cout<<m6<<endl;
        if(m6.estCreuse()==1)
            cout<<"La matrice est creuse"<<endl<<endl;
        else
            cout<<"La matrice n'est pas creuse"<<endl<<endl;
        cout<<"subMat de m6"<<endl;
        Matrice<double> *mDOUBLE1 = m6.subMat(1,3,1,3);
        cout<<*mDOUBLE1<<endl;

        cout<<"m6.MDtoMC mD2 :"<<endl;
        Matrice<double> *mDOUBLE2 = m6.MDtoMC();
        cout<<*mDOUBLE2<<endl;

        cout<<"m6.MCtoMD"<<endl;
        cout<<*mDOUBLE2->MCtoMD()<<endl;           
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl;}
    catch(const TailleInvalide& e){cerr<<e.what()<<endl;}
    catch(const InvalideCreuse& e){cerr<<e.what()<<endl;}

    
    cout<<"FIN DU PROGRAMME"<<endl;
    return EXIT_SUCCESS;
}