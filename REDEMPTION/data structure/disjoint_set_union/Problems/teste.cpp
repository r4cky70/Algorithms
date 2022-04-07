#include <bits/stdc++.h>
using namespace std;

void functions(vector<int> &arr){
  for (auto& i : arr){
    cout << i << endl;
  }
  for(int i = 0; i < arr.size(); ++i){
    cout << arr[i] << " ";
  }
}

int main(){
  vector<int> a{1,2,3,7,5};
  functions(a);
}
