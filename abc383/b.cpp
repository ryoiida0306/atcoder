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
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> mp(h);

    rep(i,h) cin >> mp[i];

    int ans = 0;

    rep(x1,h)rep(y1,w)rep(x2,h)rep(y2,w){
        if (x1 == x2 && y1 == y2) continue;
        if (mp[x1][y1] == '#' || mp[x2][y2] == '#') continue;
        int res = 0;
        rep(i,h)rep(j,w){
            if (abs(x1 -i) + abs(y1 - j) <= d || abs(x2 - i) + abs(y2 - j) <= d){
                if (mp[i][j] == '#') continue;
                res++;
            }
        }
        ans = max(ans, res);
    }

    cout << ans << endl;


}