#include <cstdlib>
#include <iostream>
#include <cstring>
#include <sstream>
#include "matrice.hpp"
#include "matriceDouble.hpp"


using namespace std;

int main(){

    cout << "Hello World" << endl;
    cout << "execution main" << endl;
     
    matriceDouble m1(2,3,3);
    matriceDouble m2(2,3,2);
    matriceDouble m4(3,2,6);
    
    
    try 
    {
        Matrice<double> *m3 = m1.subMat(0,1,0,1);
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




     
    }
    catch(const IndexInvalide& e){cerr<<e.what()<<endl;}
    catch(const TailleInvalide& e){cerr<<e.what()<<endl;}
  

    
    
   cout<<"FIN"<<endl;
    return EXIT_SUCCESS;
}
