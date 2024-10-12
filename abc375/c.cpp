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
    int n;
    cin >> n;

    vs s(n);
    rep(i,n){
        cin >> s[i];
    }

    rep(i,n/2){
        int x = i, y = i;
        auto f = [&](int x, int y){
            rep(j,(i+1)%4){
                swap(s[(n-1)-y][x], s[(n-1)-x][(n-1)-y]);
                swap(s[(n-1)-x][(n-1)-y], s[y][(n-1)-x]);
                swap(s[y][(n-1)-x], s[x][y]);
            }
            return 0;
        };

        rep(j,n/2-i){
            if(j == 0){
                f(x,y);
                continue;
            }
            f(x+j,y);
            f(x,y+j);
        }
    }

    rep(i,n){
        cout << s[i] << endl;
    }
    return 0;
}