
#include <iostream>

using namespace std;

//MENU PRINCIPAL
void menuVector (void);
void menuArreglo (void);
void menuLista (void);
void menuPila (void);
void menuCola (void);
void menuArbol (void);


	int main(){
 	EMPEZAR: 
 		system("cls");

//DECLARAMOS VARIABLES//
	int opc;
	
//MENU PRINCIPAL DEL USUARIO

   	    
   	            cout << "\n\n\t\t\tMENU PRINCIPAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t1. VECTOR" << endl;
        cout << "\t2. ARREGLO" << endl;
        cout << "\t3. LISTAS" << endl;
        cout << "\t4. PILA" << endl;
        cout << "\t5. COLA" << endl;
        cout << "\t6. ARBOL BINARIO" << endl;
        cout << "\t0. SALIR" << endl;
        
        cout << "\n\tIngrese una opcion: ";
   	            cin>>opc;
   	    cout<<"\n";    
   	    switch (opc){
   	        case 1:
   			    menuVector();
 			break;
   	    	case 2:
   		    	menuArreglo();
 			break;
	 	    case 3:
   	 		    menuLista();
 			break;
   	    	case 4:
   		    	menuPila();
 			break;
 		    case 5:
   			    menuCola();
 			break;
   	    	case 6:
   		    	menuArbol();
 			break; 
 		    case 0:
 		    	cout<<"HASTA LUEGO:)";
 		    		exit(1);		
 		    break;
 		    default:
		 	    cout<<"Ingrese un numero Valido del Menu...\n"<<endl;
			     	system("pause");
  		}
 	    goto EMPEZAR;

   	return 0;
   }

