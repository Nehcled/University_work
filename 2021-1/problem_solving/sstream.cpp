#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main(void){
    string s, tmp;
    while (getline(cin, s)){
        for (int i = 0; i <= s.length(); i++){
            if (isalpha(s[i])){
                s[i] = tolower(s[i]);
            }
            else{
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        while (ss >> tmp){
            cout << tmp << endl;
        }
    }
    return 0;
}