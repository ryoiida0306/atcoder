#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  string s;
  cin >> s;
  string num = s.substr(3,3);
  int n = stoi(num);
  cerr << n << endl;
  // for(int i = 1 ; i < 400 ; i++){
  if(n <= 349){
    if(n == 316 || n == 0){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
  }else cout << "No" << endl;
  // }
  return 0;
}


