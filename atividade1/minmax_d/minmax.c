/*
 * 1) Retornando múltiplos valores de uma função com estrutura
As vezes será necessário retornar múltiplos valores de uma função. Nessa situação é
possível usar uma estrutura e retornar os valores dentro de um ponteiro para essa estrutura.
Escreva uma função que deve retornar os valores mínimos e máximos dentro de um vetor.
Para isso utilize uma estrutura MinMax conforme abaixo:
typedef struct MinMax
{
 int min;
 int max;
}MinMax;
A função tem o seguinte protótipo:
MinMax *getMinMax(int * array, const int SIZE);
O argumento array contém um vetor de inteiros com tamanho SIZE e deve retornar um
ponteiro para uma estrutura alocada dinamicamente dentro da própria função. Lembre-se de
desalocar a memória alocado ao final da função main (que deve ser escrita por você e conter
a declaração de um vetor e a chamada a função getMinMax.
Para verificar se o código possui vazamento de memória, utilize a ferramente valgrind:
valgrind --leak-check=full --show-leak-kinds=all ./main
*/


#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

typedef	struct{
	int	min;
	int	max;
}MinMax;

MinMax	*getMinMax(int	*array,	const	int	SIZE){
	if(SIZE<=0)
		return	NULL;

	MinMax	*result=(MinMax	*)malloc(sizeof(MinMax));
	if(result==NULL)
		return	NULL;
	
	result->min=array[0];
	result->max=array[0];

	for(int	i=1;	i<SIZE;	i++){
		if(array[i]<result->min)
			result->min=array[i];
		if(array[i]>result->max)
			result->max=array[i];
	}
	
	return	result;
}

int	main(int	argc,	char	**argv){
	int	*x;
	int	*y=(int	*)	malloc(sizeof(int)*10);

	srand(time(NULL)); // inicializa o gerador de numeros aleatorios
	rand()%10; // gera um numero aleatorio entre 0 e 9

	MinMax	*minMax=getMinMax(y,10);
	if(minMax!=NULL){
		printf("Min: %d, Max: %d\n",minMax->min, minMax->max);
		free(minMax);
	}else
		printf("erro");

	printf("Programa iniciado!\n");

	getMinMax(NULL,	0);

	return	0;
}
