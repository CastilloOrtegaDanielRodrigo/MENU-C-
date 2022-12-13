
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
//ESTE CODIGO DE REFERENCIAS ES: Programacion ATS: https://www.youtube.com/watch?v=W86jnUUY2zA&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh&index=107
using namespace std;

//DEFINICION DEL TIPO DE ELEMENTOS
typedef struct nodo_estudiante {
    char nombre[50];
    char carrera[50];
    int matricula[50];
    int edad;
} tipo_info;
 
//DEFINICION DE TIPO DE LISTA
typedef struct nodo_Lista {
    tipo_info info;
    struct    nodo_Lista *next;
} tipo_Nodo;

//DECLARAMOS VARIABLES
void nuevaLista (tipo_Nodo **lista);
tipo_Nodo *getNode (tipo_info elemento);
int listaVacia (tipo_Nodo *lista);
tipo_Nodo *insertarPrimero (tipo_Nodo **lista, tipo_info elemento);
void mostrarLista (tipo_Nodo *lista);
int eliminarNodo (tipo_Nodo **lista, tipo_Nodo *nodo);
tipo_Nodo *buscar (tipo_Nodo *lista, tipo_info elemento);

void menuLista () {
	
//DECLARAMOS VARIABLES
int opc;
tipo_Nodo *lista, *p, *nodo;
int opcion;
int eliminado;
tipo_info elemento;
nuevaLista (&lista);
	 	
	start:
	system("cls");
   	do {
     	printf("\n\n\t\t\MENU LISTA\n");
     	printf("\t--------------------------------");
     	printf("\n\t1. INGRESE DATOS A TU LISTA\n");
     	printf("\t2. VER DATOS INGRESADOS EN LA LISTA\n");
     	printf("\t3. ELIMINAR UN ELEMTO DE LA LISTA\n");
     	printf("\t4. REGRESAR AL SUBMENU\n");
     	printf("\nINGRESE SU OPCION: ");
     	scanf("%d", &opcion);
     	if (opcion == 1){
     		
//SOLICITAMOS DATOS DE LA LISTA
         	printf("¿CUAL ES TU NOMBRE?: ");
         	scanf ("%s", &elemento.nombre);
         	printf("¿EN QUE CARRERA VAS?: ");
         	scanf ("%s", &elemento.carrera);
         	printf("¿CUAL ES TU MATRICULA? ");
         	scanf ("%s", &elemento.matricula);
         	printf("INGRESE SU EDAD: ");
         	scanf ("%d", &elemento.edad);
         	
//INSETAMOS EL PRIMER LEMENTO DE LA LISTA
    p = insertarPrimero (&lista, elemento);
    if (p == NULL)
        printf("\nNO SE PUEDE INSERTAR LA LISTA.\n");
    else
        printf("\nElLEMENTO INSERTADO\n");
   		system("pause");
   		system("cls");
}
     		if (opcion == 2){
     			
// VER DATOS SOLICITADOS DE LA LISTA
    printf("HISTORIAL DE LA LISTA:\n");
    if (listaVacia (lista))
    printf("NO NINGUN ELEMENTO EN LA LISTA!!\n");
else
    mostrarLista (lista);
    system("pause");
    system("cls");
}

if (opcion == 3){
//ELIMINAR DATOS DE LAS LISTAS
printf("INGRESE EL NOMBRE CON EL QUE FUE SOLICITADO EN LA LISTA ");
scanf ("%s", &elemento.nombre);

//BUSCA LOS DATOS DE LA LISTA EN EL HISTORIAL
nodo = buscar (lista, elemento);

//ELIMINA LA LISTA DEL HISTORIAL
eliminado = eliminarNodo (&lista, nodo);
if (eliminado == -1){
    printf("\nELEMENTO %s NO SE ENCUENTRA EN LISTA", elemento.nombre);
    printf("\nNO SE PUEDE ELIMINAR\n");
}
    else
    printf("\nELEMNTO %s ELIMINADO...\n", elemento.nombre);
        system("pause");
         	system("cls");
        		}
} while (opcion != 4);	
 			//Submenu al final del codigo dentro de la funcion principal.
 			cout << "\n\n\t\t\tSubmenu LISTA" << endl;
    cout << "\t\t\t--------------" << endl;
	cout<<"\n\t1.- VOLVER A INICIAR LA LISTA "<<endl;
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
//Agregando las funciones que interactuan con el programa
void nuevaLista (tipo_Nodo **lista){
 	*lista = NULL;
}
 	tipo_Nodo *getNode (tipo_info elemento){
 	  	tipo_Nodo *p;
 	  	
//*ASIGNANDO MEMORIA DINAMICAMNETE SI HAY UN NODO
   	p = (tipo_Nodo *) malloc(sizeof(tipo_Nodo));
//SI OBTUVO UN (p) EN LA MEMORIA
   	if (p != NULL){
//SE GUARDA EL ELEMENTO(DATO) EN "info"
    p->info = elemento;
    p->next = NULL;
}
   		return p;
	}
int listaVacia (tipo_Nodo *lista){
 	if (lista == NULL)
//RETURN(1) = EXITO, ESO QUIERE DECIR QUE LA LISTA ESTA VACIA
      	return (1);
   	else
//RETURN(0) = ERROR, ESO QUIERE DECIR QUE LA LISTA NO ESTA VACIA
      	return (0);
}
tipo_Nodo *insertarPrimero (tipo_Nodo **lista, tipo_info elemento){
 	tipo_Nodo *p;
//SE OBTIENE UN NUEVO NODO
   	p = getNode(elemento);
//CUANDO SE OBTUVO EL NODO
	if (p != NULL){
//VERIFIVA SI LA LISTA ESTA VACIA
	if (listaVacia (*lista))
//ACTUALIZA LA NUEVA LISTA (p)
	*lista = p;
else {
/*Enlaza p antes del primero ("lista")*/
p->next = *lista;    	/*p apunta a "lista"*/
*lista = p;         /*actualiza "lista" con p*/
        }
	}
//SE VUELVE A RETONARNAR EL NUEVO NDO CREADO
return p;
}
 		void mostrarLista (tipo_Nodo *lista){
// SE GUARDA EL PRIMER NODO
   		tipo_Nodo *p;
 		p = lista;
//SE RECORRE LA LISTA
   			while (p != NULL){
      	printf("%s ,%s ,%s ,%d \n", p->info.nombre, p->info.carrera, 
        p->info.matricula, p->info.edad);
//AVANZA EL NODO
      	p = p->next;
   		}
printf("\n");
}

int eliminarNodo (tipo_Nodo **lista, tipo_Nodo *nodo){ tipo_Nodo *q;
//EL NODO ES DE ENTRADA NULL
if (nodo == NULL)
    return (-1);
    
//VERIFICA LA LISTA VACIA
if (listaVacia (*lista))
    return (-1);
   	else {
   		
//SI EL NODO DE ENTRADA ES EL PRIMERO
//ACTUALIZA LA LISTA CON EL SIGUIENTE NODO
 if (nodo == *lista) *lista = nodo->next;
    else {
    	
//BUSCA UN NODO ANTERIOR AL NODO
q = *lista;

//CONTINUA CON EL SIGUIENTE NODO
    while (q->next != nodo)q = q->next; q->next = nodo->next;
}
//LIBERA EL NODO DE LA MEMORIA
free (nodo);
//ELEMTTO ELIMINADO
   	return (1);
 	}
}
tipo_Nodo *buscar (tipo_Nodo *lista, tipo_info elemento){
 	tipo_Nodo *p;
 	p = lista; 
   		while (p != NULL){  
//SI ENCEUNTRA EL ELEMTO
     	if (strcmp(p->info.nombre, elemento.nombre)==0) 
         	return p;                						
     		else 
//AVANZA EL NODO
			p = p->next;
	}
return NULL;
}
