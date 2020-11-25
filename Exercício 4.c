#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Merge(int *A1, int *A2, int *A3, int N, int M);
void ShellSort(int *Str, int Dim);
void associa_aleatorio(int* array, int tam);
void imprime_array(int* array, int tam); 

int main(void){
    //NOTA: Seguindo estritramente a proposta do exercício, vai sobrar memória caso haja elementos repetidos ENTRE os conjuntos
    time_t t;
    srand((unsigned) time(&t)); //gerando semente para números aleatórios

    int *a1 = NULL, *a2 = NULL, *a3 = NULL, n, m;
    n = m = -1;

    do{
        printf("Insira o tamanho do primeiro arranjo: ");
        scanf("%d", &n);
    }while(n <= 0);
    
    a1 = (int *) malloc(n * sizeof(int));
    if(!a1){
        printf("\nDeu ruim!");
        exit(1);
    }

    do{
        printf("Insira o tamanho do primeiro arranjo: ");
        scanf("%d", &m);
    }while(m <= 0);

    a2 = (int *) malloc(m * sizeof(int));
    if(!a2){
        printf("\nDeu ruim!");
        exit(1);
    }

    a3 = (int *) malloc((n + m) * sizeof(int));
    if(!a3){
        printf("\nDeu ruim!");
        exit(1);
    }

    associa_aleatorio(a1, n);
    associa_aleatorio(a2, m);

    ShellSort(a1, n);
    ShellSort(a2, m);

    Merge(a1, a2, a3, n, m);

    printf("A1: ");
    imprime_array(a1, n);

    printf("A2: ");
    imprime_array(a2, m);

    printf("A3 (Merge): ");
    imprime_array(a3, (n + m));
    return 0;
}

void Merge(int *A1, int *A2, int *A3, int N, int M){
    int CN, CM, k;
    CN = CM = k = 0;

    while((CN < N) && (CM < M)){
        if(*(A1 + CN) < *(A2 + CM)){
            *(A3 + k) = *(A1 + CN);
            CN++;
        }
        else if(*(A2 + CM) < *(A1 + CN)){
            *(A3 + k) = *(A2 + CM);
            CM++;
        }
        else{ //iguais, pega só um (sem repetições)
            *(A3 + k) = *(A1 + CN);
            CN++; CM++;
        }

        k++;
    }

    while (CN < N ) {  *(A3 + k) = *(A1 + CN);  CN++; k++;}
    while (CM < M ) {  *(A3 + k) = *(A2 + CM);  CM++; k++;}

    return;
}

void ShellSort(int *Str, int Dim) {
    int i, j, x, salto;

    for (salto=Dim/2; salto>0; salto /=2){
    for (i = salto; i < Dim; i++) {
        x = *(Str+i);
        for (j=i; j >= salto && x < *(Str+j-salto); j=j-salto)
            *(Str+j) = *(Str+j-salto);
        *(Str+j) = x;
    }	//for i
    }	// for k
    return;
}

void associa_aleatorio(int* array, int tam){
    for(int i = 0; i < tam; i++){
        *(array + i) = rand();
    }

    return;
}

void imprime_array(int* array, int tam){
    printf("{");
    for(int i = 0; i < tam - 1; i++){
        printf("%d, ", *(array + i));
    }
    printf("%d}\n", *(array + tam - 1));
    return;
}