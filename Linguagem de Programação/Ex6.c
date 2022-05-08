/*
Nome: Nathan Fonseca da Silva

Descrição do Exercício:
Considere que um banco controla as contas bancárias de seus clientes por meio de vetores
alocados dinamicamente. Um vetor armazena, em cada elemento, as seguintes informações:
    * Nome do cliente;
    * Número da conta corrente;
    * Saldo;
    * Um segundo vetor onde são armazenados todos os últimos 30 movimentos bancários.
    
O vetor com os movimentos bancários contém três campos:
    * Data da transação;
    * Valor da transação;
    * Tipo de operação (débito/crédito).

O programa deverá:
    (a) Ler todas as informações do usuário;
    (b) Ler as informações de uma nova transação de um determinado cliente e adiciona-la no vetor
    correspondente às transações atualizando o campo saldo;
    (c) Informar o saldo de um determinado cliente e todas as suas movimentações bancárias armazenadas.
*/

#include <stdio.h>
#include <stdlib.h>

//Struct dos movimentos bancários
typedef struct{
    int dia;
    int mes;
    int ano;
    double valorTransacao;
    char operacao;
}movBanco;

//Struct com os dados do cliente
typedef struct{
    char nome[100];
    int numConta;
    int qtdeMovimentos;
    int qtdeAux;
    double saldo;
    movBanco movimentos[30];
}Cliente;

Cliente * criarVet(int *, int *);
Cliente * addCliente(Cliente *, int *, int *);
void printarClientes(Cliente *, int *);
void novaTransacao(Cliente *, int *);
void exibirMovimentacoes(Cliente *, int *);


void main(){
    int size, maxSize, opcao;
    Cliente *vetorClientes;

    vetorClientes = criarVet(&size, &maxSize);

    do{
        printf("-----Escolha uma opcao-----");
        printf("\n(1) - Adicionar novo cliente\n(2) - Nova transacao\n(3) - Exibir movimentos bancarios\n(4) - Exibir dados de todos\n(5) - Sair do programa\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                vetorClientes = addCliente(vetorClientes, &size, &maxSize);
                break;
            case 2:
                novaTransacao(vetorClientes, &size);
                break;
            case 3:
                exibirMovimentacoes(vetorClientes, &size);
                break;
            case 4:
                printarClientes(vetorClientes, &size);
                break;
            case 5:
                free(vetorClientes);
                break;
            default:
                printf("A opcao escolhida eh invalida");
        }
    }while(opcao != 5);
}

void exibirMovimentacoes(Cliente *vetor, int *size){
    int contaCorrente, qtdeMov;
    printf("Insira o numero da conta corrente do cliente: ");
    scanf("%d", &contaCorrente);
    for(int i=0;i<*size;i++){
        if(contaCorrente == vetor[i].numConta){
            qtdeMov = vetor[i].qtdeAux;
            printf("Nome: %s\n", vetor[i].nome);
            printf("Saldo: %.2lf \n", vetor[i].saldo);
            printf("MOVIMENTACOES\n");
            for(int x=0;x<qtdeMov;x++){
                printf("----------");
                printf("\nData da transacao: %d/%d/%d", vetor[i].movimentos[x].dia, vetor[i].movimentos[x].mes, vetor[i].movimentos[x].ano);
                printf("\nOperacao selecionado: %c", vetor[i].movimentos[x].operacao);
                printf("\nValor da transacao: %.2lf", vetor[i].movimentos[x].valorTransacao);
                printf("\n----------\n");
            }
        }
    }
}

void novaTransacao(Cliente *vetor, int *size){
    int contaCorrente, qtdeMov;
    printf("Insira o numero da conta corrente do cliente: ");
    scanf("%d", &contaCorrente);
    for(int i=0;i<*size;i++){
        if(contaCorrente == vetor[i].numConta){
            qtdeMov = vetor[i].qtdeMovimentos;
            printf("Dia da transacao: ");
            scanf("%d", &vetor[i].movimentos[qtdeMov].dia);
            printf("Mes da transacao: ");
            scanf("%d", &vetor[i].movimentos[qtdeMov].mes);
            printf("Ano da transcao: ");
            scanf("%d", &vetor[i].movimentos[qtdeMov].ano);
            printf("Escolha se a transacao eh debito ou credito (d/c): ");
            scanf(" %c", &vetor[i].movimentos[qtdeMov].operacao);
            printf("Insira o valor da transacao: ");
            scanf("%lf", &vetor[i].movimentos[qtdeMov].valorTransacao);
            //Verificar se possui saldo para realizar a transação
            if(vetor[i].movimentos[qtdeMov].valorTransacao > vetor[i].saldo){
                printf("Voce nao possui saldo o suficiente para realizar essa transacao!\n");
                break;
            }else{
                vetor[i].saldo -= vetor[i].movimentos[qtdeMov].valorTransacao;
                //qtdeAux irá parar de ser incrementado após atingir o valor 30. Isso irá garantir que quando 
                //a função 'exibirMovimentacoes' for chamada, apenas 30 movimentações serão printadas na tela
                if(vetor[i].qtdeAux < 30)
                    vetor[i].qtdeAux++;    

                /*
                 após preencher até a posição 29 do vetor 'movimentos', o script abaixo garante que
                 ele retornará para a posição '0'. Dessa forma, a cada nova transação depois da trigésima,
                 as posições anteriores serão preenchidos com novas informação, partindo da posição '0'
                */
                if(vetor[i].qtdeMovimentos == 29)
                    vetor[i].qtdeMovimentos = 0;
                else
                    vetor[i].qtdeMovimentos++;
                i = *size;
            }
        }
    }
}

Cliente * criarVet(int *size, int *maxSize){
    Cliente *vetor;
    *size = 0;
    *maxSize= 5;
    vetor = malloc((*maxSize)*sizeof(Cliente));
    return vetor;
}

Cliente * addCliente(Cliente *vetor, int *size, int *maxSize){
    if(*size < *maxSize){
        printf("Digite o nome do cliente: ");
        scanf("%s", &vetor[*size].nome);
        printf("Digite o numero da conta: ");
        scanf("%d", &vetor[*size].numConta);
        //Verifica se já não existe uma conta cadastrada com o número inserido
        for(int i=0;i<(*size);i++){
            if(vetor[*size].numConta == vetor[i].numConta){
                printf("Esse numero de conta ja foi registrado\n");
                return vetor;
            }
        }
        printf("Digite o saldo: ");
        scanf("%lf", &vetor[*size].saldo);
        vetor[*size].qtdeMovimentos = 0;
        vetor[*size].qtdeAux = 0;
        (*size)++;
        return vetor;
    }else{
        Cliente *novoVet;
        *maxSize = (*maxSize) * 2;
        novoVet = malloc(*maxSize*sizeof(Cliente));
        for(int i=0;i<*size;i++)
            novoVet[i] = vetor[i];
        printf("Digite o nome do cliente: ");
        scanf("%s", &novoVet[*size].nome);
        printf("Digite o numero da conta: ");
        scanf("%d", &novoVet[*size].numConta);
        //Verifica se já não existe uma conta cadastrada com o número inserido
        for(int i=0;i<(*size);i++){
            if(novoVet[*size].numConta == novoVet[i].numConta){
                printf("Esse numero de conta ja foi registrado\n");
                return novoVet;
            }
        }
        printf("Digite o saldo: ");
        scanf("%lf", &novoVet[*size].saldo);
        novoVet[*size].qtdeMovimentos = 0;
        vetor[*size].qtdeAux = 0;
        (*size)++;
        free(vetor);
        return novoVet;
    }
}

void printarClientes(Cliente *vetor, int *size){
    for(int i=0;i<*size;i++){
        printf("---------\n");
        printf("Cliente numero %d\n", i+1);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Numero da conta: %d\n", vetor[i].numConta);
        printf("Saldo: %.2lf\n", vetor[i].saldo);
    }
}