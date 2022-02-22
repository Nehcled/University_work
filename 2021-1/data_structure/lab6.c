#include<stdio.h>
#include<stdlib.h>

#define N maze[i-1][j]
#define NE maze[i-1][j+1]
#define E maze[i][j+1]
#define ES maze[i+1][j+1]
#define S maze[i+1][j]
#define SW maze[i+1][j-1]
#define W maze[i][j-1]
#define WN maze[i-1][j-1]


typedef struct Stack{
    int row;
    int col;
    int size;
    int step;
    int** pos;
    struct Stack* next;
}Stack;

Stack* createStack(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->next = NULL;
    newStack->size = 0;
    return newStack;
}

void pushStack(Stack* obj, int row, int col){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->next = obj->next;
    newStack->size = obj->size+1;
    newStack->row = row;
    newStack->col = col;
    newStack->step = 0;
    newStack->pos = malloc(sizeof(int*)*7);
    obj->next = newStack;
    obj->size++;
}

void popStack(Stack* obj){
    if(!obj->size)return;
    Stack* hold = obj->next;
    obj->next = hold->next;
    obj->size--;
    free(hold);
}

Stack* topStack(Stack* obj){
    return obj->next;
}

void printStack(Stack* obj){
    Stack* curt = obj->next;
    while(curt){
        printf("%d %d->",curt->row,curt->col);
        curt = curt->next;
    }
    printf("\n");
}




int main(void){
    int mazeRow,mazeCol,i,j,ti,tj;
    scanf("%d %d",&mazeRow,&mazeCol);

    int **maze = malloc(sizeof(int*)*mazeRow);
    for(i = 0; i < mazeRow; i++){
        maze[i] = malloc(sizeof(int)*mazeCol);
    }

    for(i = 0; i < mazeRow; i++){
        int val;
        scanf("%d",&val);
        for(j = 0; j < mazeCol; j++){
            maze[i][mazeCol-1-j] = val%10;
            val/=10;
        }
    }
    i = j = 1;
    ti = mazeRow-2; tj = mazeCol-2;
    
    Stack* stack = createStack();

    do{
        pushStack(stack,i,j);
        Stack* top = topStack(stack);
        maze[i][j] = 2;
        if(i&&j&&WN==0){
            int* pos = malloc(sizeof(int));
            pos[0] = i-1;
            pos[1] = j-1;
            top->pos[top->step++] = pos;
            // WN = 2;
        }
        if(j&&W==0){
            int* pos = malloc(sizeof(int));
            pos[0] = i;
            pos[1] = j-1;
            top->pos[top->step++] = pos;
            // W = 2;
        }
        if(i<mazeRow-1&&j&&SW==0){
            int* pos = malloc(sizeof(int));
            pos[0] = i+1;
            pos[1] = j-1;
            top->pos[top->step++] = pos;
            // SW = 2;
        }
        if(i<mazeRow-1&&S==0){
            int* pos = malloc(sizeof(int));
            pos[0] = i+1;
            pos[1] = j;
            top->pos[top->step++] = pos;
            // S = 2;
        }
        if(i<mazeRow-1&&j<mazeCol-1&&ES==0){
            int* pos = malloc(sizeof(int));
            pos[0] = i+1;
            pos[1] = j+1;
            top->pos[top->step++] = pos;
            // ES = 2;
        }
        if(j<mazeCol-1&&E==0){
            int* pos = malloc(sizeof(int));
            pos[0] = i;
            pos[1] = j+1;
            top->pos[top->step++] = pos;
            // E = 2;
        }
        if(i&&j<mazeCol-1&&NE==0){
            int* pos = malloc(sizeof(int));
            pos[0] = i-1;
            pos[1] = j+1;
            top->pos[top->step++] = pos;
            // NE = 2;
        }
        if(i&&N==0){
            int* pos = malloc(sizeof(int));
            pos[0] = i-1;
            pos[1] = j;
            top->pos[top->step++] = pos;
            // N=2;
        }
        while(top->step==0){
            maze[top->row][top->col] = 0;
            popStack(stack);
            top = topStack(stack);
        }
        
        top->step--;
        i = top->pos[top->step][0];
        j = top->pos[top->step][1];
    }while((i!=ti||j!=tj)&&stack->size);

    int **print = malloc(sizeof(int*)*(stack->size+1));
    int size = stack->size;
    print[0] = malloc(sizeof(int)*2);
    print[0][0] = ti;
    print[0][1] = tj;

    // printf("stackSize:%d\n",stack->size);
    for(i = 1; i <=size; i++){
        print[i] = malloc(sizeof(int)*2);
        Stack* hold = topStack(stack);
        print[i][0] = hold->row;
        print[i][1] = hold->col;
        popStack(stack);
    }
    // for(int i = 0;i <= size; i++){
    //     printf("%d %d\n",print[i][0],print[i][1]);
    // }
    
    for(i = size; i>0; i--){
        int* curt=print[i],*next=print[i-1];
        if(next[0] == curt[0]-1&&next[1]==curt[1]){
            printf("R%d C%d D%d\n",curt[0],curt[1],0);
        }else if(next[0] == curt[0]-1&&next[1]==curt[1]+1){
            printf("R%d C%d D%d\n",curt[0],curt[1],1);
        }else if(next[0] == curt[0]&&next[1]==curt[1]+1){
            printf("R%d C%d D%d\n",curt[0],curt[1],2);
        }else if(next[0] == curt[0]+1&&next[1]==curt[1]+1){
            printf("R%d C%d D%d\n",curt[0],curt[1],3);
        }else if(next[0] == curt[0]+1&&next[1]==curt[1]){
            printf("R%d C%d D%d\n",curt[0],curt[1],4);
        }else if(next[0] == curt[0]+1&&next[1]==curt[1]-1){
            printf("R%d C%d D%d\n",curt[0],curt[1],5);
        }else if(next[0] == curt[0]&&next[1]==curt[1]-1){
            printf("R%d C%d D%d\n",curt[0],curt[1],6);
        }else if(next[0] == curt[0]-1&&next[1]==curt[1]-1){
            printf("R%d C%d D%d\n",curt[0],curt[1],7);
        }
    }
    printf("R%d C%d D*\n\n",print[0][0],print[0][1]);
    return 0;   
}

/*
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 1 0 0 0 1 1 1 1 1 1
1 1 0 0 0 1 1 0 1 1 1 0 0 1 1 1 1
1 0 1 1 0 0 0 0 1 1 1 1 0 0 1 1 1
1 1 1 0 1 1 1 1 0 1 1 0 1 1 0 0 1
1 1 1 0 1 0 0 1 0 1 1 1 1 1 1 1 1
1 0 0 1 1 0 1 1 1 0 1 0 0 1 0 1 1
1 0 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1
1 0 0 1 1 0 1 1 0 1 1 1 1 1 0 1 1
1 1 1 0 0 0 1 1 0 1 1 0 0 0 0 0 1
1 0 0 1 1 1 1 1 0 0 0 1 1 1 1 0 1
1 0 1 0 0 1 1 1 1 1 0 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/

// R1 C1 D2
// R1 C2 D4
// R2 C2 D3
// R3 C3 D1
// R2 C4 D4
// R3 C4 D4
// R4 C4 D3
// R5 C5 D*


