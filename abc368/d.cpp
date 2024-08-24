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
    int n, k;
    cin >> n >> k;
    vector<set<int>> g(n+1);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    set<int> vSet;
    int vx = -1;
    rep(i,k){
        int v;
        cin >> v;
        vx = v;
        vSet.insert(v);
    }

    g[vx].insert(0);
    g[0].insert(vx);

    set<int> ansSet;

    auto f = [&](auto f, int v, int p) -> bool{
        bool ok = false;
        for(auto u : g[v]){
            if(u == p) continue;
            ok |= f(f, u, v);
        }
        if(ok){
            ansSet.insert(v);
            return true;
        }else{
            if(vSet.count(v)){
                ansSet.insert(v);
                return true;
            }
        }
        return false;
    };

    f(f, vx, 0);

    cout << ansSet.size() << endl;

    return 0;

    
}