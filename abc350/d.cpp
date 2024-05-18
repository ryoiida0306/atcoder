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
  dsu d(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--;b--;
    d.merge(a,b);
  }
  
  set<int> S;
  rep(i,n){
    S.insert(d.leader(i));
  }
  vector<int> v;
  while((int)S.size()){
    v.push_back(d.size(*S.begin()));
    cerr << *S.begin() << endl;
    S.erase(*S.begin());
  }
  
  ll ans = 0;
  rep(i,(int)v.size()){
    ans += (ll)v[i]*(ll)(v[i]-1) / 2L;
  }
  cout << ans - m << endl;
  return 0;
}


