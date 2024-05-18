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

ll op(ll a, ll b){
  return max(a, b);
}

ll e(){
  return -1001001001001001001;
}

int main() {
  ll w, n;
  cin >> w >> n;
  vector<int> l(n), r(n);
  vector<ll> v(n);
  rep(i,n) cin >> l[i] >> r[i] >> v[i];
  
  vector<vector<ll>> dp(n+1,vector<ll>(w+1,-1001001001001001001));
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++){
    segtree<ll, op, e> seg(w+1);
    for(int j = 0; j <=w; j++){
      seg.set(j,dp[i-1][j]);
      // cerr << dp[i-1][j] << " ";
    }
    cerr << endl;
    for(int j = 0; j <= w; j++){
      dp[i][j] = seg.prod(max(j-r[i-1],0),max(j-l[i-1]+1,0)) + v[i-1];
      dp[i][j] = max(dp[i-1][j],dp[i][j]);
    }
  }
  
  ll ans = dp[n][w];
  if(ans < 0) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}


