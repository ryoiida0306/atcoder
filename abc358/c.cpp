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

int main(){
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  int ans = INF;
  rep(i,1 << n){
    vector<bool> ok(m,false);
    rep(j,n){
      if((i >> j) & 1){
        rep(k,m){
          if(s[j][k] == 'o') ok[k] = true;
        }
      }
    }
    // cerr << i << endl;
    // rep(j,m) cerr << ok[j];
    // cerr << endl;
    bool okk = true;
    rep(j,m) okk = ok[j] && okk;
    // cerr << okk << endl;
    if(okk){
      int nowans = 0;
      rep(j,n){
        nowans += (i >> j) & 1;
      }
      ans = min(nowans,ans);
    }
  }
  cout << ans << endl;
  return 0;
}