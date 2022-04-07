#include <bits/stdc++.h>
using namespace std;

class dsu{
  private:
    vector<int> parent;
    vector<int> size;
  public:
    dsu(int n){
      parent = vector<int>(n);
      size = vector<int>(n);
      iota(parent.begin(), parent.end(), 0);
      fill(size.begin(), size.end(), 1);
    }

    int find_set(int v){
      if(parent[v] == v) return v;
      else{
        return parent[v] = find_set(parent[v]);
      }
    }

    void union_sets(int a, int b){
      a = find_set(a); b = find_set(b);
      if(a != b){
        if(size[a] < size[b])
          swap(a, b);
        parent[b] = a;
        size[a] += size[b];
      }
    }
};

