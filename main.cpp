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
int main() 
{	cesar Texto;
    string cadena,temp; 
    int n=0,opc=0,bandera=0;
    ofstream myfile;
	do{
		system("cls");
		cout<<"\n ********************* " << endl;
		cout<<"\n *        MENU       * " << endl;
		cout<<"\n * 1. Codificar      * " << endl;
		cout<<"\n * 2. Decodificar    * " << endl;
		cout<<"\n * 3. Salir          * " << endl;
		cout<<"\n * Digite su opcion  * " << endl;
	    cout<<"\n ********************* " << endl;
		cin>>opc;
		fflush(stdin);
		system("cls");
		if (opc==1){ //CODIFICAR
			cout << "Ingrese el mensaje a codificar" << endl;
			cout << "estimado usuario al finalizar su mensaje debe escribir" <<endl;
			cout << ":sacame para continuar el proceso"<<endl; 
			cout << "es indiferente si es mayuscula o minuscula"<<endl; 
			do{
				
		    	getline(cin, temp);
		    	
		    	if(temp==":SACAME" || temp==":sacame"){
		    		bandera=1;
		    		temp="";
				}
				cadena=cadena+temp+'\n';
		    }while(bandera==0);
		    
		    for (int x=0; x < cadena.length(); x++){
		    	if (cadena[x]>96 && cadena[x]<123){
		    		cadena[x]=cadena[x]-32;
				}
			}	    	
	    	cout << "Ingrese el numero de desplazamiento deseado" << endl; 
	    	cin >> n;
	    	Texto.setNum(n);
	    	Texto.setCodifica(-n, cadena);
	    	cout << Texto.getTexto() << endl;
	    	system ("pause");
	    	
	    	 myfile.open("archivo", ios::trunc);
	    	 myfile << Texto.getTexto();
	    	 myfile.close();
		}
		if(opc==2){
			cout << "Este es el texto codificado\n" << endl; 
			ifstream archivoo ("archivo");
		    string tex;
		    while(getline(archivoo,tex)){
		    	cout << tex << endl;
			} 
			archivoo.clear();
			archivoo.seekg (0, ios::beg);
			fflush(stdin);
			cout << "\nComiense a Decodificar:\n" << endl; 
		    cout << "Introduce el numero de desplazamiento deseado" << endl; 
		    cin >> n;
		    while(getline(archivoo,tex)){
		    	Texto.setDescodifica(-n, tex);
				cout << Texto.getTexto() << endl;
				system ("pause");
			}
			
		    archivoo.close();
	}
	           if(opc==3){
					system("cls");
					return 0;
					system("pause");
				 }
				
	
	 
	  } while(opc!='3');
       
       system("PAUSE");
      
}

