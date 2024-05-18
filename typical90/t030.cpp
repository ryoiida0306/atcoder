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
  int n, k;
  cin >> n >> k;
  vector<int> p(n+1);
  rep(i,n+1){
    if(i == 0 || i == 1)continue;
    if(p[i])continue;
    for(int j = 1; i*j <= n; j++){
      p[i*j]++;
    }
  }
  int ans = 0;
  rep(i,n+1){
    if(i == 0 || i == 1)continue;
    if(p[i] < k)continue;
    ans++;
  }
  cout << ans << endl;
  return 0;
}


