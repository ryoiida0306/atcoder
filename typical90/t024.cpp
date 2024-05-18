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
  int n, m;
  cin >> n >> m;
  scc_graph g(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--;b--;
    g.add_edge(a,b);
  }
  
  ll ans = 0;
  for(auto vs : g.scc()){
    ll s = vs.size();
    ans += s*(s-1) / 2;
  }
  
  cout << ans << endl;
  
  
  return 0;
}


