#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  ll x;
  cin >> x;
  if(x < 0){
    cout << x/10 << endl;
    return 0;
  }
  if(x%10 == 0){
    cout << x/10 << endl;
    return 0;
  }
  cout << x/10 +1 << endl;
  return 0;
}

//wa