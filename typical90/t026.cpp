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
  vector<set<int>> d(n);
  rep(i,n-1){
    int a, b;
    cin >> a >> b;
    a--;b--;
    d[a].insert(b);
    d[b].insert(a);
  }
  rep(i,n){
    for(int v : d[i]){
      // cerr << v << " ";
    }
    // cerr << endl;
  }
  
  vi sa, sb;
  
  auto f = [&](auto f, int p, int v, int color) -> void {
    if(color == 1) sa.push_back(v);
    else sb.push_back(v);
    for(int u : d[v]){
      if(u == p)continue;
      // cerr << v << " " << u << " " << -color << endl;
      f(f,v,u,-color);
    }
  };
  
  f(f,-1,0,1);
  
  vi maxset = ((int)sa.size() > (int)sb.size()) ? sa : sb;
  rep(i,n/2){
    cout << maxset[i]+1 << " ";
  }
  cout << endl;
  return 0;
}


