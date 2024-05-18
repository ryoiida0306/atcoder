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
  int a = 0;
  int b = 0;
  rep(i,9){
    int n;
    cin >> n;
    a += n;
  }
  rep(i,8){
    int n;
    cin >> n;
    b += n;
  }
  
  cout << a - b + 1 << endl;
  return 0;
}
