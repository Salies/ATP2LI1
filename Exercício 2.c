#include <stdio.h>

void swap(int *a, int *b);
void DMaiores (int *P, int N, int *M1, int *M2, int *P1, int *P2);
/*
P = Ponteiro do array
N = n elementos
M1 = Primeiro maior
M2 = Segundo maior
P1 = Posição de M1
P2 = Posição de M2
*/

int main(void){
    int m1, m2, p1, p2;

    int arr[10] = {3, 3, 1, 5, 1, 8, 30, 9, 12, 3};

    DMaiores(arr, 10, &m1, &m2, &p1, &p2);

    printf("M1 = %d\nM2 = %d\nP1 = %d\nP2 = %d", m1, m2, p1, p2);

    return 0;
}

//NOTA: Resolução SEM ordenação
void DMaiores (int *P, int N, int *M1, int *M2, int *P1, int *P2){
    int i;
    i = *M1 = *M2 = 0;
    while(*M1 == *M2){
        *M1 = P[i];
        *M2 = P[i + 1];
        i++;
    }

    *P1 = i - 1;
    *P2 = i;

    if(M1 < M2){ //t1 sempre será MAIOR que t2
        swap(M1, M2);

        swap(P1, P2);
    }

    for(; i < N; i++){
        if(P[i] > *M1){
            swap(M1, M2);
            *M1 = P[i];

            *P2 = *P1;
            *P1 = i;
        }
        else if(P[i] > *M2){
            *M2 = P[i];
            *P2 = i;
        }
    }

    return;
}

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;

    return;
}