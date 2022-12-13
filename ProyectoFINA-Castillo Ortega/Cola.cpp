
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	char dato;
	Nodo *siguiente;	
};

 	void agregar_C(Nodo *&,Nodo *&,char);
 	bool vaciar_C(Nodo *);
 	void supri_C(Nodo *&,Nodo *&,char &);
 	
//SE MANDA A LLAMAR EL SUBMENU CON SU RESPECTIVA ACCCION	
void menuCola () {
	
//DECLARAMOS VARIABLES
 	int opc;
	int opc1;
 	char dato;
 	Nodo *frente = NULL;
 	Nodo *fin = NULL;
 		start:
	 		system("cls");
	 		

do{
			cout << "\n\n\t\t\tMENU COLA" << endl;
			cout << "\t\t\t--------------" << endl;
			cout<< "1. INGRESA UN CARACTER A LA COLA" << endl;
			cout<< "2. MOSTRAR COLA"<<endl;
			cout<< "3. SUBMENU COLA"<<endl;
			cout<< "INGRESA SU OPCION: ";
 			cin>>opc; 
			switch(opc){
			case 1: cout<<"\nINSERTE UN CARACTER:  ";cin>>dato;
			agregar_C(frente,fin,dato);
				break;
				
			case 2: cout<<"\nHISTORIAL DE LA COLA ";
								 	while(frente != NULL){
									 	supri_C(frente,fin,dato);
										 	if(frente != NULL){
									 			cout<<dato<<" , ";
							 				} else {
											 	cout<<dato<<".";
											}
									}
								 	cout<<"\n";
										system("pause");
						 		break;
							 	case 3: 
				 				break;
							}
			 				system("cls");
				} while(opc != 3);
				
//SUBMENU COLA
	cout << "\n\n\t\t\tSubMenu PILA" << endl;
    cout << "\t\t\t--------------" << endl;
	cout<<"\n\t1.- VOLVER A INICIAR LA PILA "<<endl;
	cout<<"\n\t0.- MENU PRINCIPAL"<<endl;
	cout << "____________________________________________________" << endl;
	cout<<"\n\tINGRESE LA OPCION NECESARIA: "; cin>>opc;
	switch(opc){
 	case 1:
		goto start;
			break;
			
 	case 0:
 		int main();
			break;	   	
	default:
		cout<<"Ingrese un numero Valido..."<<endl;	
				}
 		}
 		
 	//ACCIONES DE LA COLA
 	void agregar_C(Nodo *&frente,Nodo *&fin,char n){
		Nodo *nuevo_nodo = new Nodo();
		nuevo_nodo->dato = n;
		nuevo_nodo->siguiente = NULL;
			if(vaciar_C(frente)){
			frente = nuevo_nodo;
			} else {
				fin->siguiente = nuevo_nodo;
			}
		fin = nuevo_nodo;
	}
	bool vaciar_C(Nodo *frente){
		return (frente == NULL)? true : false; 
	}
		void supri_C(Nodo *&frente,Nodo *&fin,char &n){
			n = frente->dato;
			Nodo *aux = frente;
				if(frente == fin){
					frente = NULL;
					fin = NULL;
				} else {
					frente = frente->siguiente;
				}
			delete aux;
		}
