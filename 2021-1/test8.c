#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Trie{
    int exist;
    char val;
    struct Trie *next[26];
}Trie;

Trie* createTrie(int type){
    Trie* newTrie = malloc(sizeof(Trie));
    newTrie->exist = 0;
    newTrie->val = type?'0':'\0';
    for(int i = 0; i < 26; i++){
        (newTrie->next)[i] = NULL;
    }
    return newTrie;
}

void push(Trie* obj, char* s){
    if(strlen(s)==1&&obj->val == s[0]){
        obj->exist = 1;
        return;
    }
	
	int isHead = obj->val=='0'?0:1;
	if(isHead&&s[1]=='\0')return ;
	
    if(!(obj->next)[s[isHead]-'a']){
        (obj->next)[s[isHead]-'a'] = createTrie(0);
		(obj->next)[s[isHead]-'a']->val = s[isHead];
    }
    push((obj->next)[s[isHead]-'a'],s+isHead);
}

int search(Trie *obj, char* target){
    // printf("%s exist:%d val:%c\n",target,obj->exist,obj->val);
    if(!obj)return 0;
	if(strlen(target)==1){
        return obj->exist;
    }
    
	if(obj->val!='0'){
		return search((obj->next)[target[1]-'a'],target+1);
	}
    return search((obj->next)[target[0]-'a'],target);
}