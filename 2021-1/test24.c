#include<stdio.h>
#include<string.h>
int cmp(char* s1,char*s2){
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    if(s2len>s1len){
        char* hold = s2;
        s2 = s1;
        s1 = hold;
        s1len^=s2len;
        s2len^=s1len;
        s1len^=s2len;
    }
    
    int dif = 0;
    for(int i = 0; i+dif < s1len && i < s2len; i++){
        if(s1[i+dif]!=s2[i]){
            dif++;
        }
    }
    return dif+(s1len-s2len);
    
}
int main(void){
    printf("%d",cmp("acbd","abbd"));
}