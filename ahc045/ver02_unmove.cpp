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
using vvvi = vector<vector<vector<int>>>;
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
using mytpl = tuple<int,int,int,int>;
int main(){
    int n, m, q, l ,w;
    cin >> n >> m >> q >> l >> w;

    vi g(m); rep(i,m) cin >> g[i];

    vvi range(n, vi(4));

    rep(i,n) cin >> range[i][0] >> range[i][1] >> range[i][2] >> range[i][3];


    vvi c(m);
    vector<vector<P>> ab(m);

    sort(g.rbegin(), g.rend());


    rep(i, m){
        c[i].resize(g[i]);
        ab[i].resize(g[i]-1);
    }

    int sum = 0;
    rep(i,m){

        rep(j,g[i]) c[i][j] = sum + j;

        cout << "?" << " ";

        int query_size = min(g[i], l);
        cout << query_size << " ";
        rep(j,query_size){
            cout << c[i][j] << " ";
        }
        cout << endl;


        rep(j, query_size-1){
            int a, b; cin >> a >> b;

            ab[i][j] = make_pair(a, b);
        }

        for(int j = query_size-1; j < g[i]-1; j++){
            ab[i][j] = make_pair(sum+j, sum+j+1);
        }


        sum += g[i];
    }

    cout << "!" << endl;
    rep(i,m){
        for(auto cc : c[i]){
            cout << cc << " ";
        }
        cout << endl;

        for(auto aa : ab[i]){
            cout << aa.first << " " << aa.second << endl;
        }
    }


    return 0;
}