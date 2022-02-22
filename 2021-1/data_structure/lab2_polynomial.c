#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Poly{
    int coefficient;
    int power;
}Poly;

int cmp(const void* a, const void* b){
    return ((Poly*)b)->power-((Poly*)a)->power;
}
int main(void){
    Poly poly[200];
    int length = 0;
    int stay = 0;
    while(1){
        if(scanf("%c",&stay)==EOF)break;
        if(!isdigit(stay))continue;
        if(length%2){
            poly[length/2].power = stay-'0';
        }else{
            poly[length/2].coefficient = stay-'0';
        }
        length++;
    }
    length/=2;

    qsort(poly,length,sizeof(Poly),cmp);
   
    int coe = 0,pow = -1;
    for(int i = 0 ;i< length; i++){
        if(pow!=-1&&pow!=poly[i].power){
            printf("%dX^%d ",coe,pow);
            pow = poly[i].power;
            coe = 0;
        }
        coe+=poly[i].coefficient;
        pow =poly[i].power;
        if(i==length-1)printf("%dX^%d",coe,pow);
    }

    return 0;
}

// int main(void){
//     char in1[200];
//     char in2[200];
//     scanf("%s %s",in1,in2);
//     int resultlen = 0;
//     Poly result[200];
//     for(int i = 0; i < strlen(in1)/2;i++){
//         result[i].coefficient = in1[i*2]-'0';
//         result[i].power = in1[i*2+1]-'0';
        
//     }
//     resultlen+=strlen(in1)/2;
//     for(int i = 0; i < strlen(in2)/2; i++){
//         result[resultlen+i].coefficient = in2[i*2]-'0';
//         result[resultlen+i].power = in2[i*2+1]-'0';
//     }
//     resultlen+=strlen(in2)/2;
//     qsort(result,resultlen,sizeof(Poly),cmp);
   
//     int coe = 0,pow = -1;
//     for(int i = 0 ;i< resultlen; i++){
//         if(pow!=-1&&pow!=result[i].power){
//             printf("%dX^%d ",coe,pow);
//             pow = result[i].power;
//             coe = 0;
//         }
//         coe+=result[i].coefficient;
//         pow =result[i].power;
//         if(i==resultlen-1)printf("%dX^%d",coe,pow);
//     }

//     return 0;
// }
