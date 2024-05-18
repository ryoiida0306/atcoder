#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
#include "../ac-library/atcoder/all"
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n,k;
  cin >> n >> k;
  vi A;
  rep(i,n){
    int a;
    cin >> a;
    if(a%k == 0) A.push_back(a/k);
  }
  sort(A.begin(),A.end());
  for(int a : A){
    cout << a << " ";
  }
  cout << endl;
  return 0;
}


