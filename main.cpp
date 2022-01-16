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

    matriceDouble TEST(10,10,0);



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
        cout<<"subMat de m1"<<endl;
        Matrice<double> *mDOUBLE1 = m1.subMat(-5,7,10,7);
        cout<<*mDOUBLE1<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}

    //subdivision d'une matrice : CAS ERREUR
    try{
        cout<<"subMat de m1"<<endl;
        Matrice<double> *mDOUBLE1 = m1.subMat(4,7,4,10);
        cout<<*mDOUBLE1<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}

    //subdivision d'une matrice : CAS FONCTIONNEL
    try{
        cout<<"subMat de m1"<<endl;
        Matrice<double> *mDOUBLE1 = m1.subMat(4,7,4,7);
        cout<<*mDOUBLE1<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl<<endl;}



    try 
    {
         /* Matrice<double> *m3 = m1.subMat(0,1,0,1);
        cout<<"somme m1 m2"<<endl;
        cout<<"m1"<<endl;
        cout<<m1<<endl;
        cout<<"m2"<<endl;
        cout<<m2<<endl;
        cout<<"m3"<<endl;
        cout<<*m3<<endl;
        cout<<"m4"<<endl;
        cout<<m4<<endl;


        cout<<"m1+m2"<<endl;
        cout<<m1+m2<<endl;

        
        
        cout<<"m1*m4"<<endl;
        cout<<m1*m4<<endl;
        

        cout<<"sub de m1 (m3)"<<endl;
        cout<<*m3<<endl;

        TEST.set(3,1,1);
        TEST.set(3,0,1);

        cout<<TEST<<endl;
        
        
        if(TEST.estCreuse()==1)
            cout<<"La matrice est creuse"<<endl;
        else
            cout<<"La matrice n'est pas creuse"<<endl;

        TEST.MDtoMC();
        cout<<TEST<<endl;*/
        
        cout<<"Matrice TEST :"<<endl;
        cout<<TEST<<endl; 
        //TEST.set(3,1,1);
        //TEST.set(3,2,2);
        TEST.set(3,3,3);
        if(TEST.estCreuse()==1)
            cout<<"La matrice est creuse"<<endl;
        else
            cout<<"La matrice n'est pas creuse"<<endl;
        
        cout<<"TEST apres set de 3 en 1,1 "<<endl;
        cout<<TEST<<endl;
        cout<<"subMat de TEST"<<endl;
        Matrice<double> *mDOUBLE1 = TEST.subMat(1,3,1,3);
        cout<<*mDOUBLE1<<endl;

        cout<<"TEST.MDtoMC mD2 :"<<endl;
        Matrice<double> *mDOUBLE2 = TEST.MDtoMC();
        cout<<*mDOUBLE2<<endl;

        cout<<"TEST.MCtoMD"<<endl;
        cout<<*mDOUBLE2->MCtoMD()<<endl;
       


                
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl;}
    catch(const TailleInvalide& e){cerr<<e.what()<<endl;}
    catch(const InvalideCreuse& e){cerr<<e.what()<<endl;}

    //SOMME DE 2 MATRICES : CAS FONCTIONNEL
    try{
        cout<<"m1+m2"<<endl;
        cout<<m1+m2<<endl;
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl;}
    catch(const TailleInvalide& e){cerr<<e.what()<<endl;}


    //SOMME DE 2 MATRICES : CAS ERREUR
    try{
        cout<<"m1+m2"<<endl;
        cout<<m1+m3<<endl;
        //erreur les 2 matrices ne sont pas de la meme taille
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl;}
    catch(const TailleInvalide& e){cerr<<e.what()<<endl;}
    
   cout<<"FIN DU MAIN"<<endl;
    return EXIT_SUCCESS;
}
