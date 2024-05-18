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
  ll a, b, c;
  cin >> a >> b >> c;
  
  ll cb = 1;
  rep(i,b){
    cb *= c;
  }
  if(a < cb) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}


