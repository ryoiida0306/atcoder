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
  vi c1(n),c2(n);
  rep(i,n){
    int c,p;
    cin >> c >> p;
    if(c == 1) c1[i] = p;
    else c2[i] = p;
  }
  
  vi c1sum(n), c2sum(n);
  
  rep(i,n){
    if(i == 0){
      c1sum[i] = c1[i];
      c2sum[i] = c2[i];
      continue;
    }
    c1sum[i] = c1[i] + c1sum[i-1];
    c2sum[i] = c2[i] + c2sum[i-1];
  }
  
  // rep(i,n){
  //   cerr << c1sum[i] << " ";
  // }
  // cerr << endl;
  // rep(i,n){
  //   cerr << c2sum[i] << " ";
  // }
  int q;
  cin >> q;
  rep(i,q){
    int l,r;
    cin >> l >> r;
    l--;r--;
    int a,b;
    a = c1sum[r] - c1sum[l] + c1[l];
    b = c2sum[r] - c2sum[l] + c2[l];
    cout << a << " " << b << endl;
  }
  return 0;
}
