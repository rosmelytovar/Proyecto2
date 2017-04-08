#include <iostream> 
#include <string.h>
#include <fstream>


using namespace std; 
 
class cesar
{
	public:

		void setNum(int n){
			num= n;	
		}
		int getNum(){
			return num;
		}
		void setTexto(string n){
			texto = n;
		}
		string getTexto(){
			return texto;
		}
		
		void setCodifica(int n, string & cadena) { 
		    for (int i = 0; i < cadena.length(); i++) { 
		        if (cadena[i] >= 'a' && cadena[i] <= 'z') { 
		            if (cadena[i] + n > 'z') { 
		                cadena[i] = 'a' - 'z' + cadena[i] + n - 1;
		            } else if (cadena[i] + n < 'a') { 
		                cadena[i] = 'z' - 'a' + cadena[i] + n + 1; 
		            } else { 
		                cadena[i] += n; 
		            } 
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
		    this->texto=cadena;
		}
		
		void setDescodifica(int n, string & cadena){ 
    		setCodifica(-n, cadena); 
		}
		

	private:
		int num;
		string texto;		
};
