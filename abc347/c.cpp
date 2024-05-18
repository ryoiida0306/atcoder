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
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> c(n);
  rep(i,n){
    ll d;
    cin >> d;
    d--;
    c[i] = min(d%(a+b),(a+b)-d%(a+b));
  }
  sort(c.begin(),c.end());
  
  ll e = c[n-1] - c[0] + 1;
  if(e > a) cout << "No" << endl;
  else cout << "Yes" << endl;
  
  // rep(i,(int)c.size()){
  //   cerr << c[i] << " ";
  // }
  
  return 0;
}



//wa