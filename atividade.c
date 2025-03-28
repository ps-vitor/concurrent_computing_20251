/*
1) Retornando múltiplos valores de uma função com estrutura
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


typedef	struct	MinMax{
	int	min;
	int	max;
}MinMax;
