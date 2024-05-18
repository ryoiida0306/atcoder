#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<char,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  mint2 dp[8];
  rep(i,8) dp[i] = 0;
  dp[0] = 1;
  
  rep(i,n){
    if(s[i] == 'a') dp[1] += dp[0];
    if(s[i] == 't') dp[2] += dp[1];
    if(s[i] == 'c') dp[3] += dp[2];
    if(s[i] == 'o') dp[4] += dp[3];
    if(s[i] == 'd') dp[5] += dp[4];
    if(s[i] == 'e') dp[6] += dp[5];
    if(s[i] == 'r') dp[7] += dp[6];
  }
  
  cout << dp[7].val() << endl;
  return 0;
}
