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
  int n;
  cin >> n;
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  
  ll ans = 0;
  rep(i,n){
    ans += abs(a[i] - b[i]);
  }
  
  cout << ans << endl;
  return 0;
}
