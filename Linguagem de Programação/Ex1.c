/*
Nome: Nathan Fonseca da Silva

Descrição do Exercício:
Escreva um programa que armazena CPF, a data de nascimento e a altura de n jogadores
de basquete. O programa deve conter um menu que execute as seguintes operações:
    * Cadastrar um novo jogador;
    * Imprimir os jogadores que nasceram em um determinado intervalo de datas;
    * Ordenar e imprimir os jogadores em ordem crescente de altura;
    * Sair do programa.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cpf;
    int dia;
    int mes;
    int ano;
    float altura;
}Jogador;

Jogador * criarVet(int *, int *);
Jogador * addJogador(Jogador *, int *, int *);
int menorIndice(Jogador *, int, int);
void ordenar(Jogador *, int);
void intervaloData(Jogador *, int);
void printJogadores(Jogador *, int);
void printJogador(Jogador *, int);


void main(){
    int opcao, size, maxSize;
    Jogador *vetorJogadores;
    
    vetorJogadores = criarVet(&size, &maxSize);

    do{
        printf("-----MENU DE OPCOES-----\n");
        printf("(1) - Cadastar novo jogador\n(2) - Imprimir jogadores que nasceram entre determinadas datas\n(3) - Ordenar jogadores por altura\n(4) - Sair do programa\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:           
                vetorJogadores = addJogador(vetorJogadores, &size, &maxSize);
                break;
            case 2:
                intervaloData(vetorJogadores, size);
                break;
            case 3:
                ordenar(vetorJogadores, size);
                printJogadores(vetorJogadores, size);
                break;
            case 4:
                free(vetorJogadores);
                break;
            default:
                printf("Opcao invalida!");
        }
    }while(opcao!=4);
}

void printJogadores(Jogador *vetor, int size){
     for(int i=0;i<size;i++){
        printf("-----Jogador %d-----\n", i+1);
        printf("CPF:%d\n", vetor[i].cpf);
        printf("Data de nascimento:%d/%d/%d\n", vetor[i].dia, vetor[i].mes, vetor[i].ano); 
        printf("Altura: %.2f\n", vetor[i].altura);
     }
}

void printJogador(Jogador *vetor, int chave){
    printf("-----Jogador-----\n");
    printf("CPF:%d\n", vetor[chave].cpf);
    printf("Data de nascimento:%d/%d/%d\n", vetor[chave].dia, vetor[chave].mes, vetor[chave].ano); 
    printf("Altura: %.2f\n", vetor[chave].altura);
}

Jogador * criarVet(int *size, int *maxSize){
    Jogador *vetor;
    *size = 0;
    *maxSize = 5;
    vetor = malloc((*maxSize)*sizeof(Jogador));
    return vetor;
}

Jogador * addJogador(Jogador *vetor, int *size, int *maxSize){
    if(*size < *maxSize){
        printf("Insira o CPF do jogador: ");
        scanf("%d", &vetor[*size].cpf);
        printf("Insira o dia de nascimento do jogador: ");
        scanf("%d", &vetor[*size].dia);
        printf("Insira o mes de nascimento do jogador: ");
        scanf("%d", &vetor[*size].mes);
        printf("Insira o ano de nascimento do jogador: ");
        scanf("%d", &vetor[*size].ano);
        printf("Insira a altura do jogador: ");
        scanf("%f", &vetor[*size].altura);
        (*size)++;
        return vetor;
    }else{
        Jogador *novoVet;
        *maxSize = (*maxSize) * 2;
        novoVet = malloc(*maxSize*sizeof(Jogador));
        //Passar os valor de '*vetor' para '*novoVet'
        for(int i=0;i<*size;i++)
            novoVet[i] = vetor[i];
        printf("Insira o CPF do jogador: ");
        scanf("%d", &novoVet[*size].cpf);
        printf("Insira o dia de nascimento do jogador: ");
        scanf("%d", &novoVet[*size].dia);
        printf("Insira o mes de nascimento do jogador: ");
        scanf("%d", &novoVet[*size].mes);
        printf("Insira o ano de nascimento do jogador: ");
        scanf("%d", &novoVet[*size].ano);
        printf("Insira a altura do jogador: ");
        scanf("%f", &novoVet[*size].altura);
        (*size)++;
        free(vetor);
        return novoVet;
    }
}

void intervaloData(Jogador *vetor, int size){
    int d1, d2, m1, m2, a1, a2;
    printf("-----Data Inicial-----\n");
    printf("Dia: ");
    scanf("%d", &d1);
    printf("Mes: ");
    scanf("%d", &m1);
    printf("Ano: ");
    scanf("%d", &a1);
    printf("-----Data Final-----\n");
    printf("Dia: ");
    scanf("%d", &d2);
    printf("Mes: ");
    scanf("%d", &m2);
    printf("Ano: ");
    scanf("%d", &a2);
    /*
    X = Deve reprovar no teste
    ! = Deve passar no teste
    
    1- 12/3/2015 X
    2- 8/9/2005 !
    3- 25/4/2010 ! 
    4- 27/10/2010 X
    5- 30/4/2000 X 
    6- 5/8/2000 !
    7- 21/7/2000 !
    8- 5/10/2010 !
    9- 1/1/1995 X

    Primeira data (data inicial)
    data1 = 21/7/2000
    Segunda data (data final)
    data2 = 5/10/2010
    */
    for(int i=0;i<size;i++){
        if(vetor[i].ano >= a1 && vetor[i].ano <= a2){
            //Se o ano na struct for igual a a2, então o mês não pode ser maior que m2
            if(vetor[i].ano == a2 && vetor[i].mes > m2)
                continue;
            //Se o ano na struct for igual a a1, então o mês não pode ser menor que m1
            if(vetor[i].ano == a1 && vetor[i].mes < m1)
                continue;
            //Se o ano na struct for igual a a2 e o mês igual a m2, então o dia não pode ser maior que d2
            if(vetor[i].ano == a2 && vetor[i].mes == m2){
                if(vetor[i].dia > d2)
                    continue;
            }
            //Se o ano na struct for igual a a1 e o mês igual a m1, então o dia não pode ser menor que d1
            if(vetor[i].ano == a1 && vetor[i].mes == m1){
                if(vetor[i].dia < d1)
                    continue;
            }
            printJogador(vetor, i);
        }
    }
}

void ordenar(Jogador *vetor, int size){
    int menor;
    Jogador aux;
    for(int i=0;i<size;i++){
        menor = menorIndice(vetor, size, i);
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

int menorIndice(Jogador *vetor, int size, int i){
    for(int x=i+1;x<size;x++){
        if(vetor[i].altura > vetor[x].altura)
            i = x;
    }
    return i;
}


