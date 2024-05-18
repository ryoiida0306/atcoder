#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h,vector<int>(w));
  rep(i,h)rep(j,w)cin >> a[i][j];
  
  vi H(h),W(w);
  rep(i,h)rep(j,w){
    H[i] += a[i][j];
    W[j] += a[i][j];
  }
  
  rep(i,h){
    rep(j,w){
      cout << H[i] + W[j] - a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
