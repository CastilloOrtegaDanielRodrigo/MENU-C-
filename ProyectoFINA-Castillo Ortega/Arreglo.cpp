
#include<iostream>
#include<conio.h>

using namespace std;

//SE MANDA A LLAMAR EL SUBMENU CON SU RESPECTIVA ACCCION
void menuArreglo () {
 	start:
	system("cls");
	
//SE DECLARAN LAS VARIABLES
 	int numero[100];
 	int opc,n;		
		cout<<"INGRESE EL NUMERO DE ELEMNTOS DEL ARREGLO: ";cin>>n;
 		for(int i = 0; i<n; i++){
	 	cout<<"INGRESE UN NUMERO: ";cin>>numero[i]; //AQUI SE ALMACENA ELEMENTOS DEL ARREGLO
			} cout<<"\n";

//MUESTRAN ELEMTOS ASOCIADOS
 	for(int i=0;i<n;i++){
 		cout<<"      "<<i<<" -> "<<numero[i]<<endl;
			} cout<<"\n";
			
//SubmenuARREGLO
   	cout << "\n\n\t\t\tSubmenu ARREGLO" << endl;
    cout << "\t\t\t--------------" << endl;
	cout<<"\n\t1.- VOLVER A INICIAR EL ARREGLO "<<endl;
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
