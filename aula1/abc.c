#include	<stdio.h>
#include	<stdlib.h>

int	*soma(int	a,	int	b){
	int	*c=(int	*)	malloc(sizeof(int));
	*c=	a+b;
	return	c;
}

int	x;

void	main(){
	int	a,b,*c=NULL;
	a=3;
	b=4;
	c=&a;
	++b;
	c=soma(a,b);
	printf("%d\n",c);
}
