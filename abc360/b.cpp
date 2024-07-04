#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
// #define all(a) (a).begin, (a).end()
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vsi = vector<set<int>>;
using vsl = vector<set<ll>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mytpl = tuple<ll,int,int>;

int main(){
  string s,t;
  cin >> s >> t;
  for(int c = 1; c<(int)s.size(); c++){
    for(int w = c; w<(int)s.size(); w++){
      string ss = s;
      vector<string> S;
      rep(i,(int)s.size()/w +1){
        S.push_back(ss.substr(i*w,w));
      }
      // rep(i,(int)S.size()){
      //   cerr << S[i] << endl;
      // }
      // cerr << endl;
      string ans = "";
      rep(i,(int)S.size()){
        if((int)S[i].size() >= c){
          ans += S[i][c-1];
        }
      }
      if(ans == t){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}