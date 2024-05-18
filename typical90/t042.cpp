#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int k;
  cin >> k;
  if(k%9 != 0){
    cout << 0 << endl;
    return 0;
  }
  mint2 dp[k+1];
  rep(i,k+1) dp[i] = 0;
  dp[0] = 1;
  rep(i,k)for(int j = 1; j < 10; j++){
    if(i+j > k)continue;
    dp[i+j] += dp[i];
  }
  cout << dp[k].val() << endl;
  return 0;
}


