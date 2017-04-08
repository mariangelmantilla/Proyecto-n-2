#include <iostream> 
#include <string.h> 
#include <fstream>
#include <sstream>
#include<cctype>
#include "CodigoCesar.h"
using namespace std; 
  
int main() { 
    CodigoCesar CESAR;
	string cadena,temporal;
	char *Narchivo; 
    int n,bandera=0,tam,error=0;
	string  numero; 
    string opc;
    
	do{
	
		do{
			fflush(stdin);
		    error=0;
		    cout<<"Este es un programa para la codificacion y decodificacion de un archivo con el  codigo Cesar.\n\n";
		    cout<<"Seleccione la opcion que desea realizar:\n\n";
		    cout<<"1)Codificar un texto y guardarlo en un archivo.\n\n";
		    cout<<"2)Decodificar el texto de un archivo.\n\n";
		    cout<<"3)Salir.\n\nR:";
		    cin>>opc;
			
			tam=opc.size();
				if(tam>1 || opc[0]<49 || opc[0]>51){
				cout<<"por favor,seleccione solo una de las opciones ya establecidas"<<endl;
				error=1;
			}
	    system("pause");
	    system("cls");
		}while(error==1);
		
		if(opc=="1"){
			
		    
		}
		
		if(opc=="2"){
			
			
		}
		if(opc=="3"){
			cout<<"Gracias por usar el programa \n\n";
		}
	
	}while(opc!="3");
