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
    int i, t1, t2, aux;
    i = t1 = t2 = 0;
    while(t1 == t2){
        t1 = P[i];
        t2 = P[i + 1];
        i++;
    }

    *P1 = i - 1;
    *P2 = i;

    printf("\nNumeros escolhidos: %d na posicao %d // e %d na posicao %d\n", t1, *P1, t2, *P2);

    if(t1 < t2){ //t1 sempre será MAIOR que t2
        swap(&t1, &t2);

        swap(P1, P2);
    }

    printf("\nnumeros depois do shuffle: %d na posicao %d // e %d na posicao %d\n", t1, *P1, t2, *P2);

    for(; i < N; i++){
        if(P[i] > t1){
            swap(&t1, &t2);
            t1 = P[i];

            *P2 = *P1;
            *P1 = i;
        }
        else if(P[i] > t2){
            t2 = P[i];
            *P2 = i;
        }
    }

    *M1 = t1;
    *M2 = t2;

    return;
}

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//NOTA: Dá pra melhorar esse código;