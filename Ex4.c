/*
Nome: Nathan Fonseca da Silva

Descrição do Exercício:
Considere o tipo Cell definido abaixo:
    
    typedef struct{
        char car;
        int peso;
    } Cell;

Dado um vetor vet de n > 0 elementos do tipo Cell, uma sequência de dois ou mais elementos
consecutivos no vetor tais que o valor em seus campos car são iguais é chamada faixa. Por exemplo,
se os valores dos campos car de vet formam a sequência "yyzzzya", existem duas faixas no vetor: "yy" e "zzz".
Escreva uma função que receba, como entrada, um vetor de n > 0 elementos do tipo Cell e devolva, como
saída, a soma dos pesos de todos os elementos do vetor que pertencem a faixas. Por exemplo, para a sequência
"yyzzzya", se os pesos destes elementos são 10,2,5,4,5,4,3, a sua função deve devolver o valor 26.
*/
#include <stdio.h>

typedef struct{
    char car;
    int peso;
} Cell;

void addCell(Cell [], int);
int somaPeso(Cell [], int);

void main(){
    //Alterar o tamanho de vet altera a quantidade de repetições (testar com vários números)
    Cell vet[6];
    int n = sizeof(vet)/sizeof(Cell);
    int soma;
    for(int i=0;i<n;i++)
        addCell(vet, i);

    soma = somaPeso(vet, n);
    printf("\nSoma do pesos: %d", soma);
}

int somaPeso(Cell v[], int n){
    int soma=0, faixa=2;
    for(int i=0;i<n-1;i++){
        if(v[i].car == v[i+1].car){
            if(faixa==2){
                soma += (v[i].peso + v[i+1].peso);
                faixa++;        
            }else{
                soma += v[i+1].peso;
            }
        }else{
            faixa=2;
        }
    }
    return soma;
}

void addCell(Cell v[], int i){
    printf("-----Operacao (%d)-----\n", i+1);
    printf("Insira o char de car: ");
    scanf(" %c", &v[i].car);
    printf("Insira o peso: ");
    scanf("%d", &v[i].peso);
}