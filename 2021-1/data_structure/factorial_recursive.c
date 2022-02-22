#include<stdio.h>

int factorial(int n);
int factorialItv(int n);

int fibonacci(int n,int pre1, int pre2);
int fibonacciItv(int n);

int main(void){
    for(int i = 0;i < 20; i++){
        printf("%d\n",fibonacciItv(i));
    }
}
//space complexity:
//parameter: integer "n": 4 bytes
//return address(internally): 4 bytes
//total per recursive call: 8 bytes 
int factorial(int n){
    if(n<=1)return 1;
    return n*factorial(n-1);
}
//space complexity:
//parmenter: integer "n": 4 bytes
//variable: integer "sum": 4 bytes
//variable: integer "i": 4 bytes
//return address(internally): 4 bytes
//total: 16 bytes 
int factorialItv(int n){
    int sum = 1;
    for(int i = 1; i <= n; i++){
        sum*=i;
    }
    // while(n){
    //     sum*=n;
    //     n--;
    // }
    return sum;
}


//space complexity:
//parameter: interger "n" : 4 bytes
//parameter: interger "pre1": 4 bytes
//parameter: interger "pre2": 4 bytes
//return address(internally): 4 bytes
//total per recursive call: 16 bytes
int fibonacci(int n,int pre1, int pre2){
    if(!n)return pre1;
    return fibonacci(n-1,pre2,pre1+pre2);
}


//spcae complexity:
//parameter: interger "n" : 4 bytes
//variable: integer "pare1": 4 bytes
//variable: integer "pare2": 4 bytes
//variable: integer "curt": 4 bytes
//variable: integer "i": 4 bytes
//return address(internally): 4 bytes
//total: 24 bytes
int fibonacciItv(int n){
    int pre1=0,pre2=1,curt;
    for(int i = 0; i < n; i++){
        curt = pre1+pre2;
        pre1 = pre2;
        pre2 = curt;
    }
    return pre1;
}
