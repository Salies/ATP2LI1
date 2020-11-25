#include <stdio.h>

void imprime_array(int* array, int tam); 
void InverterArranjo(int *A1, int N);

int main(void){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    InverterArranjo(arr, 10);

    imprime_array(arr, 10);

    return 0;
}

void InverterArranjo(int *A1, int N){
    int aux;

    for(int i = 0; i < (N / 2); i++){ //sim divisão INTEIRA
        aux = *(A1 + i);
        *(A1 + i) = *(A1 + N - i - 1);
        *(A1 + N - i - 1) = aux;
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