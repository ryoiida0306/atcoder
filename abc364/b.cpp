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
  int h, w;
  cin >> h >> w;
  int si, sj;
  cin >> si >> sj;
  si--;sj--;
  
  
  vector<string> c(h);
  rep(i,h){
    cin >> c[i];
  }
  
  string x;
  cin >> x;
  
  int ni = si;
  int nj = sj;
  
  rep(i,(int)x.size()){
    char xx = x[i];
    if(xx == 'L'){
      if(nj - 1 < 0) continue;
      if(c[ni][nj-1] == '.') nj--;
    }
    if(xx == 'R'){
      if(nj + 1 >= w) continue;
      if(c[ni][nj+1] == '.') nj++;
    }
    if(xx == 'U'){
      if(ni - 1 < 0) continue;
      if(c[ni-1][nj] == '.') ni--;
    }
    if(xx == 'D'){
      if(ni + 1 >= h) continue;
      if(c[ni+1][nj] == '.') ni++;
    }

  }
  
  ni++;nj++;
  cout << ni << " " << nj << endl;
  return 0;
}