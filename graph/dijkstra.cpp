#include <bits/stdc++.h>
using namespace std;
#define MAXS 1000007

vector<pair <int, int>> edges[MAXS]; // pair<peso, no>
int dis[MAXS];

int dijkstra(int no){
  priority_queue <pair<int,int>, vector <pair<int,int>>,greater<pair<int,int>>> fila;
  fila.push(make_pair(no, 0));
  while(!fila.empty()){
    int peso = fila.top().first;
    int node = fila.top().second;
    fila.pop();
    if(dis[node] < peso) continue;
    for(int i = 0; i < edges[node].size(); ++i){
      pair<int, int> temp = edges[node][i];
      if(dis[temp.second] < dis[node] + temp.first){
        dis[temp.second] = dis[node] + temp.first;
        fila.push(make_pair(dis[temp.second], temp.second));
      }
    }
  }
}