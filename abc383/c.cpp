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
using mytpl = tuple<int,int>;
int main(){
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> mp(h);

    rep(i,h) cin >> mp[i];

    vvi dist(h, vi(w, INF));
    rep(i,h)rep(j,w){
        if (mp[i][j] == 'H'){
            dist[i][j] = 0;
        }
    }

    priority_queue<mytpl> pq;

    rep(i,h)rep(j,w){
        if (mp[i][j] == 'H'){
            pq.push(make_tuple(i,j));
        }
    }

    while(!pq.empty()){
        auto [x, y] = pq.top();
        pq.pop();

        if (dist[x][y] + 1 > d) continue;
        rep(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (mp[nx][ny] == '#') continue;
            if (dist[nx][ny] <= dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            pq.push(make_tuple(nx, ny));
        }

    }

    int ans = 0;
    rep(i,h)rep(j,w){
        if (dist[i][j] <= d){
            ans++;
        }
    }

    cout << ans << endl;



}