#include <bits/stdc++.h>
using namespace std;
#define MAXS 100000

int n, q;
int arr[MAXS];

int merge(int a, int b){
  return a + b;
}

struct seg_tree{
  int tree[4*MAXS];
  int lazy[4*MAXS];

  void push(int no, int l, int r){
    tree[no] = lazy[no]*(r-l+1) + tree[no];
    if(l != r){
      lazy[no*2] += lazy[no];
      lazy[no*2+1] += lazy[no];
    }lazy[no] = 0;
  }

  void build(int no, int l, int r){
    if(l == r) tree[no] = arr[l];
    else{
      int mid = (l+r)/2;
      build(no*2, l, mid);
      build(no*2+1, mid+1, r);
      tree[no] = merge(tree[no*2], tree[no*2+1]);
    }
  }
  void update(int no, int l, int r, int x, int y, int v){
    if(l > y || r < x){
      push(no, l, r);
    }else if(l >= x && r <= y){
      lazy[no] += v;
      push(no, l, r);
    }else{
      push(no, l, r);
      int mid = (l+r)/2;
      update(no*2, l, mid, x, y, v);
      update(no*2+1, mid+1, r, x, y, v);
      tree[no] = merge(tree[no*2], tree[no*2+1]);
    }
  }
  int query(int no, int l, int r, int x, int y){
    push(no, l, r);
    if(r < x || l > y) return 0;
    else if(l >= x && r <= y) return tree[no];
    int mid = (l+r)/2;
    return merge(query(no*2, l, mid, x, y), query(no*2+1, mid+1, r, x, y));
  }
}root;

int main(){
  cin >> n;
  for(int i = 0;  i < n; ++i){
    cin >> arr[i];
  }
  root.build(1, 0, n-1);
  cin >> q;
  int a, b, c, d;
  for(int  i = 0 ; i < q; ++i){
    cin >> a;
    if(a == 0){
      cin >> b >> c >> d;
      root.update(1, 0, n-1, b-1, c-1, d);
    }else{
      cin >> b >> c;
      cout << root.query(1, 0, n-1, b-1, c-1) << "\n";
    }
  }
}
