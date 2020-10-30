////Autor: XIMENA HUTCHINSON QUINTO///
/* Referencias: 
[1]Anónimo. (2020). Input/output file stream class. abril 18 , 2020, de cplusplus.com Sitio web: http://www.cplusplus.com/reference/fstream/fstream/ 
[2]Ma.E. (2020). How to convert string to int and int to string in C++. abril 18, 2020, de SysTutorials Sitio web: https://www.systutorials.com/convert-string-to-int-and-reverse/ 
[3] Anónimo. (2012). Heapsort. abril 18, 2020, de EcuRed Sitio web: https://www.ecured.cu/Heapsort
[4] Anónimo. (2020). Ordenamiento Radix. abril 18 , 2020, de Wikipedia Sitio web: https://es.wikipedia.org/wiki/Ordenamiento_Radix#Descripci%C3%
[5]González.J. (2019). Arrays, arreglos o vectores en C++. Uso, declaración y sintaxis de los vectores en C++. abril 17,2020, de ProgramarYa Sitio web: https://www.programarya.com/Cursos/C++/Estructuras-de-Datos/Arreglos-o-Vectores

*/

#include <iostream>
#include <fstream> //Para el manejo de archivos
#include <vector> //Para el manejo de vectores
#include <sstream>  // Para convertir un string en un int

using namespace std;

vector < vector <int> > Cubeta; //Declaramos el vector

#define MAX 100

class Arreglo
{
	int datos [MAX];
    int tamano = 0;

public: //Todos los métodos deben ser publicos para poder usarlos

	// Lee los datos de un archivo cuyo nombre recibe como parámetro

	void lecturaDatos(string archivo){

		ifstream texto(archivo.c_str()); //Para obtener el string del nombre del archivo que se desea abrir.
		string str;//Así se declara un string.
		
		if(texto.fail()) //Si no se pude abrir el archivo se mandará este mensaje.
		{
		cout<<"Error al abrir el archivo"<<endl;
		}
		else
		{
		  	getline(texto,str); //Esto lee lineas del  archivo.txt.
            stringstream primera(str); //Aqui se convierte un string a un entero.
            int n = 0;
            primera >> n; //Como la primera linea del archivo.txt tiene el tamaño 
						  //del arreglo esta se le asignrá a la variable tamano.
            for(int i = 0; i < n; i++){ //Este for hace que se lean todas la lineas 
            getline(texto,str);        //siguientes del archivo.txt.
            stringstream numeros(str); //Se convierten a int para poder utilizarlos en el arreglo.
            int num =0;
            numeros >> num;
           	datos[i] = num; //Los strings ya convertidos a int se meten en el arreglo.
			}
			tamano = n;
  		 //cout << tamano<<"\\\\\n";
        }
	}

	// Imprime el arreglo

   void imprimeArreglo(){
   for (int i=0 ; i<tamano; i++) ////Pasa por todos los datos del arreglo e imprime uno por uno separandolos con un salto de linea
   								//La variable tamano es el tamaño del arreglo
    cout << datos[i] << "\n";
   }

   // Ordena los elementos del arreglo de la clase usando el algoritmo Heap Sort.   
   void heapSort(){
   	
	// Contruccion del MaxHeap
		int j,paso,paso2,paso3; //Declaracion de variables que se utilizaran más adelante
	     for (int i = 1; i < tamano; i++)   //Para pasar por todos los valores del arreglo
	     {
	        // Si el hijo es más grande que el papá
	        if (datos[i] > datos[(i - 1) / 2]) //En el heap sort el padre es el elemento que este arriba de ti.
	        {									//Cada division del arbol binario es entre dos
	             j = i;

	            //Se intercambia la posicion del hijo y del padre si el hijo es mas grande que el padre

	            while (datos[j] > datos[(j - 1) / 2])
	            {

	               	paso = datos[j]; //La variable paso nos ayuda a guardar el valor de datos[j] para el intercambio
					datos[j] = datos[(j-1)/2];
					datos[(j-1)/2] = paso;	//Guardamos el valor el paso para que no se pierda esta informacion
					  j = (j - 1) / 2; //Para establecer el padre 

	            }
	        }
	    }
    	//HeapSort sacando el elemento mas grande y ocomodando el arbol de nuevo pero ahora hasta (n-1)
        for (int i = tamano - 1; i > 0; i--) //Para pasar por todos los valores del arreglo hasta (n-1)
   		{
	        //Cambiar el valor de la raiz con el ultimo valor del arreglo
	       	paso2 = datos[i]; //La variable paso2 nos ayuda a guardar el valor de datos[j] para el intercambio
			datos[i] = datos[0]; //El ultimo elemento del arbol se pasa a la raiz o sea 
			datos[0] = paso2;	//eL numero que esta al final del arreglo se pasa al principio.
				
	        // Hacer intercambios para mantener el mayor en la raiz
	        int j = 0, indice;
	       	 do{
	            indice = (2 * j + 1); //Para moverse en el árbol
	            //Si el hijo izquierdo es mas pequeño que el hijo derecho el index estara apuntando al hijo derecho
	            if (datos[indice] < datos[indice + 1] && indice < (i-1)) //*No entra al if si el valor del indice es mayor 
	            {														 //al numero de elementos que tiene el arreglo -1	
	            	  indice++;											//-1 ya que se redujo el arreglo al mover el ultimo 
				}														//elemento a la raiz
	            //Si el papá es mas chico que el hijo entonces se cambia el papá con el hijo para que el papá sea 
	            //el que contega el numero más grande 
	            if (datos[j] < datos[indice] && indice< i-1)
	            {
	            	paso3 = datos[j]; //La variable paso3 nos ayuda a guardar el valor de datos[j] para el intercambio
					datos[j] = datos[indice];
					datos[indice] = paso3;
				}
	            j = indice; //El valor de j ahora toma el valor del indice
	
	        } while (indice < i);
    	 }
	imprimeArreglo(); //Se manda a llamar a la funcion imprimir par ver el resultado del HeapSort
   }


   // Ordena los elementos del arreglo de la clase usando el algoritmo Radix Sort.
   
 void radixSort(){


	   	Cubeta.resize(10); //Para establecer el tamaño del vector
		int temp , c=0; // En el temp se almacenara el valor de las unidades decenas , centenas ..etc)
						//La variable c ayudara a guardar los datos del vector en el arreglo
		int div = 1;


		for(int i = 0 ; i<tamano; i++)
		{
			for(int j = 0; j<tamano; j++)
				{
					temp = (int)(datos[j]/div) % 10; //Primero se va de unidad a unidad y luego se obtiene el ultimo digito de este
					Cubeta[temp].push_back(datos[j]); //El valor del arreglo se insesrta en la posicion calculada anteriormente en temp
					//El push_back es un método para insertar elemento al final de un vector
				}

				div*=10;
			//Meter los valores del vector al arreglo
				for(int k=0; k<10;k++) //Este for es para pasar por todos los valores del vector
				{
					for(int l = 0;l<Cubeta[k].size();l++) //Este for es para ver si en un espacio del vector hay mas de un numero asignado
					{
						datos[c] = Cubeta[k][l];
						c++;
					}
					Cubeta[k].clear(); //Tenemos que limpiar el vector por que primero va con las unidades luego por las decenas , centenas , etc
				}

				c=0; //Tambien tenemos que regresar este contador a cero , para que en el siguiente for nos siga ayudando a meter los valores al arreglo
			}

			imprimeArreglo(); //Se manda a llamar a la funcion imprimir par ver el resultado del RadixSort
	}

};


