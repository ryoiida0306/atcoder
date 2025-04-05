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
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--; c--; d--;

    priority_queue<mytpl> que;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    vector<vector<ll>> dist(h, vector<ll>(w, LINF));
    dist[a][b] = 0;
    que.push({0, a, b});

    while(!que.empty()){
        auto [cost, x, y] = que.top(); que.pop();
        cost = -cost;
        if(used[x][y]) continue;
        used[x][y] = true;
        if(dist[x][y] < cost) continue;
        dist[x][y] = cost;

        if(x == c && y == d){
            cout << cost << endl;
            // for(auto x : dist){
            //     for(auto y : x){
            //         cout << y << " ";
            //     }
            //     cout << endl;
            // }
            return 0;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            // if(s[nx][ny] == '#') continue;
            if(used[nx][ny]) continue;
            if(s[nx][ny] == '#'){
                que.push({-(cost + 1), nx, ny});
                nx += dx[i];
                ny += dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(used[nx][ny]) continue;
                que.push({-(cost + 1), nx, ny});

            }else{
                que.push({-cost, nx, ny});
            }
        }

    }
}