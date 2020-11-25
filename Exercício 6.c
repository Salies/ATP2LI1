#include <stdio.h>
#include <math.h>

void SomarPol (int *P1, int *P2, int *P3, int N1, int N2, int *N3);
void MultiPol (int *P1, int *P2, int *P3, int N1, int N2, int *N3);
int ValorPolX (int *P1, int N1, int X);
void MultiCtePol (int *P1, int N1, int K);

void ImprimePol(int *P1, int N1);

int main(void){
    int PolTeste[4] = {5, -1, 4, -1};
    int PolTeste2[3] = {3, 2, 1};
    int PolTeste3[101], n3;

    printf("Polinomio 1: ");
    ImprimePol(PolTeste, 4);
    printf("\n");
    printf("Polinomio 2: ");
    ImprimePol(PolTeste2, 3);
    printf("\n\n");

    printf("Soma de 1 com 2: ");
    SomarPol(PolTeste, PolTeste2, PolTeste3, 4, 3, &n3);
    ImprimePol(PolTeste3, n3);
    printf("\n\n");

    printf("Multiplicacao de 1 com 2: ");
    MultiPol(PolTeste, PolTeste2, PolTeste3, 4, 3, &n3);
    ImprimePol(PolTeste3, n3);
    printf("\n\n");

    printf("Se x = 3, Pol 1 = %d\n\n", ValorPolX(PolTeste, 4, 3));

    printf("Pol 1 vezes a constante k = 2: ");
    MultiCtePol(PolTeste, 4, 2);
    ImprimePol(PolTeste, 4);

    return 0;
}

void SomarPol (int *P1, int *P2, int *P3, int N1, int N2, int *N3){
    int *maior = P1, *menor = P2, nMaior = N1, nMenor = N2, i = 0;

    if(N2 > N1){
        nMaior = N2;
        nMenor = N1;
        maior = P2;
        menor = P1;
    }
    else if (N2 == N1){
        nMaior = nMenor = N1;
        maior = menor = P1;
    }

    while(i < nMenor){
        *(P3 + i) = *(menor + i) + *(maior + i); 
        i++;
    }

    while(i < nMaior){
        *(P3 + i) = *(maior + i);
        i++;
    }

    *N3 = nMaior;

    return;
}

void MultiPol (int *P1, int *P2, int *P3, int N1, int N2, int *N3){
    *N3 = N1 + N2 - 1;

    for(int i = 0; i < *N3; i++){ //prepara o arranjo final
        *(P3 + i) = 0;
    } 

    for(int a = 0; a < N1; a++){
        for(int b = 0; b < N2; b++){
            *(P3 + a + b) += P1[a] * P2[b];
        }
    }

    return;
}

int ValorPolX (int *P1, int N1, int X){
    double v = 0;

    for(int i = 0; i < N1; i++){
        v += P1[i] * pow(X, i);
    }

    return (int) v;
}

void MultiCtePol (int *P1, int N1, int K){
    for(int i = 0; i < N1; i++){
        *(P1 + i) = K * P1[i];
    }

    return;
}

void ImprimePol(int *P1, int N1){
    for(int i = N1 - 1; i > 1; i--){
        printf("%dx^%d + ", *(P1 + i), i);
    }

    printf("%dx + %d", P1[1], P1[0]);

    return;
}