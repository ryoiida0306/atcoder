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
  ll a, b;
  cin >> a >> b;
  ll c = gcd(a,b);
  ll d = a / c;
  if(d > ll(1e18) /b) cout << "Large" << endl;
  else cout <<  d * b << endl;
  return 0;
}


