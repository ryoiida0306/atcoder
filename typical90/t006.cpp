#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<char,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n,k;
  string s;
  cin >> n >> k >> s;
  int ss = s.size();
  priority_queue<P,vector<P>,greater<P>> strp;
  rep(i,ss-k+1) strp.push(P(s[i],i));
  
  int now = -1;
  string t;
  for(int i = (int)s.size()-k+1;i <= (int)s.size();i++){
    P p;
    rep(j,(int)s.size()){
      p = strp.top();
      strp.pop();
      if(p.second>=now)break;
    }
    cerr << p.first << " " << p.second << " " << now << endl;
    now = p.second;
    t = t + p.first;
    strp.push(P(s[i],i));
  }
  
  cout << t << endl;
  return 0;
}
