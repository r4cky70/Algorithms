#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = (int)1e9 + 7;

ll multi(ll a, ll b){
  return (a % MOD) * (b % MOD) % MOD;
}
ll adi(ll a, ll b){
  return (a % MOD) + (b % MOD) % MOD;
}
ll sub(ll a, ll b){
  return (((a % MOD) - (b % MOD) % MOD) + MOD) % MOD;
}

ll fe(ll a, ll b){
  if(b == 0) return 1;
  if(b == 1) return a % MOD;
  ll x = fe(a, b/2);
  if(b%2) return multi(multi(x, x), a);
  else return multi(x, x);
}
ll inverse(int a, int mod, int s0 = 1, int s1 = 0){
  return mod == 0? s0: inverse(mod, a%mod, s1, s0-s1*(a/mod));
}

ll inv(ll a){
  return fe(a, MOD-2);
}
ll inv2(ll a){
  return (inverse(a, MOD)%MOD+MOD)%MOD;
}
