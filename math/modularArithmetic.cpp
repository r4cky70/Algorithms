w#include <bits/stdc++.h>
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
