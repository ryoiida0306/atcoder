#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
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
  vector<tuple<int,int,int>> data;
  rep(i,n){
    int d, c, s;
    cin >> d >> c >> s;
    data.push_back(tuple<int,int,int>(d,c,s));
  }
  sort(data.begin(),data.end());
  // for(auto a : data){
  //   cerr << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << endl;
  // }
  
  vector<vector<ll>> dp(n+1,vector<ll>(5001,0));
  rep(i,n+1)rep(j,5001){
    if(!i)continue;
    if(!j)continue;
    dp[i][j] = dp[i-1][j];
    if(!(get<1>(data[i-1])<=j&&j<=get<0>(data[i-1])))continue;
    dp[i][j] = max(dp[i][j],dp[i-1][j-get<1>(data[i-1])]+get<2>(data[i-1]));
  }
  ll ans = 0;
  rep(j,5001){
    ans = max(ans, dp[n][j]);
  }
  cout << ans << endl;
  return 0;
}


