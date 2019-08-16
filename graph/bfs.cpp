#include <bits/stdc++.h>
using namespace std;
#define MAXS 10000


int n, m;
bitset<MAXS> vis;
vector<int> edges[MAXS];

void bfs(int no){
  queue<int> fila;
  fila.push(no);
  vis[no] = true;
  while(!fila.empty()){
    int temp = fila.front();
    fila.pop();
    for(auto node : edges[temp]){
      if(!vis[node]){
        fila.push(node);
        vis[node] = true;
      }
    }
  }
}


int main(){

}