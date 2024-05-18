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
  int n, q;
  cin >> n >> q;
  vector<int> a(n,1);
  rep(i,q){
    int t;
    cin >> t;
    t--;
    // cout << a[0] << endl;
    if(a[t] == 1) a[t] = 0;
    else a[t] = 1;
  }
  int ans = 0;
  rep(i,n)ans += a[i];
  cout << ans << endl;
  return 0;
}


