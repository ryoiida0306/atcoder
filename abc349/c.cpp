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
  // cout << (char)('a'-32) << endl;
  string s,t;
  cin >> s >> t;
  // string now = "";
  int nowi = 0;
  rep(i,(int)s.size()){
    if((char)(s[i]-32) == t[nowi]){
      nowi++;
    }
  }
  if(nowi == 2){
    if(t[2] == 'X'){
      nowi++;
    }
  }
  if(nowi == 3) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


