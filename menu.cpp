#include <iostream> 
#include <string.h> 
#include <fstream>
#include <sstream>
#include<cctype>
#include "CodigoCesar.h"
using namespace std; 
  
int main() { 
    
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
			do{
		    	fflush(stdin);
			    error=0;
			    cout<<"Ingrese el Nombre del archivo con el que desea trabajar\nOJO,si el archivo no existe, este sera creado.\n\n";
			    cout<<"El nombre no puede contener los siguientes caracteres:\n	<	>	?	:	|	/	*	\"	\n\nNombre del archivo:";
			    getline(cin, temporal);
			
			
				tam=temporal.size();
			    for(int x=0;x<tam;x++){
			    	if ((temporal[x]=='/' ||temporal[x]==':' || temporal[x]=='|' || temporal[x]=='<'|| temporal[x]=='?' || temporal[x]=='*'|| temporal[x]=='>'|| temporal[x]=='"') && error==0){
			    		cout<<"por favor, no coloques caracteres no validos para un archivo\n";	
			    		system("pause");
			    		system("cls");
						error=1;
					}
				}
		    
			}while(error==1);
		    Narchivo=strdup(temporal.c_str());
		    
		    do{
				error=0;
				cout << "Introduce el numero de desplazamiento deseado:"; 
			    cin >> numero; 
				tam=numero.size();
				    
				for(int x=0;x<tam;x++){
					
				    if(numero[x]<48 || numero[x]>57){
				    	error=1;
				    	cout<<"por favor, introduzca solo numeros enteros\n";
					}
					else{
						istringstream(numero)>>n;
						
					}
				}
			}while(error==1);
			CESAR.setNumero(n);
			system("cls");
			cout << "Introduce el mensaje a codificar\npara salirse,en la ultima linea escriba solamente :SACAME\nMensaje:" << endl; 
		    ofstream EntradaLimpiar(Narchivo,std::ios::trunc);
		    EntradaLimpiar.close();
			
			do{
			
			    getline(cin, cadena); 
			    
				if(cadena==""){
			    	cadena=" ";
				}
				if(cadena==":SACAME" || cadena==":sacame"){
		    		bandera=1;
					cadena="";
				}	
			
				CESAR.CodificarText((-CESAR.getNumero()), cadena); 
				CESAR.setMensaje(cadena);
			    ofstream Entrada(Narchivo,std::ios::app);
			    Entrada<<CESAR.getMensaje()<<endl;
			    Entrada.close();
		    
		    
		 	}while(bandera!=1);
		
		    
		
		    
		    ifstream Imprimir(Narchivo);
			std::string linea;
			cout<<"Mensaje Codificado:";
		 	while(getline(Imprimir,linea)) {
		  		std::cout << linea<<endl;
		 	}
		 	Imprimir.clear();
			Imprimir.close();
			system("pause");	
			system("cls");	
		    
		}
		
		if(opc=="2"){
			do{
		    	fflush(stdin);
			    error=0;
			    cout<<"Ingrese el Nombre del archivo que desea decodificar.\n\n";
			    cout<<"El nombre no puede contener los siguientes caracteres:\n	<	>	?	:	|	/	*	\"	\n\nNombre del archivo:";
			    getline(cin, temporal);
			
			
				tam=temporal.size();
			    for(int x=0;x<tam;x++){
			    	if ((temporal[x]=='/' ||temporal[x]==':' || temporal[x]=='|' || temporal[x]=='<'|| temporal[x]=='?' || temporal[x]=='*'|| temporal[x]=='>'|| temporal[x]=='"')&& error==0){
			    		
						
						cout<<"por favor, no coloques caracteres no validos para un archivo\n";	
			    		system("pause");
			    		system("cls");
						error=1;
					}
				}
		    
			}while(error==1);
			
		}
		if(opc=="3"){
			cout<<"Gracias por usar el programa \n\n";
		}
	
	}while(opc!="3");
