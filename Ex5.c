/*
Nome: Nathan Fonseca da Silva

Descrição do Exercício:
Quais as diferenças entre alocação estática e alocação dinâmica na memória? Quando devemos utilizar
cada uma delas? Justifique sua resposta e forneça um pequeno exemplo na linguagem C

RESPOSTA:
Na alocação estática, a variável aloca um espaço fixo na memória. Esse espaço permanecerá o mesmo
até o fim do programa. Se tiver por exemplo um vetor estático de 5 posições, ele manterá as 5 posições até
o fim da execução do código. Se quisermos aumentar a quantidade de posições, será necessário recompilar o código.
Ja a alocação dinâmica permite que seja alocado mais espaço na memória durante a execução do programa. Se tivermos por exemplo
um vetor dinâmico de 5 posições, podemos aumentar a quantidade de posições para 10.

Utilizamos alocação estática quando sabemos exatamente quantas posições um vetor terá, e temos a certeza de que ele não precisará
de mais ou menos posições.
Utilizamos alocação dinâmica quando não sabemos quantas posições um vetor pode ter. Assim, garantimos que ele pode se expandir ou
retrair quando julgar necessário.
*/

#include <stdio.h>
#include <stdlib.h>

void printVet(int *, int);
void preencherVet(int *, int);

void main(){
    int size=5, *vetDinamico;
    printf("-----Vetor Estatico-----\n");
    int vetEstatico[] = {1,2,3,4,5};
    printVet(vetEstatico, size);
    printf("\n-----Vetor Dinamico-----\n");
    vetDinamico = malloc(size*sizeof(int));
    preencherVet(vetDinamico, size);
    printVet(vetDinamico, size);

}

void printVet(int *vet, int size){
    for(int i=0;i<size;i++)
        printf("%d\n", vet[i]);
}

void preencherVet(int *vet, int size){
    for(int i=0;i<size;i++)
        vet[i] = i+1;
}

