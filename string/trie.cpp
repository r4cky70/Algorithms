
#include <bits/stdc++.h>
using namespace std;

struct node{
  node *point[26];
  bool end;
}*head;

void init(){
  head = new node();
  head->end = false;  
}

void build(string s){
  node *atual = head;
  for(int i = 0; i < s.size(); ++i){
    int aux = s[i]-'a';
    if(atual->point[aux] == nullptr){
      atual->point[aux] = new node();
    }
    atual = atual->point[aux];
  }
  atual->end = true;
}

void search(string t){
  node *atual = head;
  for(int i = 0; i < t.size(); ++i){
    int aux = t[i]-'a';
    if(atual->point[aux] != nullptr){
      atual = atual->point[aux];
    }
  }
}

int main(){
  init(); 
}
