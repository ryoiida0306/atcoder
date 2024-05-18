#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<char,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  int q;
  cin >> q;
  vector<ll> b(q);
  rep(i,q) cin >> b[i];
  sort(a.begin(),a.end());
  
  rep(i,q){
    int l = 0;
    int r = (int)a.size()-1;
    while(r-l>1){
      // cerr << l << " " << r << endl;
      int m = (l + r) /2;
      if(a[m]-b[i]>0)r = m;
      else l = m;
      // cerr << l << " " << r << endl;
      
    }
    ll ans = min(abs(a[r]-b[i]),abs(b[i]-a[l]));
    cout << ans << endl;
  }
  return 0;
}
