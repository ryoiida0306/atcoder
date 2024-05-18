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
  vi a(n);
  map<int,int> b;
  rep(i,n) cin >> a[i];
  
  int l = 0;
  int r = 0;
  set<int> s;
  
  s.insert(a[0]);
  b[a[0]]++;
  int ans = 0;
  while(r < n){
    // cerr << l << " " << r << endl;
    if((int)s.size() <= k){
      ans = max(ans,r-l+1);
      r++;
      b[a[r]]++;
      s.insert(a[r]);
      continue;
    }else{
      if(b[a[l]] == 1){
        s.erase(a[l]);
        b[a[l]]--;
      }else{
        b[a[l]]--;
      }
      l++;
    }
  }
  cout << ans << endl;
  return 0;
}


