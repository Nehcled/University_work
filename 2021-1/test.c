#include<stdio.h>
#include<stdlib.h>

int main(void){
    int acol=0,arow=0,acount=0,bcol=0,brow=0,bcount=0;
    scanf("%d %d %d",&arow,&acol,&acount);
    int **amatrix = malloc(sizeof(int*)*arow*acol);
    for(int i = 0; i < arow; i++){
        amatrix[i] = calloc(1,sizeof(int)*acol);
    }
    for(int i = 0; i < acount; i++){
        int col = 0,row = 0;
        scanf("%d %d",&col,&row);
        scanf("%d",&amatrix[col][row]);
    }

    
    scanf("%d %d %d",&brow,&bcol,&bcount);
    int **bmatrix = malloc(sizeof(int*)*brow*bcol);
    for(int i = 0; i < brow; i++){
        bmatrix[i] = calloc(1,sizeof(int)*bcol);
    }
    for(int i = 0; i < bcount; i++){
        int col = 0,row = 0;
        scanf("%d %d",&col,&row);
        scanf("%d",&bmatrix[col][row]);
    }
    // printf("\n");
    // for(int i = 0;i < 3; i++){
    //     for(int j = 0;j < 3; j++){
    //         printf("%d", amatrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for(int i = 0;i < 3; i++){
    //     for(int j = 0;j < 3; j++){
    //         printf("%d", bmatrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");  

    int **result = malloc(sizeof(int*)*arow);
    for(int i = 0; i < arow; i++){
        result[i] = calloc(1,sizeof(int)*bcol);
    }
    
    int rconut = 0;
    for(int i = 0; i < arow; i++){
        for(int j = 0;j < bcol; j++){
            for(int k = 0; k < acol; k++){
               result[i][j] += amatrix[i][k]*bmatrix[k][j];
            }
            if(result[i][j])rconut++;
        }
    }
    printf("%d %d %d",arow,bcol,rconut);
    for(int i = 0;i < arow; i++){
        for(int j = 0; j< bcol; j++){
            if(result[i][j])printf("\n%d %d %d",i,j,result[i][j]);
        }
    }
}