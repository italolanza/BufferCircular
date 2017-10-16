/*
	Biblioteca simples que implementa um buffer circular de double	
*/
using namespace std;

#ifndef BufferCircular_h
#define BufferCircular_h

class BufferCircular
{
	private: 
				bool 			BUFFER_IS_LOADED; 				//flag que diz se o buffer ja foi cheio pelo menos uma vez
				int				BUFFER_SIZE; 					//tamanho do buffer
				double*	 		cursor;		 					//aponta para o proximo espaço a ser preenchido
				double*			buffer_head; 					//aponta para posicao inicial do buffer
				double*			buffer_tail;					//aponta para a posição final do buffer
				double* 		buffer;						//variavel que recebe o ponteiro do buffer

	public:
				BufferCircular();
				BufferCircular(int);
				BufferCircular(double*,int);
				void	creatBuffer(int);
				void	setBuffer(double *);
				void 	setBufferSize(int);
				int 	getBufferSize();
				void 	setBufferHead(double*);
				void	setBufferTail(double*);
				double*	getBufferHead();
				double*	getBufferTail();
				void	setCursor(double*);
				double*	getCursor();
				bool	isBufferLoaded();
				void	addItem(double);
				double	getItem(int);
				double	getAverage();
				double 	getSum();
				void	resetBuffer();
				
};


#endif