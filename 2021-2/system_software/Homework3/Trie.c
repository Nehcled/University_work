#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define DISP 65
typedef struct Trie{
    char c;
    int isSymbol;
    int address;
    struct Trie* children[26];
}Trie;


Trie* createTrie(void);
int insertTrie(Trie*, char*, int);
int searchTrie(Trie*, char*);   
void printTrie(Trie*);
void dfsTrie(Trie*, char*, int);


Trie* createTrie(void){
    Trie* newTrie = (Trie*)calloc(1,sizeof(Trie));
    newTrie->c = '\0';
    newTrie->isSymbol = 0;
    newTrie->address = -1;
    return newTrie;
}


int insertTrie(Trie* trie, char* word, int address){
    char* cptr = word;
    while(*cptr!='\0'){
        if(!trie->children[*cptr-DISP]){
            trie->children[*cptr-DISP] = (Trie*)calloc(1,sizeof(Trie));  
            trie = trie->children[*cptr-DISP];
            trie->c = *cptr;
            trie->address = -1;
        }else{
            trie = trie->children[*cptr-DISP];
        }
        cptr++;
    }
    if(!trie->isSymbol){
        trie->isSymbol = 1;
        trie->address = address;
        return 1;
    }
    return 0;
};

int searchTrie(Trie* trie, char* word){
    char* cptr = word;
    while(*cptr!='\0'){
        if(!trie->children[*cptr-DISP]){
            return -1;
        }
        trie = trie->children[*cptr-DISP];
        cptr++;
    }
    if(trie->isSymbol){
        return trie->address;
    }
    return -1;
}

void printTrie(Trie* trie){
    char buffer[9] = {0}; 
    for(int i = 0; i < 26; i++){
        dfsTrie(trie->children[i], buffer, 0);
    }
};

void dfsTrie(Trie* trie, char* buffer, int length){
    if(!trie)return;
    buffer[length] = trie->c;
    if(trie->isSymbol){
        printf("%-8s :  %06X\n",buffer, trie->address);
    }
    for(int i = 0; i < 26; i++){
        dfsTrie(trie->children[i],buffer,length+1);
    }
    buffer[length] = '\0';
}




// int main(void){
//     Trie* root = createTrie();
//     printf("%d\n",insertTrie(root,"hello",23432));
//     printf("%d\n",search(root,"hello"));
//     printf("%d\n",insertTrie(root,"tpqsds",13245));
//     printf("%d\n",search(root,"c"));
//     printTrie(root);
// }