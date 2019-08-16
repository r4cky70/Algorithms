#include <bits/stdc++.h>
using namespace std;
#define MAXS 1000007
#define INF 2147000000

vector<pair <int, int>> edges[MAXS]; // pair<peso, no>
int dis[MAXS];
int n;

void dijkstra(int no){
  fill(dis, dis+n+1, INF);
  priority_queue < pair<int,int > , vector <pair<int,int> >,greater<pair<int,int> > > fila;
  dis[no] = 0;
  fila.push(make_pair(0, no));
  while(!fila.empty()){
    int peso = fila.top().first;
    int node = fila.top().second;
    fila.pop();
    if(dis[node] < peso) continue;
    for(int i = 0; i < edges[node].size(); ++i){
      pair<int, int> temp = edges[node][i];
      if(dis[temp.second] > dis[node] + temp.first){
        dis[temp.second] = dis[node] + temp.first;
        fila.push(make_pair(dis[temp.second], temp.second));
      }
    }
  }
}