#include <bits/stdc++.h>
#define MAXS 1000007

using namespace std;

bitset <MAXS> cri;

void sieve(){
  cri.set();
  cri[0] = cri[1] = 0;
  for(long long i = 2; i < MAXS; i++){
    if(cri[i]){
      for(long long j = i + i; j < MAXS; j += i){
        cri[j] = false;
      }
    }
  }
}

int main() {
  sieve();
} 
