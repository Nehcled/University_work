#include<stdio.h>
#include<string.h>

int main(void){
    char str[20];
    memset(str,'$',20);
    for(int i = 0; i < 20; i++){
        printf("%c",str[i]);
    }
    return 0;
}
