#include <stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>


//       (pai)      
//         |        
//    +----+----+
//    |         |   
// filho_1   filho_2


// ~~~ printfs  ~~~
// pai (ao criar filho): "Processo pai criou %d\n"
//    pai (ao terminar): "Processo pai finalizado!\n"
//  filhos (ao iniciar): "Processo filho %d criado\n"

// Obs:
// - pai deve esperar pelos filhos antes de terminar!


int main(int argc, char** argv) {

    // ....

    /*************************************************
     * Dicas:                                        *
     * 1. Leia as intruções antes do main().         *
     * 2. Faça os prints exatamente como solicitado. *
     * 3. Espere o término dos filhos                *
     *************************************************/

	pid_t	pid1,	pid2;

	pid1	=	fork();
	if(pid1<0){	
		perror("Erro ao criar o primeiro filho");
		return	1;
	}

	if(pid1==0){
		printf("Processo filho %d criado\n",getpid());
		return	0;
	}else{
		printf("Processo pai criou %d\n",pid1);

		pid2=fork();
		if(pid2<0){
			perror("Erro ao criar o segundo filho");
			return	1;
		}
		if(pid2==0){
			printf("Processo filho %d criado\n",getpid());
			return	0;
		}else{
			printf("Processo pai criou %d\n",pid2);

			int	status;
			waitpid(pid1,&status,0);
			waitpid(pid2,&status,0);
			printf("Processo pai finalizado!\n");
		}
	}
	return	0;
}
