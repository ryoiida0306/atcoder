#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
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
    int h, w; cin >> h >> w;
    vvc s(h, vc(w)); rep(i,h) rep(j,w) cin >> s[i][j];

    int hmin = INF, hmax = -1, wmin = INF, wmax = -1;
    rep(i,h) rep(j,w){
        if(s[i][j] == '#'){
            hmin = min(hmin, i);
            hmax = max(hmax, i);
            wmin = min(wmin, j);
            wmax = max(wmax, j);
        }
    }

    rep(i,h) rep(j,w){
        if(i < hmin || i > hmax) continue;
        if(j < wmin || j > wmax) continue;

        if(s[i][j] == '.') {
            cout << "No" << endl;
            return 0;
        }
        // cout << s[i][j];
        // if(j == wmax) cout << endl;
    }
    cout << "Yes" << endl;
    return 0;
}