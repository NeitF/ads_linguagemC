/*
Nome: Nathan Fonseca da Silva

Descrição do Exercício:
Escreva uma função que recebe como parâmetro um vetor de inteiros, um inteiro n que 
indica o tamanho do vetor e dois ponteiros para inteiro f1 e f2. A função deve devolver no 
endereço apontado por f1 o elemento do vetor de menor frequência (que possui o menor número
de ocorrências) e no endereço apontado por f2 o elemento do vetor de maior frequência.
*/
#include <stdio.h>

void frequencias(int [], int, int *, int *);
int lerFrequencia(int *, int, int);
void selectionSort(int [], int);
int menorIndice(int [], int, int);

void main(){
    int f1, f2;
    int vetor[10] = {0,1,4,1,1,4,7,2,4,1};
    int n = sizeof(vetor)/sizeof(int);
    //O selection sort garante que a variável 'numAtual' localizada na função 'frequencias' cumpra seu papel
    selectionSort(vetor, n);
    //f1 - menor frequencia   f2 - maior frequencia
    frequencias(vetor, n, &f1, &f2);
    printf("F1(menor frequencia):%d\nF2(maior frequencia):%d", f1, f2);
}

void frequencias(int v[], int n, int *f1, int *f2){
    int numAtual, freq, maiorFreq, menorFreq;
    //Considerar que na primeira repetição a maior e a menor frequência sempre serão v[0]
    freq = lerFrequencia(v, n, 0);
    maiorFreq = freq;
    menorFreq = freq;
    *f2 = v[0];
    *f1 = v[0];
    numAtual = v[0];
    for(int i=1;i<n;i++){
        if(v[i] != numAtual){
            numAtual = v[i];
            freq = lerFrequencia(v, n, i);
            if(freq > maiorFreq){
                maiorFreq = freq;
                *f2 = v[i];
            }
            if(freq < menorFreq){
                menorFreq = freq;
                *f1 = v[i];
            }
        }
    }
}

int lerFrequencia(int *v, int n, int i){
    int num=1;
    for(int j=i+1;j<n;j++){
        if(v[i] == v[j])
            num++;
    }
    return num;
}

void selectionSort(int vet[], int size){
    int menor, aux;
    for(int i=0; i<size; i++){
        menor = menorIndice(vet, size, i);
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}

int menorIndice(int vet[], int size, int i){
    for(int j=i+1; j<size; j++){
        if(vet[i] > vet[j])
            i = j;
    }
    return i;
}