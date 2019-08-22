#include <bits/stdc++.h>
using namespace std;
#define MAXS 10007

int arr[MAXS];
int ftree[MAXS];
int n;

void update(int id, int v){
  while(id<=n){
    ftree[id] += v;
    id+=id&-id;
  }
}
int query(int id){
  int acu = 0;
  while(id>0){
    acu+=ftree[id];
    id-=id&-id;
  }
  return acu;
}
int a, q;


int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> arr[i];
  }
  for(int i = 1 ; i <= n; ++i){
    update(i, arr[i]);
  }
  query(1); query(n);
}