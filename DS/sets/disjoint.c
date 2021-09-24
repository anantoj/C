#include <stdio.h>
#define MAXN 100

int Parent[MAXN + 10];

void makeSet(int n){
    for (int i = 0; i < n; i++){
        Parent[i] = i;
    }
    return;
}

int findParent(int a){
    if (Parent[a] == a) return a;
//  return findParent(Parent[a]);
    return Parent[a] = findParent(Parent[a]); // path compression
}

int isSameSet(int a, int b){
    return findParent(a) == findParent(b);
}

void merge(int a, int b){
    Parent[findParent(a)] = findParent(b);
    return;
}


int main(void){

}


