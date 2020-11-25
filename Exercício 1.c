#include <stdio.h>
#include <math.h>

#define MAX 100

void imprime_array(int* array, int tam); 
void NPrimeirosPrimos(int *Ptr, int N);
short primo(int n);

int main(void){
    int arr[MAX];

    NPrimeirosPrimos(arr, MAX);

    imprime_array(arr, MAX);

    return 0;
}

void NPrimeirosPrimos(int *Ptr, int N){
    if(N <= 0) return;

    int i = 0, k = 3;

    *(Ptr + i) = 2;
    i++;

    if(N == 1) return;

    while(i < N){
        if(primo(k)){
            *(Ptr + i) = k;
            i++;
        }
        k += 2;
    }

    return;
}

short primo(int n) {
    if (n == 0 || n == 1 || (n % 2 == 0 && n != 2)) {
        return 0;
    }
    
    const double raiz = sqrt(n);

    for (int i = 3; i <= raiz; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void imprime_array(int* array, int tam){
    if(tam == 0){
        printf("\nConjunto vazio.\n");
        return;
    }
    
    printf("{");
    for(int i = 0; i < tam - 1; i++){
        printf("%d, ", *(array + i));
    }
    printf("%d}\n", *(array + tam - 1));
    return;
}