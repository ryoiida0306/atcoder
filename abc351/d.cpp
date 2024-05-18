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

void show(vvi a){
  rep(i,(int)a.size()){
    rep(j,(int)a[0].size()) cerr << a[i][j] << " ";
    cerr << endl;
  }
  cerr << endl;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> t(h);
  rep(i,h) cin >> t[i];
  vvi ans(h,vector<int>(w,-1));
  vvi G(h,vector<int>(w,0));
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  
  
  auto isin = [&](int i, int j) -> bool {
    bool ok = true;
    if(i < 0) ok = false;
    if(i >= h) ok = false;
    if(j < 0) ok = false;
    if(j >= w) ok = false;
    return ok;
  };
  auto canmove = [&](int i, int j) -> bool {
    bool ok = true;
    rep(k,4){
      int ni = i+dx[k];
      int nj = j+dy[k];
      if(!isin(ni,nj)) continue;
      if(t[ni][nj] == '#') ok = false;
    }
    return ok;
  };
  auto isdot = [&](int i, int j) -> bool {
    bool ok = isin(i,j);
    if(!ok) return false;
    if(t[i][j] == '#') ok = false;
    return ok;
  };
  
  int Ans = 1;
  rep(i,h)rep(j,w){
    if(t[i][j] == '#')continue;
    if(G[i][j] == 1)continue;
    deque<P> Q;
    set<P> S;
    Q.push_back(P(i,j));
    S.insert(P(i,j));
    while((int)Q.size()){
      P now = Q.front();
      Q.pop_front();
      S.insert(P(now.first,now.second));
      bool ok = canmove(now.first,now.second);
      if(ok){
        rep(k,4){
          int ni = now.first+dx[k];
          int nj = now.second+dy[k];
          bool okk = isdot(ni,nj);
          if(okk){
            if(!S.count(P(ni,nj)))
            Q.push_back(P(ni,nj));
            G[ni][nj] = 1;
          }
        }
      }
    }
    Ans = max(Ans, (int)S.size());
  }
  
  cout << Ans << endl;
  return 0;
}

//tle