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

    ImprimePol(PolTeste, 4);
    printf("\n");
    ImprimePol(PolTeste2, 3);
    printf("\n");
    SomarPol(PolTeste, PolTeste2, PolTeste3, 4, 3, &n3);
    ImprimePol(PolTeste3, n3);

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

void ImprimePol(int *P1, int N1){
    for(int i = N1 - 1; i > 1; i--){
        printf("%dx^%d + ", *(P1 + i), i);
    }

    printf("%dx + %d", P1[1], P1[0]);

    return;
}