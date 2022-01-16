#include <cstdlib>
#include <iostream>
#include <cstring>
#include <sstream>
#include "matrice.hpp"

#include "matriceDouble.cpp"
#include "matriceCreuse.hpp"


using namespace std;

int main(){

    cout << "Hello World" << endl;
    cout << "execution main" << endl;
     
    matriceDouble m1(10,10,4);
    matriceDouble m2(10,10,1);

    matriceDouble m3(3,2,6);
    matriceDouble m4(2,3,2);

    matriceDouble TEST(10,10);
    
    
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
        cout<<"m1+m2 :"<<endl;
        cout<<m1+m2<<endl;

        cout<<"m3*m4 :"<<endl;
        cout<<m3*m4<<endl;

        cout<<"Matrice TEST :"<<endl;
        cout<<TEST<<endl; 
        TEST.set(3,1,1);
        if(TEST.estCreuse()==1)
            cout<<"La matrice est creuse"<<endl;
        else
            cout<<"La matrice n'est pas creuse"<<endl;
        
        cout<<"TEST apres set de 3 en 1,1 "<<endl;
        cout<<TEST<<endl;
        cout<<"subMat de TEST"<<endl;
        Matrice<double> *mDOUBLE1 = TEST.subMat(1,3,1,3);
        cout<<*mDOUBLE1<<endl;

        cout<<"TEST.MDtoMC"<<endl;
        Matrice<double> *mDOUBLE2 = TEST.MDtoMC();
        cout<<*mDOUBLE2<<endl;



                
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl;}
    catch(const TailleInvalide& e){cerr<<e.what()<<endl;}
    catch(const InvalideCreuse& e){cerr<<e.what()<<endl;}

    
    
   cout<<"FIN DU MAIN"<<endl;
    return EXIT_SUCCESS;
}
