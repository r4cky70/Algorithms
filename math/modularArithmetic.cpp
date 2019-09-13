#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

long long multi(long long a, long long b){
  return (a % MOD) * (b % MOD) % MOD;
}
long long adi(long long a, long long b){
  return (a % MOD) + (b % MOD) % MOD;
}
long long sub(long long a, long long b){
  return (((a % MOD) - (b % MOD) % MOD) + MOD) % MOD;
}

long long fe(long long a, long long b){
  if(b == 0) return 1;
  if(b == 1) return a % MOD;
  int x = fe(a, b/2);
  if(b%2) return multi(multi(x, x), a);
  else return multi(x, x);
}
//gcd(b mod) need to be 1
long long inv(long long a, long long b){
  return multi((a % MOD) , fe(b, MOD-2)%MOD);
} 
