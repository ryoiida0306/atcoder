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
  int n;
  cin >> n;
  vl a(n);
  vi keta(15);
  rep(i,n)cin >> a[i];
  vl mypow(15,0);
  ll my = 1;
  rep(i,15){
    mypow[i] = my;
    my *= 10;
  }
  // rep(i,15) cerr << mypow[i] << endl;
  rep(i,n){
    // int k = 0;
    rep(k,15){
      if(a[i] / mypow[k] == 0){
        keta[k]++;
        break;
      }
    }
  }
  // rep(i,15) cerr << keta[i] << endl;
  
  vl backa(n);
  ll sum = 0;
  rrep(i,n){
    if(i == n-1)continue;
    sum += a[i+1];
    backa[i] = sum;
  }
  // rep(i,n) cerr << backa[i] << endl;
  
  mint ans = 0;
  rep(i,n-1){
    rep(k,15){
      if(a[i] / mypow[k] == 0){
        keta[k]--;
        break;
      }
    }
    // rep(j,15) cerr << keta[j] << endl;
    rep(j,15){
      // if(keta[j] == 0)continue;
      ans += (int)((mypow[j] * a[i] * keta[j]) % 998244353L);
      // cerr << mypow[j] << " " << a[i] << " " << keta[j] << endl;
    }
    // cout << keta[j].
    ans += backa[i];
    // cerr << ans.val() << endl;
  }
  cout << ans.val() << endl;
  return 0;
}

//wa