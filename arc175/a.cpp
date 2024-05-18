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
  vector<P> p(n);
  rep(i,n){
    int a;
    cin >> a;
    p[i] = P(a-1,i);
  }
  sort(p.begin(),p.end());
  string s;
  cin >> s;
  
  auto f = [&](char kiki) -> mint {
    mint ans = 1;
    char kikii = 'n';
    if(kiki == 'L') kikii='R';
    else kikii = 'L';
    int forkdelta = -1;
    if(kiki == 'L') forkdelta = 0;
    else forkdelta = 1;
    int forkdeltai = -1;
    if(kiki == 'L') forkdeltai = 1;
    else forkdeltai = 0;
    vi fork(n,0);
    rep(i,n){
      if(fork[(p[i].second+forkdeltai)%n] == 1){
        if(s[p[i].second] == '?') ans *= 2;
      }else{
        if(s[p[i].second] == kikii) ans = 0;
      }
      fork[p[i].second+forkdelta] = 1;
    }
    return ans;
  };
  mint ans = f('L') + f('R');
  
  cout << ans.val() << endl;
  
  return 0;
}


//re