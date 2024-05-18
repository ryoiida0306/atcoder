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
  int n,m,l,q;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  cin >> m;
  vi b(m);
  rep(i,m) cin >> b[i];
  cin >> l;
  vi c(l);
  rep(i,l) cin >> c[i];
  cin >> q;
  vi x(q);
  rep(i,q) cin >> x[i];
  
  set<int> S;
  
  rep(i,n)rep(j,m)rep(k,l){
    S.insert(a[i]+b[j]+c[k]);
  }
  
  rep(i,q){
    if(S.count(x[i])){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
