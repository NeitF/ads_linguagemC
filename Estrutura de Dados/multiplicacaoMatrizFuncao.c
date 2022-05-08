#include <stdio.h>

void multiplicaMat(double mat1[100][100], double mat2[100][100], double matRes[100][100], int n);
void preencherMatrizes(double mat1[100][100], double mat2[100][100], double matRes[100][100], int);
void exibirMatrizes(double mat1[100][100], double mat2[100][100], double matRes[100][100], int n);

void main(){
    double mat1[100][100], mat2[100][100], matRes[100][100];
    int n = 3;

    preencherMatrizes(mat1, mat2, matRes, n);
    multiplicaMat(mat1, mat2, matRes, n);
    exibirMatrizes(mat1, mat2, matRes, n);
}

void multiplicaMat(double mat1[100][100], double mat2[100][100], double matRes[100][100], int n){
    double val=0;
    int x, repeticao;
    for(int i=0;i<n;i++){
        x = 0;
        repeticao = 0;
        for(int j=0;j<n;j++){
            val += mat1[i][j] * mat2[j][x];

            if(j == (n-1)){
            matRes[i][repeticao] = val;
            val = 0;
                if(repeticao != n){
                    j = -1;
                    repeticao++;
                    x++;
                }
            }
        }
    }
}

void preencherMatrizes(double mat1[100][100], double mat2[100][100], double matRes[100][100], int n){
    //Matriz 1
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat1[i][j] = (j+1);
        }
    }
    
    //Matriz 2
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat2[i][j] = (j+1);
        }
    }

    //Matriz Respota
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matRes[i][j] = 0;
        }
    }
}

void exibirMatrizes(double mat1[100][100], double mat2[100][100], double matRes[100][100], int n){
    //Matriz 1
    printf("Matriz 1\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%.1lf \t", mat1[i][j]);
        }
        printf("\n");
    }
    //Matriz 2
    printf("\nMatriz 2\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%.1lf \t", mat2[i][j]);
        }
        printf("\n");
    }
    //Matriz Resposta
    printf("\nMatriz Resposta\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%.1lf \t", matRes[i][j]);
        }
        printf("\n");
    }
}