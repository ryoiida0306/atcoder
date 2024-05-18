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
  int h, w;
  cin >> h >> w;
  if(h == 1 || w == 1) cout << h * w << endl;
  else cout << (int)((h+1)/2) * (int)((w+1)/2) << endl;
  return 0;
}


