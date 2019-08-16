#include <bits/stdc++.h>
using namespace std;
#define MAXS 100000

int arr[MAXS];

struct seg_tree{
  int tree[4*MAXS];

  void build(int no, int l, int r){
    if(l == r) tree[no] = arr[l];
    else{
      int mid = (l+r)/2;
      build(no*2, l, mid);
      build(no*2+1, mid+1, r);
      tree[no] = tree[no*2] + tree[no*2+1];
    }
  }
  void update(int no, int l, int r, int x, int v){
    if(l == r) tree[no] = v;
    else{
      int mid = (l+r)/2;
      if(mid >= x) update(no*2, l, mid, x, v);
      else update(no*2+1, mid+1, r, x, v);
      tree[no] = tree[no*2] + tree[no*2+1];
    }
  }
  int query(int no, int l, int r, int x, int y){
    if(r < x || l > y) return 0;
    if(l >= x && r <= y) return tree[no];
    int mid = (l+r)/2;
    return query(no*2, l, mid, x, y) + query(no*2+1, mid+1, r, x, y);
  }
}root;



int main(){
  
  freopen("input.txt", "r", stdin);

  int n; cin >> n;
  for(int i  = 0; i < n; ++i){
    cin >> arr[i];
  }
  root.build(1, 0, n-1);
  int m; cin >> m;
  int a, b, c;
  for(int i = 0; i < m; ++i){
    cin >> a >> b >> c;
    if(a == 1){
      root.update(1, 0, n-1, b, c);
    }else{
      cout << root.query(1, 0, n-1, b, c) << endl;
    }
  }
}