#include <bits/stdc++.h>
using namespace std;

#define MAXS 100007
#define STREE int branch = no*2, mid = (l+r)/2
#define all(a) a.begin(),a.end()

typedef vector<int> vi;

int n, q;
int arr[MAXS];

//This algorithms fetches for the number of values bigger than v in a given interval [L, R]
//Complexity to build = O(n log(n))
//Complexity to search = O(log(n)^2)

struct mergetree{
  vi tree[MAXS*4];

  void build(int no, int l, int r){
    if(l == r) tree[no].push_back(arr[l]);
    else{
      STREE;
      build(branch, l, mid);
      build(branch+1, mid+1, r);
      merge(all(tree[branch]), all(tree[branch+1]), back_inserter(tree[no]));;
    }
  }
  int query(int no, int l, int r, int x, int y, int v){
    if(l > y || r < x){
      return 0;
    }else if(l >= x && r <= y){
      int p1 = tree[no].size() - (upper_bound(all(tree[no]), v) - tree[no].begin()); // (lower_bound(all(tree[no]), v) - tree[no].begin())
    }else{                                                                           // for values lower than v
      STREE;
      return query(branch, l, mid, x, y, v) + query(branch+1, mid+1, r, x, y, v);
    }
  }
}root;


int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  root.build(1, 0, n-1);
  cin >> q;
  int a, b, v;
  for(int i = 0; i < q; ++i){
    cin >> a >> b >> v;
    cout << root.query(1, 0, n-1, a-1, b-1, v) << "\n";
  }
}
