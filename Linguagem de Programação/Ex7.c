/*
Nome: Nathan Fonseca da Silva

Descrição do Exercício:
Em um fórum, criado para debater sobre as eleições do próximo prefeito, centenas de pessoas se 
inscreveram. Cada pessoa tem um partido e tem uma pergunta a ser feita para outra pessoa, de um
partido diferente. Por dia, serão feitas 20 perguntas. Como o fórum irá durar poucos dias, nem
todos poderão realizar perguntas. Pensando nisso, o organizador criou algumas regras:
    * O primeiro a realizar a pergunta é o primeiro a ter se inscrito;
    * Se um pessoa for endereçada a um partido P, então o primeiro partidário de P que ainda
    não falou responderá a pargunta;
    * Tem direito a fazer a próxima pergunta a pessoa que tiver acabado de responder.

Considerando o cenário descrito, faça:
    a - Projete e descreva um estrutura de dados para armazenar os dados do problema. A estrutura
    deve ser pensada para as operações descritas abaixo;
    b - Escreva um algoritmo que receba os dados das pessoas em ordem de inscrição e crie a estrutura de
    dados projetada no item anterior. Deixe claro qual é a entrada, por exemplo, uma pessoa pode ser
    identificada pelo número de identidade e um partido pelo número da legenda. Serão informados número de dias,
    número de partido, etc;
    c - Escreva uma função que determine se uma dada pessoa poderá fazer uma pergunta.
    

EXPLICAÇÃO DO FUNCIONAMENTO DO ALGORITMO

Antes de tudo, será necessário criar um novo partido. Durante a sua criação, é criado 
automaticamente um vetor dinamico de 5 posições onde serão armazenados os dados dos partidários.
Cada posição do vetor 'partido' tem um vetor de 5 posições do tipo 'partidario'. Esses vetores são dinâmicos
e se expandem a medida que o usuario vai adicionando mais partidos/partidários.
É necessário ter ao menos um partido adicionado para adicionar um partidário.
A opção 'Exibir partidos' mostra a ID do partido (criada automaticamente durante a criação do partido), o nome e
a quantidade de partidários que aquele partido possui.
A opção 'Exibir partidarios' mostra as informações de todos os partidários de um determinado partido.
A opção 'perguntas' funciona da seguinte forma:
    O primeiro partido adicionado será o primeiro a perguntar;
    O primeiro partidario adicionado nesse partido irá fazer a pergunta;
    É escolhido um partido ao qual a pergunta é direcionada
    O primeiro partidario livre do partido selecionado irá responder a pergunta, e logo após isso irá fazer uma
    pergunta para algum partido.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idPartidario;
    int podeResponder;
    char nomePartidario[100];
}partidario;

typedef struct{
    int idPartido;
    int numPartidarios;
    int sizePart, maxSizePart;
    char nomePartido[100];
    partidario *vetorPartidario;
}partido;

partido * criarPartido(int *, int *);
partido * addPartido(partido *, int *, int *);
void exibirPartidos(partido *, int *);
void addPartidario(partido *, int *);
void exibirPartidario(partido *, int *);
void perguntas(partido *, int *, int *, int *);

void main(){
    int size, maxSize, opcao, posicaoPartido = 0, posicaoPartidario = 0;
    partido *vetorPartido;

    vetorPartido = criarPartido(&size, &maxSize);
    do{
        printf("-----Escolha uma opcao-----");
        printf("\n(1) - Add novo partido\n(2) - Add novo partidario\n(3) - Perguntas\n(4) - Exibir Partidario\n(5) - Exibir Partidos\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                vetorPartido = addPartido(vetorPartido, &size, &maxSize);
                break;
            case 2:
                addPartidario(vetorPartido, &size);
                break;
            case 3:
                perguntas(vetorPartido, &size, &posicaoPartido, &posicaoPartidario);
                break;
            case 4:
                exibirPartidario(vetorPartido, &size);
                break;
            case 5:
                exibirPartidos(vetorPartido, &size);
                break;
            case 0:
                free(vetorPartido);
                break;
            default:
                printf("Opcao invalida!");
        }
    }while(opcao != 0);
}

void perguntas(partido *vetor, int *size, int *posicaoPartido, int *posicaoPartidario){
    int id, tam;
    //Somente 20 perguntas podem ser feitas por chamada
    for(int q=0;q<20;q++){
        printf("Partido que ira perguntar: %s\n", vetor[*posicaoPartido].nomePartido);
        printf("Pergunta feita pelo partidario %s\n", vetor[*posicaoPartido].vetorPartidario[*posicaoPartidario].nomePartidario);
        printf("Essa pergunta esta sendo direcionada ao partido (insira o id do partido): ");
        scanf("%d", &id);
        vetor[*posicaoPartido].vetorPartidario[*posicaoPartidario].podeResponder = 0;
        //Varre o vetor 'partido' para encontrar o ID do partido
        for(int i=0;i<*size;i++){
            if(id == vetor[i].idPartido){
                tam = vetor[i].sizePart;
                //Varre o vetor partidario para ver qual o proximo livre para responder
                for(int x=0;x<tam;x++){
                    if(vetor[i].vetorPartidario[x].podeResponder == 1){
                        printf("O partidario %s do partido %s ira responder\n\n", vetor[i].vetorPartidario[x].nomePartidario, vetor[i].nomePartido);
                        *posicaoPartidario = x;
                        *posicaoPartido = i;
                        break;
                    }
                }
                break;
            }
        }
    }
}

void exibirPartidario(partido *vetor, int *size){
    int id, tam;
    printf("Digite a ID do partido ao qual voce deseja ver os partidarios: ");
    scanf("%d", &id);
    //Varre o vetor 'partido' para encontrar o ID do partido
    for(int i=0;i<*size;i++){
        if(id == vetor[i].idPartido){
            tam = vetor[i].sizePart;
            printf("Fazem parte do partido %s\n", vetor[i].nomePartido);
            for(int x=0;x<tam;x++){
                printf("--------\n");
                printf("ID do partidario: %d\n", vetor[i].vetorPartidario[x].idPartidario);
                printf("Nome do partidario: %s\n", vetor[i].vetorPartidario[x].nomePartidario);
                if(vetor[i].vetorPartidario[x].podeResponder == 1)
                    printf("Esse partidario pode responder\n");
                else
                    printf("Esse partidario nao pode responder\n");
                printf("--------\n");
            }
        }
    }
}

void addPartidario(partido *vetor, int *size){
    int id, tam;
    printf("Digite a ID do partido ao qual vai adicionar este partidario: ");
    scanf("%d", &id);
    //Varre o vetor 'partido' para encontrar o ID do partido
    for(int i=0;i<*size;i++){
        if(id == vetor[i].idPartido){
            tam = vetor[i].sizePart;
            if(vetor[i].sizePart < vetor[i].maxSizePart){
                printf("Insira o nome do partidario: ");
                scanf("%s", &vetor[i].vetorPartidario[tam].nomePartidario);
                vetor[i].vetorPartidario[tam].podeResponder = 1;
                vetor[i].vetorPartidario[tam].idPartidario = tam + 1;
                vetor[i].numPartidarios++;
                vetor[i].sizePart++;
            }else{
                tam = vetor[i].sizePart;
                partidario *novoVet;
                vetor[i].maxSizePart = (vetor[i].maxSizePart) * 2;
                novoVet = malloc((vetor[i].maxSizePart)*sizeof(partidario));
                for(int x=0;x<tam;x++)
                    novoVet[x] = vetor[i].vetorPartidario[x];
                vetor[i].vetorPartidario = novoVet;
                printf("Insira o nome do partidario: ");
                scanf("%s", &vetor[i].vetorPartidario[tam].nomePartidario);
                vetor[i].vetorPartidario[tam].podeResponder = 1;
                vetor[i].vetorPartidario[tam].idPartidario = tam + 1;
                vetor[i].numPartidarios++;
                vetor[i].sizePart++;
            }
        }
    }
}

void exibirPartidos(partido *vetor, int *size){
    for(int i=0;i<*size;i++){
        printf("--------\n");
        printf("ID do partido: %d\n", vetor[i].idPartido);
        printf("Nome do partido: %s\n", vetor[i].nomePartido);
        printf("Numero de partidarios: %d\n", vetor[i].numPartidarios);
        printf("--------\n");
    }
}

partido * addPartido(partido *vetor, int *size, int *maxSize){
    if(*size < *maxSize){
        printf("Insira o nome do partido: ");
        scanf("%s", &vetor[*size].nomePartido);
        vetor[*size].idPartido = *size + 1;
        vetor[*size].numPartidarios = 0;
        vetor[*size].sizePart = 0;
        vetor[*size].maxSizePart = 5;
        //Criação do vetor de partidários
        partidario *vet;
        vet = malloc((vetor[*size].maxSizePart)*sizeof(partidario));
        vetor[*size].vetorPartidario = vet;
        (*size)++;
        return vetor;
    }else{
        partido *novoVet;
        *maxSize = (*maxSize) * 2;
        novoVet = malloc(*maxSize*sizeof(partido));
        for(int i=0;i<*size;i++)
            novoVet[i] = vetor[i];
        printf("Insira o nome do partido: ");
        scanf("%s", &novoVet[*size].nomePartido);
        novoVet[*size].idPartido = *size + 1;
        novoVet[*size].numPartidarios = 0;
        novoVet[*size].sizePart = 0;
        novoVet[*size].maxSizePart = 5;
        //Criação do vetor de partidários
        partidario *vet;
        vet = malloc((novoVet[*size].maxSizePart)*sizeof(partidario));
        novoVet[*size].vetorPartidario = vet;
        (*size)++;
        return novoVet;
    }
}

partido * criarPartido(int *size, int *maxSize){
    partido *vetor;
    *size = 0;
    *maxSize = 5;
    vetor = malloc(*maxSize*sizeof(partido));
    return vetor;
}