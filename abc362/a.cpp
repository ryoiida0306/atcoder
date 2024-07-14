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
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mytpl = tuple<P,int>;
int main(){
  int r, g, b;
  cin >> r >> g >> b;
  string c;
  cin >> c;
  int ans = INF;
  if(c == "Red"){
    ans = min(g,b);
  }
  if(c == "Green"){
    ans = min(r,b);
  }
  if(c == "Blue"){
    ans = min(r,g);
  }
  cout << ans << endl;
  return 0;
}