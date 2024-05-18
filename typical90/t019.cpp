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
  vi a(2*n);
  rep(i,2*n) cin >> a[i];
  
  const int INF = 1001001001;
  vector<vector<ll>> dp(2*n,vector<ll>(2*n,INF));
  rep(i,2*n-1){
    dp[i][i+1] = abs(a[i]-a[i+1]);
  }
  for(int i = 2; i<=2*n; i++){
    for(int j = 0; j+i<2*n; j++ ){
      int l = j;
      int r = j + i;
      dp[l][r] = min(dp[l][r],dp[l+1][r-1] + abs(a[l]-a[r]));
      for(int k = l+1;k+1<=r-1;k++){
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
      }
    }
  }
  
  cout << dp[0][2*n-1] << endl;
  
  return 0;
}


