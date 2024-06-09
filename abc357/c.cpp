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

int main(){
  int n;
  cin >> n;
  
  vector<int> mypow(8);
  mypow[0] = 1;
  rep(i,8){
    if(i == 0)continue;
    mypow[i] = mypow[i-1] * 3;
  }
  
  vector<vector<char>> carpet(mypow[6],vector<char>(mypow[6],'#'));
  
  rep(m,6){
    for(int i = mypow[m]; i < (int)carpet.size(); i+=mypow[m+1]){
      for(int j = mypow[m]; j < (int)carpet.size(); j+=mypow[m+1]){
        for(int k = i; k < mypow[m]+i; k++){
          for(int l = j; l < mypow[m]+j; l++){
            carpet[k][l] = '.';
          }
        }
      }
    }
  }
  
  rep(i,mypow[n]){
    rep(j,mypow[n]) cout << carpet[i][j];
    cout << endl;
  }
  return 0;
}