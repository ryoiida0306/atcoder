#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vvi d(n+1);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    d[a].push_back(b);
    d[b].push_back(a);
  }
  P vh = P(-1,-1);
  
  auto dfs = [&](auto dfs, int p, int v,int h) -> void {
    // cout << p << v << h << endl;
    if(vh.second<h){
      vh = P(v,h);
    }
    for(int n : d[v]){
      if(n == p) continue;
      dfs(dfs,v,n,h+1);
    }
  };
  
  dfs(dfs,-1,1,0);
  dfs(dfs,-1,vh.first,0);
  
  cout << vh.second +1 << endl;
  return 0;
}
