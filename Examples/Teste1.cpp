/*
	14/08/2017 - Autor: Italo Lanza
	Programa para testar os métodos da classe BufferCircular
*/


#include "C:\Users\Italo Lanza\Documents\Arduino\libraries\BufferCircular\BufferCircular.h"
#include "C:\Users\Italo Lanza\Documents\Arduino\libraries\BufferCircular\BufferCircular.cpp"
#include <iostream>
using namespace std;


int main()
{
	BufferCircular buffer(10); // cria o buffer
	cout << "Tamanho do buffer: " << buffer.getBufferSize() << endl; //imprime o tamanho do buffer
	for(int i =0; i <10; i++) //laço para encher o buffer;
	{
		buffer.addItem(i);		
	}
	for(int i =0; i <10; i++) // laço para imprimir todos os itens no buffer
	{
		cout << "Item " << i << " :" << buffer.getItem(i) << endl;	
	}

	cout << "Media : "<< buffer.getAverage() << endl; //imprime a média do itens contido no buffer
	cout << "Buffer resetado" << endl; //reseta o buffer
	buffer.resetBuffer();
	buffer.addItem(1);
	buffer.addItem(2);
	cout << "Media : "<< buffer.getAverage() << endl;
	for(int i =0; i <10; i++)
	{
		cout << "Item " << i << " :" << buffer.getItem(i) << endl;	
	}
	//System("pause");
 	return 0;
 }
