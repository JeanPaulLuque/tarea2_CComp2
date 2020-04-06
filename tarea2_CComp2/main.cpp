#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	float monto;
	cout << "Ingrese un monto:" << endl;
	cin >> monto;
	
	int montoInteger = monto;
	float montoFloat;
	montoFloat = monto - montoInteger+0.01f;
	
	
	bool valido = true;

	if (monto < 0)
	{
		valido = false;
		cout << "monto Ingresado incorrecto" << endl;
	}
	
	//monedas
	int soles[8] = { 200,100,50,20,10,5,2,1 };
	float centimos[3] = { 0.50f,0.20f,0.10f };
	
	
	if (valido)
	{
		int cont = 0;
		float* pivotF = centimos;
		int* pivot = soles;
		for(;pivot<soles+8;pivot++)
		{
			while (montoInteger >= * pivot)
			{
				montoInteger -= *pivot;
				cont++;
			}
			if (*pivot < 10)
			{
				cout << "monedas de " << *pivot << " : " << cont << endl; 
			}else
				cout << "billetes de "<<*pivot <<" : "<< cont<<endl;
			cont = 0;
		}
		cont = 0;
		
		for (; pivotF < centimos + 3; pivotF++)
		{
			while (montoFloat >= * pivotF)
			{
				montoFloat -= *pivotF;
				cont++;
			}
			cout << "Monedas de " << *pivotF*100 << " : " << cont<<endl;
			cont = 0;
		}
		
	}
	return 0;
}