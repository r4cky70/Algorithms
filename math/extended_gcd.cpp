#include <bits/stdc++.h>
using namespace std;

// for modular inverse of a mod b, check if gcd==1
//and then do x = (a%b+b)%b;
int exgcd(int a, int b, int &x, int &y){
  if(a == 0){
    x = 0;
    y = 1; 
    return b;
  }
  int x1, y1;
  int d = exgcd(b%a, a, x1, y1);
  x = y1 - (b/a) * x1;
  y = x1;
  return d;
}