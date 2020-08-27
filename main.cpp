#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TAM = 100;

void ingresar(int Arreglo[TAM], int t);
string interpolacion (int Arreglo[TAM], int t);
void imprimir(int Arreglo[TAM], int t);


int main() {
  ofstream ordenar;
  string encontrado;
  int arreglo[TAM], tamanio, i;  
  ordenar.open("Interpolacion", ios::out);
  if (ordenar.is_open())
  {
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamanio;
    ingresar(arreglo, tamanio);
    imprimir(arreglo, tamanio);
    ordenar << "Arreglo ingresado: ";
    for (i = 0; i < tamanio; i++)
    {
      ordenar << arreglo[i] << " ";
    }
    ordenar << '\n';
    encontrado = interpolacion (arreglo, tamanio);
    ordenar << encontrado;
  }
  else
  {
    cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
  }
  ordenar.close();
  return 0;
}

void ingresar(int Arreglo[TAM], int t)
{
  for (int i = 0; i < t; i++)
  {
    cout << "Ingrese el valor al arreglo: ";
    cin >> Arreglo[i];
  }
}

void imprimir(int Arreglo[TAM], int t)
{
  for (int i = 0; i < t; i++)
  {
    cout << Arreglo[i] << " ";
  }
}

string interpolacion (int Arreglo[TAM], int t)
{
	int primero=0;
	int ultimo = t-1;
	int medio;
	int n;
	int contador=0;
  string resultado;
	cout<<"\nIngrese el elemento a buscar: ";
  cin>>n;
	while(Arreglo[primero]!=n&&contador<t)
	{
    medio = primero + ((n-Arreglo[primero])*(ultimo -primero))/(Arreglo[ultimo]-Arreglo[primero]);

		if(Arreglo[medio]<n)
		{
			ultimo =medio+1;
		}
		else if (Arreglo[medio]>n)
		{
			ultimo =medio-1;
		}
		else 
		{
			primero =medio;
		}
		contador++;
		break;
	}
	if (Arreglo[primero]==n)
	{
    resultado = "Elemento encontrado";
	}
	else
	{
		resultado = "Elemento no encontrado";
	}
  return resultado;
}