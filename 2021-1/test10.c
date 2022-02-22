#include<stdio.h>
#include<stdlib.h>
// while(1){
//         int asum;
//         int output=-1;
//         int box[5];
//         scanf("%d %d %d %d %d",&box[0],&box[1],&box[2],&box[3],&box[4]);
//         asum = box[0]^box[1]^box[2]^box[4];
//         printf("%d | %d %d %d %d %d | %d\n",asum,box[0],box[1],box[2],box[3],box[4],output);
//         for(int i = 0; i < 25; i++){
//             output = box[4];
//             box[4] = box[3];
//             box[3] = box[2];
//             box[2] = box[1];
//             box[1] = box[0];
//             box[0] = asum;
//             asum = box[0]^box[1]^box[2]^box[4];
//             printf("%d | %d %d %d %d %d | %d\n",asum,box[0],box[1],box[2],box[3],box[4],output);
//         }
//         printf("\n");
//     }
void init(int* origin, int* box){
    for(int i = 0; i < 5; i++){
        box[i] = origin[i];
    }
}

int main(void){
    int asum;
    int output=-1;
    int box[5];
    int origin[5];
    printf("Seed: ");
    scanf("%d %d %d %d %d",&origin[4],&origin[3],&origin[2],&origin[1],&origin[0]);

    
    //00000
    printf("00000:");
    init(origin,box);
    asum = 0;
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = 0;
        printf("%d",output);
    }
    printf("\n");
    //00001
    printf("00001:");
    init(origin,box);
    asum = box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[0];
        printf("%d",output);
    }
    printf("\n");
    //00010
    printf("00010:");
    init(origin,box);
    asum = box[1];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[1];
        printf("%d",output);
    }
    printf("\n");
    //00011
    printf("00011:");
    init(origin,box);
    asum = box[1]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[1]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //00100
    printf("00100:");
    init(origin,box);
    asum = box[2];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[2];
        printf("%d",output);
    }
    printf("\n");
    //00101
    printf("00101:");
    init(origin,box);
    asum = box[2]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[2]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //00110
    printf("00110:");
    init(origin,box);
    asum = box[2]^box[1];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[2]^box[1];
        printf("%d",output);
    }
    printf("\n");
    //00111
    printf("00111:");
    init(origin,box);
    asum = box[2]^box[1]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[2]^box[1]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //01000
    printf("01000:");
    init(origin,box);
    asum = box[3];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[3];
        printf("%d",output);
    }
    printf("\n");
    //01001
    printf("01001:");
    init(origin,box);
    asum = box[3]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[3]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //01010
    printf("01010:");
    init(origin,box);
    asum = box[3]^box[1];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[2]^box[1];
        printf("%d",output);
    }
    printf("\n");
    //01011
    printf("01011:");
    init(origin,box);
    asum = box[3]^box[1]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[3]^box[1]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //01100
    printf("01100:");
    init(origin,box);
    asum = box[3]^box[2];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[3]^box[2];
        printf("%d",output);
    }
    printf("\n");
    //01101
    printf("01101:");
    init(origin,box);
    asum = box[3]^box[2]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[3]^box[2]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //01110
    printf("01110:");
    init(origin,box);
    asum = box[3]^box[2]^box[1];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[3]^box[2]^box[1];
        printf("%d",output);
    }
    printf("\n");
    //01111
    printf("01111:");
    init(origin,box);
    asum = box[3]^box[2]^box[1]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[3]^box[2]^box[1]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //10000
    printf("10000:");
    init(origin,box);
    asum = box[4];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4];
        printf("%d",output);
    }
    printf("\n");
    //10001
    printf("10001:");
    init(origin,box);
    asum = box[4]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //10010
    printf("10010:");
    init(origin,box);
    asum = box[4]^box[1];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[1];
        printf("%d",output);
    }
    printf("\n");
    //10011
    printf("10011:");
    init(origin,box);
    asum = box[4]^box[1]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[1]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //10100
    printf("10100:");
    init(origin,box);
    asum = box[4]^box[2];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[2];
        printf("%d",output);
    }
    printf("\n");
    //10101
    printf("10101:");
    init(origin,box);
    asum = box[4]^box[2]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[2]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //10110
    printf("10110:");
    init(origin,box);
    asum = box[4]^box[2]^box[1];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[2]^box[1];
        printf("%d",output);
    }
    printf("\n");
    //10111
    printf("10111:");
    init(origin,box);
    asum = box[4]^box[2]^box[1]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[2]^box[1]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //11000
    printf("11000:");
    init(origin,box);
    asum = box[4]^box[3];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[3];
        printf("%d",output);
    }
    printf("\n");
    //11001
    printf("11001:");
    init(origin,box);
    asum = box[4]^box[3]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[3]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //11010
    printf("11010:");
    init(origin,box);
    asum = box[4]^box[3]^box[1];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[3]^box[1];
        printf("%d",output);
    }
    printf("\n");
    //11011
    printf("11011:");
    init(origin,box);
    asum = box[4]^box[3]^box[1]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[3]^box[1]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //11100
    printf("11100:");
    init(origin,box);
    asum = box[4]^box[3]^box[2];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[3]^box[2];
        printf("%d",output);
    }
    printf("\n");
    //11101
    printf("11101:");
    init(origin,box);
    asum = box[4]^box[3]^box[2]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[3]^box[2]^box[0];
        printf("%d",output);
    }
    printf("\n");
    //11110
    printf("11110:");
    init(origin,box);
    asum = box[4]^box[3]^box[2]^box[1];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[3]^box[2]^box[1];
        printf("%d",output);
    }
    printf("\n");
    //11111
    printf("11111:");
    init(origin,box);
    asum = box[4]^box[3]^box[2]^box[1]^box[0];
    for(int i = 0; i < 25; i++){
        output = box[0];
        box[0] = box[1];
        box[1] = box[2];
        box[2] = box[3];
        box[3] = box[4];
        box[4] = asum;
        asum = box[4]^box[3]^box[2]^box[1]^box[0];
        printf("%d",output);
    }
    printf("\n");

}