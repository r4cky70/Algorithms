#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<ll>> matrix;
using long long ll;

matrix operator +(matrix a, matrix b){
  int n = (int)a.size();
  int m = (int)a[0].size();
  matrix c;
  c.resize(n);
  for(int i = 0; i < n; ++i){
    c[i].resize(m);
    for(int j = 0; j < m; ++j){
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}

matrix operator *(ll t, matrix a){
  int n = (int)a.size();
  int m = (int)a[0].size();
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      a[i][j]*=t;
    }
  }
  return a;
}

matrix operator -(matrix a, matrix b){
  return a + (-1 * b);
}

matrix operator *(matrix a, matrix b) {
  int n = (int)a.size();
  int m = (int)b.size();
  int p = (int)b[0].size();
  matrix c(n, vector<ll>(p));
  ll col[m];
  for (int j = 0; j < p; j++) {
    for (int k = 0; k < m; k++)
      col[k] = b[k][j];
    for (int i = 0; i < n; i++) {
      ll s = 0;
      for (int k = 0; k < m; k++)
        s += a[i][k] * col[k];
      c[i][j] = s;
    }
  }
  return c;
}

matrix det(int n){
  matrix c(n, vector<ll>(n));
  for(int i = 0; i < n; ++i) c[i][i] = 1;
  return c;
}

matrix exp(matrix a, int b){
  if(b == 0) return det(a.size());
  matrix c = exp(a, b/2);
  c = c*c;
  if(b%2 != 0) c = c*a;
  return c;
}


int main(){
  //fibo recorrence
  matrix a = {{1, 1},{1, 0}};
  matrix b = {{1, 1}, {2, 2}};
  matrix c = exp(a, 3);
  for(int i = 0; i < c.size(); ++i){
    for(int j = 0; j < c[0].size(); ++j){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
}
