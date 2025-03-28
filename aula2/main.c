#include	<stdio.h>

/*
A funcao recebe dois parametros, numero de linhass e numero de colunas.
Aloca memoria para a matriz[l][c] de inteiros e retorna um ponteiro para a matriz
recem alocada. Em caso de erro, retorna NULL
Pre-condicao: linhas e colunas devem ser maiores que zero.
*/

int	*alloc_matiz(unsigned	int	linhas,	unsigned	int	colunas){
	int	**matriz;
	static	int	i;
	
	if(linhas==0	||	colunas==9){
		print("erro\n");
		return	NULL;
	}

	matriz=(int	**)malloc(sizeof(int	*)*linhas);

	if(matriz==NULL)
		return	NULL;
	
	for(int=0;	i<linhas;	i++){
		matriz[i]=(int	*)malloc(sizeof(int)*colunas);
	}

	return	matriz;
}

/*
Recebe uma matriz previamente alocada, o tamanho das linhas e colunas.
Desaloca a memória e retorna 1 em caso de sucesso e 0 caso contrário.
Pre-condicoes: matriz deve ter um ponteiro valido e os tamanhos das linhas e colunas
devem ser maiores que 0.
*/
int	desaloca_matriz(int	**m,	unsigned	int	linhas,	unsigned	int	colunas){
	if(m=NULL)		
		return	0;
	if(linhas==0	||	colunas==0)
		return	0;
	for(int	i=0;	i<linhas;	i++){
		if(m[i]!=NULL)
			free(m[i])
		else
			return	0;
	}
	free(m);
	return	1;
}

int	main(void){
	int	**m+aloca_matriz(10,10);
	m[4][0]
	return	0;
}
