#include <stdio.h>

void somaMat(double mat1[100][100], double mat2[100][100], double matRes[100][100], int n);
void exibirMatrizes(double mat1[100][100], double mat2[100][100], int n);

void main(){
    int n = 6;
    double mat1[100][100];
    double mat2[100][100];
    double matRes[100][100];

    // Preencher a primeira matriz
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            mat1[x][y] = y;
        }
    }
    // Preencher a segunda matriz
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            mat2[x][y] = y;
        }
    }

    exibirMatrizes(mat1, mat2, n);
    somaMat(mat1, mat2, matRes, n);
}

void somaMat(double mat1[100][100], double mat2[100][100], double matRes[100][100], int n){
    //Soma
    printf("\nMatriz Soma\n");
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            matRes[x][y] = mat1[x][y] + mat2[x][y];
            printf("%1.lf\t", matRes[x][y]);
        }
        printf("\n");
    }
}

void exibirMatrizes(double mat1[100][100], double mat2[100][100], int n){
    //Matriz 1
    printf("Matriz 1\n");
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            printf("%.1lf \t", mat1[x][y]);
        }
        printf("\n");
    }
    printf("\nMatriz 2\n");
    //Matriz 2
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            printf("%.1lf \t", mat2[x][y]);
        }
        printf("\n");
    }    
}