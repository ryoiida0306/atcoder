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
  int n;
  cin >> n;
  vvi d(n);
  rep(i,n-1){
    int a, b;
    cin >> a >> b;
    a--;b--;
    d[a].push_back(b);
    d[b].push_back(a);
  }
  
  vector<ll> dp(n,0);
  
  auto dfs = [&](auto dfs, int p = -1, int v = 0) -> ll {
    dp[v] = 1;
    for(int u : d[v]){
      if(u == p) continue;
      dp[v] += dfs(dfs, v, u);
    }
    return dp[v];
  };
  
  dfs(dfs,-1,0);
  ll ans = 0;
  rep(i,n){
    ans += dp[i] * (n - dp[i]);
  }
  cout << ans << endl;
  return 0;
}


