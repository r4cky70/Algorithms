#include <bits/stdc++.h>
using namespace std;

#define MAXS 100007

int arr[MAXS];

void kmp(string s){
  int m = 0;
  arr[0] = 0;
  for(int i = 1; i < s.size(); ++i){
    while(m > 0 && s[m] != s[i]) m = arr[m];
    if(s[m] == s[i]) arr[i] = ++m;
  }
}

int main(){
  string s;
  cin >> s;
  kmp(s);
  for(int i = 0; i < s.size(); ++i){
    cout << arr[i] << " ";
  }cout << endl;
}