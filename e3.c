#include <stdio.h>

int tam_cresc_max(int *ptr, int N);

int main(void){
    int arr1[9] = {5,10,3, 2, 4, 7,9 ,8,5};
    int arr2[8] = {10,8, 7,5, 4,3, 2,1};
    int arr3[5] = {1, 2, 3, 4, 5};
    int t;

    t = tam_cresc_max(arr1, 9);

    printf("%d ///", t);

    t = tam_cresc_max(arr2, 8);
    
    printf("%d ///", t);

    t = tam_cresc_max(arr3, 5);
    
    printf("%d ///", t);

    return 0;
}

int tam_cresc_max(int *ptr, int N){
    int max = 1, cont = 1;

    for(int i = 1; i < N; i++){
        if(*(ptr + i) > *(ptr + i - 1)){
            cont++;
        }else{
            cont = 1;
        }

        if(cont > max){
            max = cont;
        }
    }

    return max;
}