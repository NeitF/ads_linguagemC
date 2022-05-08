/*
Refaça o exercício anterior (ExOrdenacao1) mudando os vetores para que contenha 5 nomes cada um.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencherVetor(char [5][50]);
void exibirVetor(char [5][50]);
void bubbleSort(char [5][50], int);
void selectionSort(char [5][50], int);
void insertionSort(char [5][50], int);
int menorIndice(char [5][50], int, int);

void main(){
    char vetor1[5][50], vetor2[5][50], vetor3[5][50];

    preencherVetor(vetor1);
    // preencherVetor(vetor2);
    // preencherVetor(vetor3);

    // bubbleSort(vetor1, 5);
    // selectionSort(vetor1, 5);
    insertionSort(vetor1, 5);

    exibirVetor(vetor1);
}

void bubbleSort(char vet[5][50], int size){
    char aux[50];
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-(i+1);j++){
            if(strcmp(vet[j], vet[j+1]) > 0){
                strcpy(aux, vet[j]);
                strcpy(vet[j], vet[j+1]);
                strcpy(vet[j+1], aux);
            }
        }
    }
}

void insertionSort(char vet[5][50], int size){
    char aux[50];
    int j;
    for(int i=1;i<size;i++){
        strcpy(aux, vet[i]);
        j = i-1;

        while(j >= 0 && strcmp(vet[j], aux) > 0){
            strcpy(vet[j+1], vet[j]);
            j--;
        }
        strcpy(vet[j+1], aux);
    }
}

void selectionSort(char vet[5][50], int size){
    char aux[50];
    int menor;
    for(int i=0;i<size-1;i++){
        menor = menorIndice(vet, size, i);
        strcpy(aux, vet[i]);
        strcpy(vet[i], vet[menor]);
        strcpy(vet[menor], aux);
    }
}

int menorIndice(char vet[5][50], int size, int ini){
    int min = ini;
    for(int j=ini+1; j<size; j++){
        //strcmp(vet[min], vet[j]) > 0
        if(strcmp(vet[min], vet[j]) > 0)
            min = j;
    }
    return min;
}

void preencherVetor(char vet[5][50]){
    for(int i=0;i<5;i++){
        printf("Nome: ");
        gets(vet[i]);
        fflush(stdin);
    }
}

void exibirVetor(char vet[5][50]){
    for(int i=0;i<5;i++){
        printf("Nome %d = %s\n", (i+1), vet[i]);
    }
}

