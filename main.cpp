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
    matriceDouble mm(3,3);
   
    //double x = mm.get(2,2);
    //cout<<x<<endl;
    cout<<mm<<endl;
    cout<<"set a 5.3"<<endl;
    mm.set(5.3,0,2);
     cout<<mm<<endl;
    return EXIT_SUCCESS;
}
//PB fonction set 