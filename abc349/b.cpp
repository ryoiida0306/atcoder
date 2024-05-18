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
  string s;
  cin >> s;
  vi e(30);
  rep(i,(int)s.size()){
    e[(int)(s[i] - 'a')]++;
  }
  
  // rep(i,30){
  //   cerr << e[i] << endl;
  // }
  
  vector<int> f(101);
  
  rep(i,30){
    rep(j,101){
      if(e[i] == j){
        f[j]++;
      }
    }
  }
  
  int ok = 1;
  rep(i,101){
    if(!i)continue;
    if(f[i] != 0 && f[i] != 2){
      ok = 0;
      break;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


