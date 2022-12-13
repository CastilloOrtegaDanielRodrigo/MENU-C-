
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

//DECLARAMOS VARIABLES
struct Nodo{
 	int dato;
 	Nodo *der;
 	Nodo *izq;	
 	Nodo *padre;
};

Nodo *crearNodo(int, Nodo *);
	void insertarNodo(Nodo *&, int, Nodo *);
	void mostrarArbol(Nodo*, int);
	bool busqueda(Nodo *,int);
	void eliminar(Nodo *,int);
	void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
	void reemplazar(Nodo *, Nodo *);
	void destruirNodo(Nodo *);
Nodo *arbol = NULL;
 	void menuArbol () {
//DECLARAMOS VARIABLES
	int opc;
	int dato;
	int opcion, contador=0;
	 			start:
	 				system("cls");

do{
 				cout << "\n\n\t\t\tMENU COLA" << endl;
				cout << "\t\t\t--------------" << endl;
 				cout <<"\n\t1. INGRESAR DATOS AL ARBOL"<< endl;
	 			cout <<"\n\t2. MOSTRAR ARBOL"<< endl;
	 	    	cout <<"\n\t3. BUSCAR RAMAS EN EL ARBOL"<< endl;
	  	    	cout <<"\n\t4. ELIMINAR RAMAS DEL ARBOL"<< endl;	    	
	  	    	cout <<"\n\t5.SUBMENU ARBOL BINARIO"<< endl;	  	    	
	 			cout <<"\n\tIngrese opcion: ";
 					cin>>opcion;
					 	switch (opcion){
	case 1: cout<<"\nINGRESE UN NUMERO: ";
	cin>>dato;
//INSERTA UN NODO AL ARBOL
	insertarNodo(arbol,dato, NULL); //inserta un nodo
		cout<<("\n");
		system("pause");
	break;	

	case 2: cout<<"ARBOL COMPLETO \n\n";
//MUESTRA EL ARBOL
	mostrarArbol(arbol,contador);
			cout<<"\n";
			system("pause");
	break;
	
	case 3: cout<<"l\nINGRESE EL ELEMNTO A BUSCAR \n\n";
	cin>>dato;
//BUSCA RAMAS EN EL ARBOL
	if(busqueda(arbol,dato)==true){
	cout<<"RAMA "<<dato<<" A SIDO ENCONTRADA\n";
	}else{
		cout<<"\nRAMA NO ENCONTRADA\n";
		}
			system("pause");
				cout<<"\n";		 		
	break;	
	
	case 4: cout<<"DIGITE UN NUMERO DE LA RAMA PARA ELIMINAR: \n\n";
		cin>>dato;
		
//ELIMINA EL NUMERO DE LA RAMA
		eliminar(arbol, dato);
		cout<<"\n";
		system("pause");
	break;						 			
}	
			system("cls");	
			} while (opcion != 5) ;
			
//SUBMENU ARBOL BINARIO

   	cout << "\n\n\t\t\tSubMenu ARBOL BINARIO" << endl;
    cout << "\t\t\t--------------" << endl;
	cout<<"\n\t1.- VOLVER A INICIAR EL ARBOL BINARIO "<<endl;
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
//ACCIONES QUE REALIZA EL ARBOL
 		Nodo *crearNodo(int n, Nodo *padre){
			Nodo *nuevo_nodo = new Nodo();
	 		nuevo_nodo->dato=n;
 			nuevo_nodo->der=NULL;
 			nuevo_nodo->izq=NULL;	
	 		nuevo_nodo->padre=padre;	
				return nuevo_nodo;
	 	}
//FUNCIONES PARA INSERTAR ELEMTOS EN UN ARBOL
 	void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
//SI EL ARBOL ESTA VACIO	
		if(arbol==NULL){ 
		Nodo *nuevo_nodo=crearNodo(n, padre);
// SI EL ARBOL TIENE UN NODO MAS
		arbol =  nuevo_nodo;
	 	} else { 
//OBTENER VALOR DE LA RAIZ
	int valorRaiz = arbol->dato;
		if(n<valorRaiz){ 
//SI EL ELEMNTO ES MENOR QUE LA RAIZ, SE INSERTA A LA IZQUIARDA
			insertarNodo(arbol->izq, n, arbol);
	 	} else {
// SI EL ELEMETO ES MAYOR A LA RAIZ, SE INSERTA A LA DERECHA
			insertarNodo(arbol->der, n, arbol);
		}
	}
}
 //MOSTRAR EL ARBOL BNARIO
	void mostrarArbol(Nodo *arbol, int cont){
		if(arbol == NULL){
			return;
			} else {
				mostrarArbol(arbol->der, cont+1);
			for(int i=0; i<cont; i++){
				cout<<"   ";
		}
		 	cout<<arbol->dato<<endl;
			mostrarArbol(arbol->izq,cont+1);
	}
}
//BUSCAR UN ELEMTO EN EL ARBOL
 	bool busqueda(Nodo *arbol, int n){
 		if(arbol == NULL){
 			return false;	
 		} else if(arbol->dato==n){
 				return true;
		}else if (n<arbol->dato){
 				return busqueda(arbol->izq,n);
		} else {
				return busqueda(arbol->der, n);
 	}	
}
 //ELIMINA UN NODO
 	void eliminar(Nodo *arbol, int n){
 		if(arbol==NULL){
 			return;
		} else if(n<arbol->dato){
			eliminar(arbol->izq,n);
		} else if (n > arbol->dato){
			eliminar(arbol->der,n);
		} else {
			eliminarNodo(arbol);
 	}	
}
 		Nodo *minimo(Nodo *arbol){
 			if(arbol == NULL){
 				return NULL;
}
			if(arbol->izq){
				return minimo(arbol->izq);
				} else {
				return arbol;
	}
}
//REEPLAZA DOS NODOS
 	void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
 		if(arbol->padre){
			if(arbol->dato=arbol->padre->izq->dato){
				arbol->padre->izq=nuevoNodo;	
 			} else if(arbol->dato == arbol->padre->der->dato){
				arbol->padre->der =nuevoNodo;
}
			} if(nuevoNodo){
 			nuevoNodo->padre=arbol->padre;		
 	}
}
 //DESTRIR UN NODO
 	void destruirNodo(Nodo *nodo){
 		nodo->izq =NULL;
		nodo->der = NULL;
		delete nodo;	
}
 //FUNCION PARA IMPRIMIR UN NODO CONTRARIO
 	void eliminarNodo(Nodo *nodoEliminar){
 		if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato=menor->dato;
		eliminarNodo(menor);
	} else if (nodoEliminar->izq){
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);	
	} else if(nodoEliminar->der){
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
 	} else {
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}
