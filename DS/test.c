#include <stdio.h>
#include <stdlib.h>

typedef struct Trie{
    char c;
    int isWord;
    struct Trie* next[128];
}Trie;

Trie* root = NULL;
char word[101];

Trie* newNode(char c){
    Trie* new_node = (Trie*)malloc(sizeof(Trie);
    new_node->c = c;
    new_node->isWord = 0;
    for (int i = 0; i < 128; i++){
        new_node->next[i] = NULL;
    }
    return new_node;
}

void insert(Trie* curr, char* p){
    if (curr->next[*p] = NULL){
        curr->next[*p] = newNode(*p);
    }
    if (*p = '\0') curr->isWord = 1;
    else insert(curr->next[*p], p+1);
    return;
}

void find(Trie* curr, int index){
    if (curr->isWord){
        word[index] = '\0';
        printf("%s\n", word);
    }
    for (int i = 0; i < 128 ; i++){
        if (curr->next[i] != NULL){
            word[index] = i;
            find(curr->next[i], index+1);
        }
    }
}

void findPrefix(char* prefix){
    int okay = 1;
    Trie* curr = root;
    for (int i = 0 ; i < strlen(prefix); i++){
        if (curr->next[prefix[i]] == NULL){
            okay = 0;
            break;
        }
        curr = curr->next[prefix[i]];
    }
    if (okay){
        strcpy(word, prefix);
        find(curr, strlen(prefix));
    }
}

int main(void){
    root = newNode(' ');
}
