#include <bits/stdc++.h>
using namespace std;
#define MAXS 100007

int n, q;
int arr[MAXS];
int spt[MAXS][26];


void build(){
  for(int i = 0; i < n; ++i) spt[i][0] = arr[i];

  for(int i = 1; (1<<i) <= n; ++i){
    for(int j = 0; j +(1<<i) <= n; ++j){
      spt[j][i] = max(spt[j][i-1], spt[j+(1<<i-1)][i-1]);
    }
  }
}

int query(int l, int r){
  if(l > r) swap(l, r);
  int lg = __builtin_clz(1) - __builtin_clz(r-l+1);
  return max(spt[l][lg], spt[r-(1<<lg)+1][lg]);
}


int main(){
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> arr[i];
  build();
  cin >> q;
  int a,b ;
  for(int i = 0; i < q; ++i){
    cin >> a >> b;
    cout << query(a, b) << endl;
  }
}