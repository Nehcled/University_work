#include<iostream>
#include<cmath>
#include<iomanip>

#define MAX 100
using namespace std;

int main(int argc, char** argv){
    int array[MAX];
    for(int i = 0; i < MAX; i++){
        cout << i << " ";
    }
    cout << endl;
    const double pi = acos(-1.0);
    cout << setprecision(15) << pi << endl;
}