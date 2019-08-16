#include <bits/stdc++.h>
using namespace std;

#define MAXS

int pai[MAXS];
int tamanho[MAXS];


int find(int a){
  if(pai[a] == a) return a;
  return pai[a] = find(pai[a]);
}

void uni(int a, int b){
  int A = find(a), B = find(b);

  if(A == B) return;
  if(A < B){
    pai[A] = B;
    tamanho[B] += tamanho[A];
  }else{
    pai[B] = A;
    tamanho[A] += tamanho[B];
  }
}


int main(){
  iota(pai, pai + MAXS, 0);
  fill(tamanho, tamanho + MAXS, 1);
}