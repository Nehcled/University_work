#include <stdio.h>

void swap(int * p, int* q){
    int hold = *p;
    *p = *q;
    *q = hold;
}

int main(void){
    int q = 0 , r1 = 0, r2 = 0, r = 0, s1 = 1, s2 = 0, s = 0, t1 = 0, t2 = 1, t = 0,hold1,hold2;
    scanf("%d %d",&r1,&r2);
    printf("  q  | r1  r2 |  r  | s1  s2 |  s  | t1  t2 |  t  \n");
    printf("------------------------------------\n");
    while(r2){
        if(r1<2)swap(&r1,&r2);
        hold1 = r1, hold2 = r2;
        q = r1/r2;
        r = r1%r2;
        r1 = r2;
        r2 = r;

        s = s1-s2*q;
        s1 = s2;
        s2 = s;

        t = t1-t2*q;
        t1 = t2;
        t2 = t;
        printf(" %-3d| %-4d%-3d| %-3d| %-4d%-3d| %-3d| %-4d%-3d| %-3d\n",q,hold1,hold2,r,s1,s2,s,t1,t2,t);
    }
         printf("    | %-4d%-3d|    | %-4d%-3d|    | %-4d%-3d|    \n",r1,r2,s1,s2,t1,t2);
        printf("gcd(%d,%d), (s,t)=(%d,%d)#\n",r1,r2,s1,t1);
    return 0;
}