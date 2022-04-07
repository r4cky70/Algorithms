#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



ll modinv(ll a, ll m) {
	// assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	// assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}

template <int MOD> class modnum{
public:
  ll v;
  modnum() : v(0){}
  modnum(ll p){v = p%MOD;}
  bool operator == (modnum& o) {return this.v == o.v;}
  bool operator != (modnum& o) {return this.v != o.v;}
  friend ostream& operator << (ostream& os, const modnum& mn) {
    os << mn.v;
    return os;
  }
  friend istream& operator >> (istream& is, modnum& mn) {
    is >> mn.v;
    return is;
  }
  modnum operator + (ll o) {return (v+o)%MOD;}
  modnum operator - (ll o) {return ((v-o)%MOD+MOD)%MOD;}
  modnum operator * (ll o) {return (v*o)%MOD;}
  modnum operator / (ll o) {return (v * modinv(o, MOD));}
  modnum operator ~() const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}
	modnum& operator += (const modnum& o) {v = (v+o.v)%MOD;return *this;}
	modnum& operator -= (const modnum& o) {v = ((v-o.v)%MOD+MOD)%MOD;return *this;}
	modnum& operator *= (const modnum& o) {v = (v*o.v)%MOD;return *this;}
	modnum& operator /= (const modnum& o) {return *this *= (~o);}
 
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num=modnum<1000000007>;


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

ll inverse(int a, int mod, int s0 = 1, int s1 = 0){
  return mod == 0? s0: inverse(mod, a%mod, s1, s0-s1*(a/mod));
}

ll inv(ll a){
  return fe(a, MOD-2);
}
ll inv2(ll a){
  return (inverse(a, MOD)%MOD+MOD)%MOD;
}
