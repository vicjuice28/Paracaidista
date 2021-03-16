#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<math.h>
using namespace std;

int op;
double raire, masa, graveda;
string gravity;
fstream gravedad ("gravedad.txt");



void Menu(){

    cout<<"Resolucion de problema de un paracaidista"<<endl;
    cout<<"¿Desea cambiar la gravedad?: \n 1.-Si \n 2.-No \n : ";
    cin>>op;

    switch (op) {
    case 1:
    // Cambiar la gravedad







        break;

    case 2:
    //Continuar con la establecida
        if(!gravedad.is_open()){
        gravedad.open("gravedad.txt", ios::in);
        }

        while(getline(gravedad, gravity)){
        
        }
        gravedad.close();

        graveda = stod(gravity);
        cout<<"\n"<<"La gravedad actual es: "<<graveda<<endl;

    break;



    default:
    cout<<"¡¡¡Digite una opcion valida!!!";
    Menu();
        break;
    }
    cout<<"\nDigite la resistencia al aire: "<<endl;  cin>>raire;
    cout<<"Digite la masa: "<<endl; cin>>masa;


}



int main () {

        Menu();
    return 0;
}