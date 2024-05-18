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
  int INF = 1001001001;
  string t;
  int n;
  cin >> t >> n;
  vi a(n);
  vector<vector<string>> S(n);
  rep(i,n){
    cin >> a[i];
    int ss = a[i];
    rep(j,ss){
      string s;
      cin >> s;
      S[i].push_back(s);
    }
  }
  
  int dp[110][110];
  rep(i,110){
    rep(j,110){
      dp[i][j] = INF;
    }
  }
  
  int T =t.size();
  dp[0][T] = 0;
  rep(i,n){
    for(string s : S[i]){
      for(int j = 0;j <= T;j++){
        int ss = s.size();
        int l = T - j;
        int r = l + ss;
        if(l<0) continue;
        string subt = t.substr(l,r-l);
        // cout << ss << " ";
        // cout << l << " " << r << " " << subt << endl;
        if(subt == s){
          // cout << " " << "kouryo" << endl;
          dp[i+1][j-ss] = min(dp[i+1][j -ss],dp[i][j]+1);
        }
        dp[i+1][j] = min(dp[i+1][j] , dp[i][j]);
      }
    }
  }
  int ans = dp[n][0];
  if(ans != INF){
    cout << dp[n][0] << endl;
  }else{
    cout << -1 << endl;
  }
  return 0;
}
