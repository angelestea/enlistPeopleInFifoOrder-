#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

using namespace std;
int contabilizador=0;

struct Usuario{
    char nombre[50];
    int cedula;
    double pago;
    char ti_pago[50];
    int cliente;
};

struct datos{
    Usuario usu;
    datos *sig;
};
struct datos *c, *primero = NULL, *ultimo = NULL;

struct datos *nuevo_nodo();
void error();
void push(int & var);
void leer();
int colaVacia ();
void mostrarcola ();

int main (){
    char op;

    system("cls");
        cout<<"\n\n\t\t\t\t\t       ***************"<<endl;
        cout<<"\t\t\t\t\t       | Opening S.O |"<<endl;
        cout<<"\t\t\t\t\t       ***************"<<endl;
        for(int i = 0; i<=100;i++){
        string loading="";
        loading+=".";
        cout<<loading;
        Sleep(15);
    }

    do{
            fflush(stdin);
        system("cls");
        cout << "\n\t\t  ************" << endl;
        cout << "\t\t |Supermarket|" << endl;
        cout << "\t\t  ************" << endl;
        cout << "\n\n\t 1. Enlistar cliente a la cola " << endl;
        cout << "\n\n\t 2. Atender cliente" << endl;
        cout << "\n\n\t 3. Salir " << endl;
        do{
            cout<<"\n\t\tIngrese una opcion [1-3]: ";
            op=getche();//recibe inforamción directo del teclado
        }while(op<'1'||op>'3');
        switch(op){
            case '1':
                if(colaVacia()){
                contabilizador++;}
                push(*&contabilizador);
                break;
            case '2':
                leer();
        }
    }while(op!='3');
    cout<<"\n"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"\t\t     Exiting"<<endl;
    cout<<"*********************************************"<<endl;
    for(int i = 0;i<=45;i++){
        string exit = "";
        exit+=".";
        cout<<exit;
        Sleep(25);
    }
    cout<<"\n"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"\t\t  Exit complete"<<endl;
    cout<<"*********************************************"<<endl;
    getch();
    return 0;
}
void error(){
    perror("\n\n\t\t Memoria no reservada..");
    getch();
    exit(true);
}

struct datos *nuevo_nodo(){

    struct datos *c1;
    c1=new struct datos;

    if(!c1)
        error();

    return c1;
};

int colaVacia(){
    return (primero ==NULL);
};


void mostrarCola()
{
    int aten;
   c = primero;
      cout<<endl;
      while(c)
      {
          cout<<"\n";
          cout<<"\t\t\t***********************"<<endl;
          cout<<"\t\t\t********Cliente "<<c->usu.cliente<<"******"<<endl;
          cout<<"\t\t\t| Numero del cliente : |"<<c->usu.cliente<<endl;
         cout<<"\t\t\t| Nombre cliente      :|"<< c->usu.nombre <<endl;
         cout<<"\t\t\t| Cedula              :|"<< c->usu.cedula <<endl;
         cout<<"\t\t\t| Pago efectuado      :|"<< c->usu.pago <<endl;
         cout<<"\t\t\t| Tipo de pago        :|"<< c->usu.ti_pago <<endl;
          cout<<"\t\t\t***********************";
         c = c->sig;
      }
      cout<<endl;
}

void push(int &numeroCl)
{
    numeroCl=contabilizador;
   int cedula, asien, cl=1;
   double pago;
   char fin;
   fflush(stdin);
   do{
        fflush(stdin);
       system ("cls");
       if(colaVacia()){
        cout<<"\n\t Enlistar clientes";
       }else{
        cout<<"\n\t Clientes enlistados ";
       }
       mostrarCola();
       if(colaVacia()){delete(c);}
        c = new struct datos;
        fflush(stdin);
       cout<<"\n\t Ingrese el nombre: ";
       cin.getline(c->usu.nombre,50,'\n');
        fflush(stdin);
       cout<<"\n\t Ingrese la cedula: ";
       cin>>cedula;
        c->usu.cedula=cedula;
        cin.ignore();
        fflush(stdin);
       cout<<"\n\t Ingrese valor del pago: ";
       cin>>pago;
       c->usu.pago=pago;
       cin.ignore();
       cout<<"\n\t Tipo de pago efectuado: ";
       cin.getline(c->usu.ti_pago,50,'\n');
        cin.ignore();
       c->usu.cliente=numeroCl;
       c->sig = NULL;

       if(ultimo){
        ultimo->sig=c;
       }

       ultimo=c;

       if(!primero){
        primero=c;
       }
       cout<<"\n\t\t Desea ingresar mas clientes? (S/N)";
        fflush(stdin);
       fin=toupper(getche());
       numeroCl++;
   }while (fin == 'S');
}

void leer(){
    int cl;
    struct datos *aux;
    aux = primero;
    if(colaVacia()){
        system("cls");
        cl=0;
            cout<<"\n\t\t No existe clientela en cola"<<endl;
        getch();
    }else{
        system("cls");
        cout<<"\n\n\t Atendiendo al cliente "<<aux->usu.cliente;
        mostrarCola();
        primero = aux->sig;
        cout<<"\n\n\t Cliente "<<aux->usu.cliente<< " atendido"<<endl;
        delete(aux);
        if(!colaVacia()){
         cout<<"\n\n\t Cola restante: "<<endl;
        }else{
         cout<<"\n\n\t Cola atendida"<<endl;
        }
        mostrarCola();
    }
    getch();
}
