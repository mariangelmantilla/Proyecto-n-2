#include <iostream>
#ifndef CodigoCesar_H
#define CodigoCesar_H

using namespace std;

class CodigoCesar{
	public:

		void setNumero(int n){
			numero = n;	
		}
		int getNumero(){
			return numero;
		}
		void setMensaje(string n){
			mensaje = n;
		}
		string getMensaje(){
			return mensaje;
		}
		
		void CodificarText(int n, string & cadena){
			for (int i = 0; i < cadena.length(); i++) { 
		        if (cadena[i] >= 'a' && cadena[i] <= 'z') { 
		            if (cadena[i] + n > 'z') { 
		                cadena[i] = 'a' - 'z' + cadena[i] + n - 1; 
		            } else if (cadena[i] + n < 'a') { 
		                cadena[i] = 'z' - 'a' + cadena[i] + n + 1; 
		            } else { 
		                cadena[i] += n; 
		            } 
		            
		        cadena[i]=cadena[i]-32;//esta linea se agrego para que cambiara las
		                               //minusculas a mayusculas
		        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') { 
		            if (cadena[i] + n > 'Z') { 
		                cadena[i] = 'A' - 'Z' + cadena[i] + n - 1; 
		            } else if (cadena[i] + n < 'A') { 
		                cadena[i] = 'Z' - 'A' + cadena[i] + n + 1; 
		            } else { 
		                cadena[i] += n; 
		            } 
		        } 
		    }
		    this->mensaje=cadena;
		}
		
		void DecodificarText(int n, string & cadena){
			CodificarText(n, cadena);
		}
	private:
		int numero;
		string mensaje;		
};

#endif
