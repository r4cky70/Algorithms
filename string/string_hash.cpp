#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int MAXS = 1000007;

ll bmod[2] = {114559609, 114559639};
ll lmod[2] = {307, 317};

ll pot[2][MAXS];
ll inv[2][MAXS];

ll adi(ll a, ll b, ll mod){
  return (a%mod + (b%mod))%mod;
}
ll multi(ll a, ll b, ll mod){
  return (a%mod * (b%mod))%mod;
}
ll fastexp(ll a, ll b, ll mod){
  if(b == 0) return 1;
  if(b == 1) return a%mod;
  ll x = fastexp(a, b/2, mod);
  if(b%2){
    return multi(multi(x, x, mod), a, mod);
  }else{
    return multi(x, x, mod);
  }
}

void prec(){
  for(int j = 0; j < 2; ++j){
    pot[j][0] = lmod[j];
    inv[j][0] = fastexp(lmod[j], bmod[j]-2, bmod[j]);
    for(int i = 1; i < MAXS; ++i){
      pot[j][i] = multi(pot[j][i-1], lmod[j], bmod[j]);
      inv[j][i] = multi(inv[j][i-1], inv[j][0], bmod[j]);
    }
  }
}

struct hashing{
  ll chash[2][MAXS];
  int tam;

  hashing(){tam = 0;}
  hashing(string s){
    for(int j = 0; j < 2; ++j){
      chash[j][0] = s[0]-'a'+1;
      for(int i = 1; i < s.size(); ++i){
        chash[j][i] = adi(chash[j][i-1], multi((s[i]-'a'+'1'), pot[j][i], bmod[j]), bmod[j]);
      }
    }
    tam = s.size();
  }

  pair<ll, ll> gethash(){
    return make_pair(chash[0][tam-1], chash[1][tam-1]);
  }

  bool operator ==(hashing &e){
    pair<ll, ll> temp = gethash();
    pair<ll, ll> a = e.gethash();
    return (temp.first == a.first && temp.second == a.second);
  }
  
  pair<ll, ll> sub(int i, int j){ // [i, j]
    pair<ll, ll> ans;
      ans.first = (chash[0][j] + bmod[0] - (i==0?0:chash[0][i-1])) * inv[0][i] %bmod[0];
      ans.second = (chash[1][j] + bmod[1] - (i==0?0:chash[1][i-1])) * inv[1][i] %bmod[1];
    return ans;
  }
};


int main(){
  prec();
  string s1, s2;
  cin >> s1;
  int n;cin >> n;
  int a, b;
  hashing h = hashing(s1);
  for(int i = 0; i < n; ++i){
    cin >> a >> b;
    pair<ll, ll> temp = h.sub(a, b);
    cout << temp.first << " " << temp.second << endl;
  }
  
  
}
