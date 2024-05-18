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
  ll l, r;
  cin >> l >> r;
  // ll m = l;
  vector<pair<ll,ll>> ans;
  while(l < r){
    for(int i = 60; i >= 0; i--){
      if(l % (1L << i) == 0 && l + (1L << i) <= r){
        ans.push_back(pair<ll,ll>(l,l+(1L << i)));
        l += (1L << i);
        break;
      }
    }
  }
  cout << (int)ans.size() << endl;
  rep(i,(int)ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  
  rep(i,60){
    cerr << (1L << i) << endl;
  }
  return 0;
}


