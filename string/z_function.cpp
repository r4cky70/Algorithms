#include <bits/stdc++.h>
using namespace std;
#define MAXS 100007

int zf[MAXS];

void zfunc(string s){
  for(int i = 1, l = 0, r = 0; i < s.size(); i++){
    zf[i] = max(0, min(zf[i-l], r-i+1));
    while(i+zf[i] < s.size() && s[zf[i]] == s[i+zf[i]]) {
      l = i; r = i+zf[i]; zf[i]++;
    }
  } zf[0] = s.size();
}

int main(){
  string s;
  cin >> s;
  zfunc(s);
  for(int i =0; i < s.size(); ++i) cout << zf[i] << " "; cout << endl;
}