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
  int h,w;
  cin >> h >> w;
  int q;
  cin >> q;
  dsu d(h*w+3);//i*h+w
  vvi table(h,vector<int>(w,0));
  rep(i,q){
    int t, ra, ca;
    cin >> t >> ra >> ca;
    ra--;ca--;
    if(t == 1){
      table[ra][ca] = 1;
      vector<P> diff;
      diff.push_back(P(1,0));
      diff.push_back(P(0,1));
      diff.push_back(P(-1,0));
      diff.push_back(P(0,-1));
      for(auto p : diff){
        int nh = ra + p.first;
        int nw = ca + p.second;
        if(nh<0)continue;
        if(nh>=h)continue;
        if(nw<0)continue;
        if(nw>=w)continue;
        if(table[nh][nw] != 1)continue;
        d.merge(ra*w+ca,nh*w+nw);
      }
    }
    if(t == 2){
      int rb, cb;
      cin >> rb >> cb;
      rb--;cb--;
      if(P(ra,ca) == P(rb,cb)){
        if(table[ra][ca] == 1){
          cout << "Yes" << endl;
        }else{
          cout << "No" << endl;
        }
        continue;
      }
      if(d.same(ra*w+ca,rb*w+cb)){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
    // rep(i,h){
    //   rep(j,w) cerr << table[i][j] << " ";
    //   cerr << endl;
    // }
    // cerr << endl;
  }
  return 0;
}


