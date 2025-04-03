/*2) Escreva um programa em C para permitir a ordenação de vetores.
Exemplo de entrada:
Elementos do vetor de entrada: 10 -1 0 4 2 100 15 20 24 -5
Exemplo de saída:
Vetor ordenado em ordem ascendente: -5, -1, 0, 2, 4, 10, 15, 20, 24, 100,
Vetor ordenado em ordem descendente: 100, 24, 20, 15, 10, 4, 2, 0, -1, -5,
Para isso, você deve implementar as seguintes funções:
//Lê os elementos do teclado e os coloca em arr. Size possui o tamanho do vetor
void inputArray(int * arr, int size);
//Imprime o conteúdo do vetor arr com tamanho size
void printArray(int * arr, int size); 
//Função que compara dois inteiros. A função retorna a diferença entre o primeiro e o
segundo
int sortAscending(int * num1, int * num2);
//Função que compara dois inteiros. A função retorna a diferença entre o segundo e o
primeiro
int sortDescending(int * num1, int * num2);
//Função que realizada a ordenação. O terceiro argumento é um ponteiro para função que
realiza a comparação entre dois inteiros do vetor (funções sortAscending ou
sortDescending)
void sort(int * arr, int size, int (* compare)(int *, int *));
O conteúdo da função main é dado abaixo:
*/

#include	<stdio.h>

#define	MAX_SIZE	100

void	inputArray(int	*arr,	int	size){
	for(int	i=0;	i<size;	i++)
		scanf("%d",	&arr[i]);
}

void	printArray(int	*arr,	int	size){
	for(int	i=0;	i<size;	i++){
		printf("%d",	arr[i]);
		if(i<size-1)
			printf(", ");
	}
	printf("\n");
}

int	sortAscending(int	*num1,	int	*num2){return	(*num1-*num2);}

int	sortDescending(int	*num1,	int	*num2){return	(*num2-*num1);}

void	sort(int	*arr,	int	size,	int(*compare)(int	*,	int	*)){
	for(int	i=0;	i<size-1;	i++){
		for(int	j=0;	j<size-i-1;	j++){
			if(compare(&arr[j],	&arr[j+1])>0){
				int	temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}				
		}
	}
}

int main()
{
 int arr[MAX_SIZE];
 int size;

 /*
 * Input array size and elements.
 */

 printf("Enter array size: ");
 scanf("%d", &size);
 printf("Enter elements in array: ");
 inputArray(arr, size);
 
 printf("\n\nElements before sorting: ");
 printArray(arr, size);

 // Sort and print sorted array in ascending order.
 printf("\n\nArray in ascending order: ");
 sort(arr, size, sortAscending);
 printArray(arr, size);

 // Sort and print sorted array in descending order.
 printf("\nArray in descending order: ");
 sort(arr, size, sortDescending);
 printArray(arr, size);

 return 0;
}
