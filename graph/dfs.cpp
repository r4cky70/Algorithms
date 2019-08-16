#include <bits/stdc++.h>
using namespace std;
#define MAXS 1000007

bool vis[MAXS];
vector<int> edges[MAXS];
int target, n;

void dfs(int no){
  vis[no] = true;
  for(int i = 0; i < edges[no].size(); ++i){
    int node = edges[no][i];
    if(!vis[node]){
      dfs(node);
    }
  }
}