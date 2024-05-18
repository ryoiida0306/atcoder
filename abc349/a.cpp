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
  int ans = 0;
  rep(i,n-1){
    int a;
    cin >> a;
    ans -= a;
  }
  cout << ans << endl;
  return 0;
}


