#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)

int main() {
  long long n;
  cin >> n;
  
  if(n == 1){
    cout << "0" << endl;
    return 0;
  }
  
  n--;
  
  vector<int> v;
  
  while(n != 0){
    v.push_back(n%5);
    n /= 5;
  }
  
  rep(i,v.size()){
    cout << v.at(v.size()-i-1) *2;
  }
  
  
  
  cout << endl;
  
  return 0;
}