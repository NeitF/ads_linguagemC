/*
Nome: Nathan Fonseca da Silva

Descrição do Exercício:
Considere um vetor alocado dinamicamente dentro de uma função, em que cada elemento
seja um valor não inteiro. Nesse vetor, devem ser armazenados os valores diferentes de zero
contidos em um vetor de 100 posições passado como parâmetro da função. Assim, a função deve alocar 
dinamicamente um vetor e preenchê-lo com os valores diferentes de zero do vetor passado como parâmetro e
retornar o endereço para esse vetor alocado dinamicamente.
*/
#include <stdio.h>
#include <stdlib.h>

float * novo_vetor(float [], int *);
void preencherVetor(float []);

void main(){
    int tam;
    float vetor[100];
    preencherVetor(vetor);
    float *novoVetor = novo_vetor(vetor, &tam);
    for(int i=0;i<tam;i++)
        printf("%.2f\n", novoVetor[i]);
 
}

float * novo_vetor(float v[], int *tam){
    float *newVet;
    int size=100;
    //Determinar qual será o tamanho do vetor
    for(int i=0;i<100;i++){
        if(v[i] == 0)
            size--;
    }
    
    *tam = size;
    newVet = malloc(size * sizeof(float));
    //Armazenar valores diferentes de zero
    for(int i=0, j=0;i<100;i++){
        if(v[i] != 0){
            newVet[j] = v[i];
            j++;
        }
    }
    return newVet;
}

void preencherVetor(float vet[]){
    int x=3;
    for(int i=0;i<100;i++){   
        if(x==3){
            vet[i] = 0;
            x=0;
        }else{
            vet[i] = rand() % 20;
            x++;
        }
    }
}