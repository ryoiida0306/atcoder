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
  string s;
  cin >> s;
  bool ok = true;
  int n = s.size();
  rep(i,n){
    if(s[i] == '|'){
      ok = !ok;
      continue;
    }
    if(ok) cout << s[i];
  }
  
  cout << endl;
  return 0;
}
