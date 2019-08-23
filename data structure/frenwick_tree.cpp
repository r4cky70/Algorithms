#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXS 10007

int arr[MAXS];
int ftree[MAXS];
int n;

void update(int id, int v){
  while(id<=MAXS){
    ftree[id] += v;
    id+=id&-id;
  }
}
ll query(int id){
  ll acu = 0;
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