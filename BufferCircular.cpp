#include "BufferCircular.h"
//#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\Arduino.h"
//#include "iostream"
using namespace std;


//------------------------------------------Construtores-------------------------------------------------//
//construtor vazio
BufferCircular::BufferCircular(){}
//contrutor onde você passa o tamanho do buffer e ele é criado
BufferCircular::BufferCircular(int size)
{
	this->creatBuffer(size);
	this->setBufferSize(size);
	this->setBufferTail(this->buffer+(int((this->getBufferSize())-1)));
	this->setBufferHead(this->buffer);
	this->setCursor(this->buffer);
}
//contrutor onde você passa um buffer pronto
BufferCircular::BufferCircular(double* buffer, int size)
{
	this->setBuffer(buffer);
	this->setBufferSize(size);
	this->setBufferTail(this->buffer+(int((this->getBufferSize())-1)));
	this->setBufferHead(this->buffer);
	this->setCursor(this->buffer);
}

//-------------------------------------Construtores (FIM)-----------------------------------------------//
void	BufferCircular::creatBuffer(int size)
{
		this->buffer = new double[size];
}


void 	BufferCircular::setBufferSize(int size)
{
		this->BUFFER_SIZE = size;
}


void	BufferCircular::setBuffer(double* buffer)
{
		this->buffer = buffer;
}


int 	BufferCircular::getBufferSize()
{
		return this->BUFFER_SIZE;
}


void	BufferCircular::setCursor(double* pos)
{
		this->cursor = pos;
}


double* 	BufferCircular::getCursor()
{
		return this->cursor;
}

		
void 	BufferCircular::setBufferHead(double* pos)
{
		this->buffer_head = pos;
}


void	BufferCircular::setBufferTail(double* pos)
{
		this->buffer_tail = pos;
}


double* 	BufferCircular::getBufferHead()
{
		return this->buffer_head;
}


double* 	BufferCircular::getBufferTail()	
{
		return this->buffer_tail;
}	


bool	BufferCircular::isBufferLoaded()
{
		return this->BUFFER_IS_LOADED;
}


void	BufferCircular::addItem(double item)
{
		
		if(this->cursor == this->buffer + this->getBufferSize())
		{
			this->cursor = this->buffer;
			if(!(this->isBufferLoaded()))
			{
				this->BUFFER_IS_LOADED = true;
			}
		}

		*this->cursor = item;
		 this->cursor = this->cursor + 1;
}


double	BufferCircular::getItem(int pos)
{
	return *(this->buffer + pos);
}

double BufferCircular::getSum()
{
	double sum =0;
	if(this->isBufferLoaded())
	{		
		for(int i = 0; i < this->getBufferSize(); i++)
		{
				sum = sum + *(this->buffer + i);
		}	
	}
	else
	{
		int j;
		for(j=0 ; (this->buffer + j) != this->cursor; j++)
		{
			sum = sum + *(this->buffer + j);
		}
	}

	return sum;
}


double	BufferCircular::getAverage()
{
	double avg =0;
	
	if(this->isBufferLoaded())
	{
		for(int i = 0; i < this->getBufferSize(); i++)
		{
			avg = avg + this->getItem(i);
		}

		return (avg / this->getBufferSize());
	}
	else
	{
		int j;
		avg = this->getItem(0);
		for(j=1 ; (this->buffer + j) != this->cursor; j++)
		{
			avg = avg + this->getItem(j);
		}

		return (avg / j);		
	}

}


void	BufferCircular::resetBuffer()
{
	for (int k =0; k<10; k++)
	{
		*(this->buffer + k) = 0;
	}
	this->cursor = this->buffer;
	this->BUFFER_IS_LOADED = false;
}





