/*
Nome: Nathan Fonseca da Silva

Descrição do Exercício:
Considere a função de Ackermann A(m,n) abaixo, onde m e n valores inteiros não negativos, dada por:

          n + 1              m = 0
A(m,n) =  A(m-1, 1)          m > 0, n = 0
          A(m-1, A(m, n-1))  m > 0, n > 0

e m e n são valores digitados pelo usuário.
Para achar sua solução, escreva:
    (a) Uma função não recursiva;
    (b) Uma função recursiva.

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
    //Situação 1
    if(m == 0){
        return n+1;
    }else if(m > 0 && n == 0){
    //Situação 2    
        return ackermann(m-1, 1);
    }else{
    //Situação 3
        ackermann(m-1, ackermann(m, n-1));
    }
}