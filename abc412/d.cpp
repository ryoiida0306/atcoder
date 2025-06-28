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



int solve(int &n, int &m, vvb &G, vi v){
    sort(v.begin(), v.end());
    int res = INF;
    int vs = (int)v.size();
    int vt = 0;
    rep(i, vs)rep(j, vs){
        if(i == j) continue;
        if(G[v[i]][v[j]]) vt++;
    }
    vt /= 2;
    do {
        int ress = 0;
        rep(i, vs){
            if(G[v[i]][v[(i+1)%vs]]) ress++;
        }
        res = min(res, vs + vt - 2*ress);
    } while (next_permutation(v.begin(), v.end()));
    return res;
}

int gg(int &n, int &m, vvb &G, vi v, vi w){
    int res = 0;
    int vs = (int)v.size();
    int ws = (int)w.size();
    rep(i, vs)rep(j, ws){
        if(G[v[i]][w[j]]) res++;
    }
    return res;
}

int main(){
    int n, m; cin >> n >> m;

    vvb G(n, vb(n, false));

    rep(i, m) {
        int a, b; cin >> a >> b; --a; --b;
        G[a][b] = true;
        G[b][a] = true;
    }

    int ans = INF;
    if(n == 8){
        vi v = {0, 0, 0, 0, 0, 1, 1, 1};
        do{
            vi w, x;
            rep(i, 8){
                if(v[i] == 0) w.push_back(i);
                else x.push_back(i);
            }
            int res = gg(n, m, G, w, x);
            res += solve(n, m, G, w);
            res += solve(n, m, G, x);
            ans = min(ans, res);
        }while(next_permutation(v.begin(), v.end()));

        vi v2 = {0, 0, 0, 0, 1, 1, 1, 1};
        do{
            vi w, x;
            rep(i, 8){
                if(v2[i] == 0) w.push_back(i);
                else x.push_back(i);
            }
            int res = gg(n, m, G, w, x);
            res += solve(n, m, G, w);
            res += solve(n, m, G, x);
            ans = min(ans, res);
        }while(next_permutation(v2.begin(), v2.end()));

        vi w;
        rep(i, 8) w.push_back(i);
        int res = solve(n, m, G, w);
        ans = min(ans, res);
        
    }

    if(n == 7){
        vi v = {0, 0, 0, 0, 1, 1, 1};
        do{
            vi w, x;
            rep(i, 7){
                if(v[i] == 0) w.push_back(i);
                else x.push_back(i);
            }
            int res = gg(n, m, G, w, x);
            res += solve(n, m, G, w);
            res += solve(n, m, G, x);
            ans = min(ans, res);
        }while(next_permutation(v.begin(), v.end()));

        vi w;
        rep(i, 7) w.push_back(i);
        int res = solve(n, m, G, w);
        ans = min(ans, res);
    }

    if(n == 6){
        vi v = {0, 0, 0, 1, 1, 1};
        do{
            vi w, x;
            rep(i, 6){
                if(v[i] == 0) w.push_back(i);
                else x.push_back(i);
            }
            int res = gg(n, m, G, w, x);
            res += solve(n, m, G, w);
            res += solve(n, m, G, x);
            ans = min(ans, res);
        }while(next_permutation(v.begin(), v.end()));

        vi w;
        rep(i, 6) w.push_back(i);
        int res = solve(n, m, G, w);
        ans = min(ans, res);
    }

    if(n <= 5){
        vi w;
        rep(i, n) w.push_back(i);
        int res = solve(n, m, G, w);
        ans = min(ans, res);
    }

    cout << ans << endl;
    return 0;
}