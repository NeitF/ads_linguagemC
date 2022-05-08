/*
Descrição do Exercício:
Desenvolva um programa que contenha três vetores que devem ser preenchidos com 10 números cada um. 
Crie um procedimento que ordene o primeiro vetor utilizando o método de trocas, um procedimento que 
ordene o segundo vetor utilizando o método de seleção e um procedimento que ordene o terceiro vetor 
utilizando o método de inserção. Ao final mostre o conteúdo dos três vetores na tela;
*/

#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int []);
void exibirVetor(int []);
void bubbleSort(int [], int);
void selectionSort(int [], int);
void insertionSort(int [], int);
int menorIndice(int [], int, int);


void main(){
    int vetor1[10], vetor2[10], vetor3[10];

    preencherVetor(vetor1);
    preencherVetor(vetor2);
    preencherVetor(vetor3);

    // bubbleSort(vetor1, 10);
    // selectionSort(vetor2, 10);
    insertionSort(vetor3, 10);
    exibirVetor(vetor3);
}

void insertionSort(int vet[], int size){
    int aux, j;
    for(int i=1;i<size;i++){
        aux = vet[i];
        j = i-1;

        while(j >= 0 && vet[j] > aux){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = aux;
    }
}

void selectionSort(int vet[], int size){
    int aux, menor;
    for(int i=0;i<size-1;i++){
        menor = menorIndice(vet, size, i);
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}

int menorIndice(int vet[], int size, int ini){
    int min = ini;
    for(int j=ini+1; j<size; j++){
        if(vet[min] > vet[j])
            min = j;
    }
    return min;
}

void bubbleSort(int vet[], int size){
    int aux = 0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-(i+1);j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

void preencherVetor(int vetor[]){
    for(int i=0;i<10;i++){
        vetor[i] = rand() % 100;
    }
}

void exibirVetor(int vetor[]){
    for(int i=0;i<10;i++){
        printf("%d\n", vetor[i]);
    }
}