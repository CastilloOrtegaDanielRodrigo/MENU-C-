
#include<iostream>
#include<conio.h>

using namespace std;

//SE MANDA A LLAMAR EL SUBMENU CON SU RESPECTIVA ACCCION
void menuVector () {
 	start:
	 	system("cls");
	 	
//SE DECLARAN LAS VARIABLES
	int matriz[100][100], fila,columna;
	int opc,n;
	 	printf("INGRESA EL NUMERO DE FILAS:  ");
 		scanf("%d", &fila);
 		printf("INGRESA EL NUMERO DE COLUMNAS:  ");
		scanf(" %d", &columna);
		
//SE ALMACENA EL VECTOR
	for (int i=0;i<fila;i++){
	for(int j=0;j<columna;j++){
		printf("INGRESA UN VALOR [%d] [%d]:" ,i,j);
 		scanf(" %d", &matriz [i][j]);
 	}
}	
//SE IMPRIME
 	printf("\n");
 	for (int i=0;i<fila;i++){
	for(int j=0;j<columna;j++){
 		printf("   %d",matriz[i][j]);
	}
 	printf("\n");
}


//SubmenuVECTOR 
   	cout << "\n\n\t\t\tSubmenu VECTOR" << endl;
    cout << "\t\t\t--------------" << endl;
	cout<<"\n\t1.- VOLVER A INICIAR EL VECTOR "<<endl;
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
