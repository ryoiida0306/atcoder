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
  int n;
  cin >> n;
  vi a(n+1), vec(n+1);
  for(int i = 1;i<= n;i++){
    int b;
    cin >> b;
    a[i] = b;
    vec[b] = i;
  }
  vector<P> ans;
  
  for(int i = 1;i <= n ; i++){
    if(a[i] != i){
      ans.push_back(P(i,vec[i]));
      int r = i;
      int l = vec[i];
      swap(a[r],a[l]);
      vec[a[r]] = r;
      vec[a[l]] = l;
    }
  }
  cout << (int)ans.size() << endl;
  for(auto an : ans){
    cout << an.first << " " << an.second << endl;
  }
  return 0;
}


