#include<bits/stdc++.h>
using namespace std;
#define MAXS 100007

int n;
int arr[MAXS];
int sqrte[MAXS];

void build(){
  int temp = (int)sqrt(n);
  for(int i = 0; i < n; ++i){
    sqrte[i/temp]+=arr[i];
  }
}
int query(int l, int r){
  int ans = 0;
  int temp = (int)sqrt(n);
  while(l <= r){
    if(l%temp == 0 && l+temp <= r){
      ans+=sqrte[l/temp];
      l+=temp;
    }else{
      ans+=arr[l];
      l++;
    }
  }
  return ans;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  build();
  int q, a, b;
  cin >> q;
  for(int i =0; i < q; ++i){
    cin >> a >> b;
    cout << query(a-1, b-1) << endl;
  }
}