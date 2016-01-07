#include <stdio.h>
//#include <malloc.h>
#include <stdlib.h>

void print_matrix_diagonal(int m,int n,int **M)
{
    if(NULL == M) {
        printf("The matrix is empty!\n");
        return;
    }
    int row = m;
    int col = n;
    int i_ini = 0;
    int j_ini = 0;
    int i,j;

    int counter = 1;
    while(counter <= (row + col -1)) {
        i = i_ini;
        j = j_ini;
        do {
            printf("%d ",M[i][j]);
            i--;
            j++;
        }while(i >= 0 && j <= col - 1);
        printf("\n");
        counter++;
        (counter > row ) ? (i_ini = row - 1,j_ini++) : (i_ini++,j_ini = 0);
    }
    return;
}

void print_matrix_normal(int m,int n,int **M)
{
    if(NULL == M) {
        printf("The matrix is empty!\n");
        return;
    }

    int i,j;
    for(i = 0;i < m;i++) {
        for(j = 0;j < n;j++) {
            printf("%4d ",M[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(int argc,char **argv)
{
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    int **arr = (int**)malloc(sizeof(int*) * row);
    int i,j;
    for(i = 0;i < row;i++) {
        arr[i] = (int*)malloc(sizeof(int) * col);
    }

    int count = 1;
    for(i = 0;i < row;i++) {
        for(j = 0;j < col;j++) {
            arr[i][j] = count;
            count++;
        }
    }

    print_matrix_normal(row,col,arr);
    printf("++++++++++++++++++\n");
    print_matrix_diagonal(row,col,arr);
    return 0;
}
