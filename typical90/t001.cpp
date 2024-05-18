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
  int n , l , k;
  cin >> n >> l >> k;
  vector<int> a;
  a.push_back(0);
  rep(i,n){
    int aa;
    cin >> aa;
    a.push_back(aa);
  }
  a.push_back(l);
  vector<int> b;
  for(int i = 0;i <= n;i++){
    b.push_back(a[i+1]-a[i]);
  }
  
  
  auto f = [&](int x) -> bool{
    int nowk = 0;
    int nowl = 0;
    rep(i,(int)b.size()){
      nowl += b[i];
      if(nowl >= x){
        if(nowk >= k) return true;
        nowk++;
        nowl = 0;
      }
    }
    return false;
  };
  
  int lx = 0;
  int rx = 1001001001;
  
  while(rx-lx > 1){
    int m = (lx + rx) /2;
    if(f(m)){
      lx = m;
    }else{
      rx = m;
    }
    cerr << lx << endl;
  }
  
  cout << lx << endl;
  return 0;
}
