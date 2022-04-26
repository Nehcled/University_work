#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SUM(arr, size) (for(int i = 0, sum = 0; i < size; sum+=arr[i++]))

int main(void) {
    // int t,k,a,b,p;
    // long long sum;
    // int arr[4] = {0,1,1,2};
    // scanf("%d", &t);
    // for(int run = 0; run < t; run++){
    //     scanf("%d%d%d",&k,&a,&b);
    //     sum = 0;
    //     for(int i = a-1; i < b; i++){
    //         printf("%d %lf\n",pow(2,k-i/4-arr[i%4]));
    //         sum+=pow(2,k-i/4-arr[i%4]);
    //     }
    //     printf("Case %d: %lld\n",run+1,sum);
    // }
    int arr[3] = {1,2,3};
    int size = 3;
    
    printf("%d", SUM(arr, size));
    return 0;
}