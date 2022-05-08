/*
Feito por: Nathan Fonseca da Silva

Descrição do Exercício:
Crie um sistema de senha de atendimento. O sistema deve emitir uma nova senha e quando uma senha 
for atendida, a mesma deverá ser removida da fila. Criem um menu de acesso. O tema do tipo de 
atendimento é livre, use a criatividade. 

EXPLICAÇÃO DO CÓDIGO
A ideia é simular o sistema de atendimento de um banco, onde teremos dois tipos de filas:
- A fila comum;
- A fila preferencial.

Senhas de número positivo representam a fila comum, enquanto senhas de número negativo
representam a fila preferencial. O número zero indica que não há senhas para serem atendidas.
Por padrão, o sistema irá priorizar o atendimento da fila preferencial, portanto ele só irá começar
a atender a fila comum se a fila preferencial estiver vazia.
*/

#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

void qinit(Fila *, FilaPref *); //Inicia a fila
void addQueue(Fila *, int); //Adiciona uma nova senha à fila
void addQueuePref(FilaPref *, int); //Adiciona uma nova senha à fila preferencial
void initSenha(int []); //Adiciona senhas ao vetor de senha
void initSenhaPref(int []); //Adiciona senhas ao vetor de senha preferencial (numeros negativos)
void exibirFila(Fila *, FilaPref *); //Exibe toda a fila e suas senha 
int atendQueue(Fila *, FilaPref *); //Atende algumas senha e a retira da fila
int isFull(Fila *); //Verifica se a fila está cheia
int isFullPref(FilaPref *);  //Verifica se a fila preferencial está cheia
int isEmpty(Fila *); //Verifica se a fila está vazia
int isEmptyPref(FilaPref *); //Verifica se a fila preferencial está vazia


void main(){
    Fila f;
    FilaPref fp;
    int senha[200], senhaPref[200];
    int opcao, s, sp, num=0, numPref=0;

    qinit(&f, &fp); //Inicia fila 
    initSenha(senha); //Inicia senha comum
    initSenhaPref(senhaPref); //Inicia senha preferencial
    while(opcao!=0){
        s = senha[num];
        sp = senhaPref[numPref];
        system("cls");
        printf("\n-----\n");
        printf("(0) - Sair\n(1) - Adicionar na fila\n(2) - Adicionar na fila preferencial\n(3) - Atender proximo da fila\n(4) - Exibir fila");
        printf("\n-----\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                addQueue(&f, s);
                num++;
                system("pause");
                break;
            case 2:
                addQueuePref(&fp, sp);
                numPref++;
                system("pause");
                break;
            case 3:
                printf("\nSenha %d atendida!\n" , atendQueue(&f, &fp));
                system("pause");
                break;
            case 4:
                exibirFila(&f, &fp);
                system("pause");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida\n\n");
                system("pause");
        }
    }
}

void exibirFila(Fila *f, FilaPref *fp){
    printf("\nTamanho das filas: %d\n", Max);
    printf("\nFILA COMUM\n");
    for(int i=0;i<f->total;i++){
        printf("Posicao[%d]: Senha %d\n", i, f->valor[i]);
    }

    printf("\nFILA PREFERENCIAL\n");
    for(int i=0;i<fp->total;i++){
        printf("Posicao[%d]: Senha %d\n", i, fp->valor[i]);
    }
}

int atendQueue(Fila *f, FilaPref *fp){
    if(isEmptyPref(fp)==0){
        int y = fp->valor[fp->comeco];
        //Este laço é responsável por "fazer a fila andar"
        for(int i=0;i<(fp->total-1);i++){
            fp->valor[i] = fp->valor[i+1];
        }
        fp->final--;
        fp->total--;
        return y;
    }else if(isEmpty(f)==0){
        int x = f->valor[f->comeco];
        //Este laço é responsável por "fazer a fila andar"
        for(int i=0;i<(f->total-1);i++){
            f->valor[i] = f->valor[i+1];
        }
        f->final--;
        f->total--;
        return x;
    }else{
        printf("\nA fila esta vazia!\n");
        return 0;
    }

}

void addQueue(Fila *f, int senha){
    if(isFull(f)==0){
        f->valor[f->final] = senha;
        f->final++;
        f->total++;
    }else{
        printf("\nA fila esta cheia!\n");
    }
}

void addQueuePref(FilaPref *fp, int senhaPref){
    if(isFullPref(fp)==0){
        fp->valor[fp->final] = senhaPref;
        fp->final++;
        fp->total++;
    }else{
         printf("\nA fila preferencial esta cheia!\n");
    }
}

int isEmpty(Fila *f){
    return(f->total==0);
}

int isEmptyPref(FilaPref *fp){
    return(fp->total==0);
}

int isFull(Fila *f){
    return(f->total==Max);
}

int isFullPref(FilaPref *fp){
    return(fp->total==Max);
}

void initSenha(int senha[]){
    for(int i=0;i<200;i++){
        senha[i] = (i+1);
    }
}

void initSenhaPref(int senha[]){
    int x=0;
    for(int i=0;i<200;i++){
        x-=1;
        senha[i] = x;
    }
}

void qinit(Fila *f, FilaPref *fp){
    f->comeco = 0;
    f->final = 0;
    f->total = 0;

    fp->comeco = 0;
    fp->final = 0;
    fp->total = 0;
}