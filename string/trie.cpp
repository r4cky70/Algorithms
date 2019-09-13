
//I'm still working on this code, it dont works


#include <bits/stdc++.h>
using namespace std;

const int MAXS = 100007;

int n, m;
string arr[MAXS], sub[MAXS];

struct node{
  node *point[26];
  bool end;
  node(){
    end = false;
  }
}head;

void build(string s){
  node atual = head;
  for(int i = 0; i < s.size(); ++i){
    int aux = s[i]-'a';
    if(atual.point[aux] == NULL){
      atual.point[aux] = new node();
    }
    atual = *atual.point[aux];
  }
  atual.end = true;
}

bool search(string t){
  node atual = head;
  for(int i = 0; i < t.size(); ++i){
    int aux = t[i]-'a';
    if(atual.point[aux] != NULL){
      atual = *atual.point[aux];
      cout << aux+'a';
    }
  }
  cout << endl;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
    build(arr[i]);
  }
  cin >> m;
  for(int i = 0; i < m; ++i){
    cin >> sub[i];
    search(sub[i]);
  }
}
