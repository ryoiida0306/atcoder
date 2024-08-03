#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
// #define all(a) (a).begin, (a).end()
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vsi = vector<set<int>>;
using vsl = vector<set<ll>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mytpl = tuple<ll,int,int>;


int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  vector<vector<int>> score_map(n+1,vector<int>(3,-INF));
  rep1(i,n){
    char c = s[i-1];
    if(c == 'R'){
      score_map[i][2] = 0;
      score_map[i][0] = 1;
    }
    if(c == 'P'){
      score_map[i][0] = 0;
      score_map[i][1] = 1;
    }
    if(c == 'S'){
      score_map[i][1] = 0;
      score_map[i][2] = 1;
    }
  }
  
  vector<vector<int>> dp(n+1,vector<int>(3,0));
  // rep(i,3)dp[0][i] = 0;
  
  rep1(i,n){
    rep(j,3){
      dp[i][j] = max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + score_map[i][j];
    }
  }
  
  int ans = 0;
  for(auto value : dp[n]){
    ans = max(ans,value);
  }
  cout << ans << endl;
  
  // rep(i,n+1){
  //   rep(j,3) cerr << score_map[i][j] << " ";
  //   cerr << endl;
  // }
  // rep(i,n+1){
  //   rep(j,3) cerr << dp[i][j] << " ";
  //   cerr << endl;
  // }
  return 0;
}