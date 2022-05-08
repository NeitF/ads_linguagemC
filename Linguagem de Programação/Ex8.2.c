/*
Nome: Nathan Fonseca da Silva
*/


#include <stdio.h>

int ackermann(int, int);

void main(){
    int m, n;

    printf("Insira m: ");
    scanf("%d", &m);
    printf("Insira n: ");
    scanf("%d", &n);
    printf("Resultado: %d", ackermann(m, n));
}

int ackermann(int m, int n){
    while(1){
        //Situação 1
        if(m == 0){
            return n+1;
        }else if(m > 0 && n == 0){
        //Situação 2
            m -= 1;
            n = 1;
        }else{
        //Situação 3
            n = ackermann(m, n-1);
            m -= 1;
        }
    }
}