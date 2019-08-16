#include <bits/stdc++.h>

using namespace std;

long long fastExp(long long a, long long b){
  if(b == 0) return 1;
  if(b%2 == 0){
    long long x = fastExp(a, b/2);
    return x * x;
  }
  return fastExp(a, b - 1) * a;
}

int main(){
  int n, m;
  cin >> n >> m;  
  cout << fastExp(n, m) << endl;
}