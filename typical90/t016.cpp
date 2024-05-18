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
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  const ll INF = 1001001001;
  ll ans = INF;
  rep(i,10000)rep(j,10000){
    if((n-a*i-b*j)%c == 0 && n-a*i-b*j>=0){
      ans = min(ans,i+j+(n-a*i-b*j)/c);
    }
  }
  cout << ans << endl;
  return 0;
}


