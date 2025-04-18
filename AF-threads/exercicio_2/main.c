#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

typedef	struct{
	double	*a;
	double	*b;
	double	*c;
	double	inicio,fim;
}param_t;

// Lê o conteúdo do arquivo filename e retorna um vetor E o tamanho dele
// Se filename for da forma "gen:%d", gera um vetor aleatório com %d elementos
//
// +-------> retorno da função, ponteiro para vetor malloc()ado e preenchido
// | 
// |         tamanho do vetor (usado <-----+
// |         como 2o retorno)              |
// v                                       v
double* load_vector(const char* filename, int* out_size);


// Avalia o resultado no vetor c. Assume-se que todos os ponteiros (a, b, e c)
// tenham tamanho size.
void avaliar(double* a, double* b, double* c, int size);

void*   somar_vetores(void* arg){
    param_t* p=(param_t*)arg;
    for(int i=p->inicio;i<p->fim;++i){
        p->c[i]=p->a[i]+p->b[i];
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    // Gera um resultado diferente a cada execução do programa
    // Se **para fins de teste** quiser gerar sempre o mesmo valor
    // descomente o srand(0)
    srand(time(NULL)); //valores diferentes
    //srand(0);        //sempre mesmo valor

    //Temos argumentos suficientes?
    if(argc < 4) {
        printf("Uso: %s n_threads a_file b_file\n"
               "    n_threads    número de threads a serem usadas na computação\n"
               "    *_file       caminho de arquivo ou uma expressão com a forma gen:N,\n"
               "                 representando um vetor aleatório de tamanho N\n",
               argv[0]);
        return 1;
    }
  
    //Quantas threads?
    int n_threads = atoi(argv[1]);
    if (!n_threads) {
        printf("Número de threads deve ser > 0\n");
        return 1;
    }
    //Lê números de arquivos para vetores alocados com malloc
    int a_size = 0, b_size = 0;
    double* a = load_vector(argv[2], &a_size);
    if (!a) {
        //load_vector não conseguiu abrir o arquivo
        printf("Erro ao ler arquivo %s\n", argv[2]);
        return 1;
    }
    double* b = load_vector(argv[3], &b_size);
    if (!b) {
        printf("Erro ao ler arquivo %s\n", argv[3]);
        free(a);
        return 1;
    }
    
    //Garante que entradas são compatíveis
    if (a_size != b_size) {
        printf("Vetores a e b tem tamanhos diferentes! (%d != %d)\n", a_size, b_size);
        free(a);
        return 1;
    }
    //Cria vetor do resultado 
    double* c = malloc(a_size*sizeof(double));
    if(!c){
        perror("malloc");
        free(a);
        free(b);
        return 1;
    }

    if(n_threads>a_size)n_threads=a_size;

    // Calcula com uma thread só. Programador original só deixou a leitura 
    // do argumento e fugiu pro caribe. É essa computação que você precisa 
    // paralelizar
    //
   	//pthread_t*	c=malloc(a_size*sizeof(double)); 
    //
    //    +---------------------------------+
    // ** | IMPORTANTE: avalia o resultado! | **
    //    +---------------------------------+
    //
    /*pthread_t	thread;
    param_t	params;
    params.a=a;
    params.b=b;
    */
    pthread_t*  threads=malloc(n_threads*sizeof(pthread_t));
    param_t*    params=malloc(n_threads*sizeof(param_t));
    
    int tamanho_bloco=a_size/n_threads;
    int resto=a_size%n_threads;

    int inicio=0;
    for(int i=0;i<n_threads;++i){
        int fim=inicio+tamanho_bloco+(i<resto?1:0);
        params[i].a = (double *)a;
        params[i].b = (double *)b;
        params[i].c = (double *)c;
        params[i].inicio=inicio;
        params[i].fim=fim;

        pthread_create(&threads[i],NULL,somar_vetores,&params[i]);
        // if(pthread_create(&threads[i], NULL, somar_vetores, &params[i])!=0){
        //     perror("pthread_create");
        //     exit(1);
        // }
        inicio=fim;
    }

    for(int i=0;i<n_threads;++i){
        pthread_join(threads[i], NULL);
    }
    
    avaliar(a, b, c, a_size);
    

    //Importante: libera memória
    free(a);
    free(b);
    free(c);
    free(threads);
    free(params);

    return 0;
}
