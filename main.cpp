#include <iostream>
#include<fstream>
#include<string>
#include<math.h>
#include "utils.hpp"
using namespace std;

int op, init, fin, paso, i;
double raire, masa, graveda;
double v = 0;
string gravity, newgrav;
ifstream gravedad ("gravedad.txt");
ofstream gravedad2("gravedad.txt");




void Menu(){

    cout<<"Resolucion de problema de un paracaidista"<<endl;
    cout<<"¿Desea cambiar la gravedad?: \n 1.-Si \n 2.-No \n : ";
    cin>>op;
    

    switch (op) {
    case 1:
    // Cambiar la gravedad
        cout<<"Escriba la nueva gravedad: "; cin>>newgrav;
       if(!gravedad2.is_open()){
           gravedad2.open("gravedad.txt", ios::out);
       }
       
        
        gravedad2 << newgrav;
        gravedad2.close();
        graveda = stod(newgrav);

        cout<<"La gravedad es: "<<graveda<<endl;






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
    cout<<"Digite en que segundo iniciara: "<<endl; cin>>init;
    cout<<"Digite en que segundo acabara: "<<endl; cin>>fin;
    cout<<"Digite cuantos pasos en tiempo hara: "<<endl; cin>>paso;





}




void Tabla(){
    system(CLEAN);
    cout<<"t,s"<<"\t"<<"v m/s"<<endl;
    cout<<"--------------"<<endl;
   for ( i = init; i <= fin; i+=paso){
        v = v+ (graveda - ((raire / masa) * v)) * paso;
        cout<<i<<"\t"<<v<<endl;



    }

   


}



int main () {
    //Abrir menu me borra contenido en archivo, así que se construye antes
        if(!gravedad2.is_open()){
           gravedad2.open("gravedad.txt", ios::out);
            }
       
        
        gravedad2 << 9.8;
        gravedad2.close();



        Menu();
        Tabla();
    return 0;
}