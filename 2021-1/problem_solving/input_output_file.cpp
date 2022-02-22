#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char** argv){
    ifstream in("input.txt");
    ofstream out("output.txt");
    string s;

    while(getline(in,s)){
        out << s << endl;
    }
}