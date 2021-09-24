#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie{
    char c; // this is only used to denote the node name
    int isWord; // used to mark the end of a word
    struct Trie* next[128]; // the one that will truly identify the node is this one (thru index to ascii)
}Trie;
 
Trie* root = NULL;

char word[101];

Trie* newNode(char c){
    Trie* node = (Trie*)malloc(sizeof(Trie));
    node->c = c;
    node->isWord = 0;
    for(int i = 0; i < 128; i++){
        node->next[i] = NULL;
    }
    return node;
}

void insert(Trie* curr, char* p){
    if (curr->next[*p] == NULL){
        curr->next[*p] = newNode(*p);
    }
    if (*p == '\0') curr->isWord = 1;
    else insert(curr->next[*p], p+1);
}

void find(Trie* curr, int index) {
    if (curr->isWord == 1){
        word[index] = '\0';
        puts(word);
    }
    for (int i = 0; i < 128; i++) {
        if (curr->next[i] != NULL) {
            word[index] = i; // translated to ascii intentionally
            find(curr->next[i], index+1);
        }
    }
}

void findPrefix(char *prefix){
    int okay = 1;
    Trie* curr = root;

    for (int i = 0; i < strlen(prefix); i++){
        if (okay == 1){
            if (curr->next[prefix[i]] == NULL) okay = 0;
            else curr = curr->next[prefix[i]];
        }
    }
    if (okay){
        strcpy(word, prefix);
        find(curr, strlen(prefix));
    }
    
}

int main(void){
    // initialize root
    root = (Trie*)malloc(sizeof(Trie));
    root->c = ' ';
    root->isWord = 0;
    for(int i = 0; i < 128; i++){
        root->next[i] = NULL;
    }

    // input
    int n;
    scanf("%d", &n); getchar();
    for( int i = 0; i < n; i++){
        char s[101];
        scanf("%s", s); getchar();
        insert(root, s);
    }

    // word initializing
    for (int i = 0; i < 101; i++){
        word[i] = ' ';
    }

    char prefix[101];
    scanf("%s", prefix);
    findPrefix(prefix);
}
