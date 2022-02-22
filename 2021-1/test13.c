#include<stdio.h>
#include<string.h>

int main(void){
    char in[16] = {0};
    int len,temp,count = 0;
    while(scanf("%s",in)!=EOF){
        printf("%d. ",++count);
        len = strlen(in);
    
        for(int i = 0; i < len; i++){
            temp = (len-i)%8+(len-i>7);
            if(temp>5){
                printf("%c%c lakh ",in[i],in[i+1]);
                i++;
            }else if(temp>3){
                printf("%c%c hajar ",in[i],in[i+1]);
                i++;
            }else if(temp>2){
                printf("%c shata ",in[i]);
            }else if(temp>1){
                printf("%c%c%s",in[i],in[i+1],len-i>7?" kuti ":"\n");
                i++;
            }else if(temp>0){
                printf("%c%s",in[i],len-i>7?" kuti ":"\n");
            }
        }
    }
    return 0;

}