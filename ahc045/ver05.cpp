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
using mytpl = tuple<int,int,int>;
int main(){

    // clock_t start = clock();


    int n, m, q, l ,w;
    cin >> n >> m >> q >> l >> w;

    vector<P> g(m);
    rep(i,m){
        int gi; cin >> gi;
        g[i] = make_pair(gi, i);
    }

    vvi range(n, vi(4));

    rep(i,n) cin >> range[i][0] >> range[i][1] >> range[i][2] >> range[i][3];


    vvi c(m);
    vector<vector<P>> ab(m);

    sort(g.rbegin(), g.rend());


    // rep(i, m){
    //     c[i].resize(g[i]);
    //     ab[i].resize(g[i]-1);
    // }


    vvi dist(n, vi(n, INF));
    rep(i,n) dist[i][i] = 0;

    // hash<ll> hasher;

    random_device rnd;
    mt19937 mt(rnd());

    rep(i,n)rep(j,n){
        if(i == j) continue;
        // x100 sampling 
        double d_sum = 0;
        int sample_size = 10;
        uniform_int_distribution<> rand100x1(range[i][0], range[i][1]);
        uniform_int_distribution<> rand100y1(range[i][2], range[i][3]);
        uniform_int_distribution<> rand100x2(range[j][0], range[j][1]);
        uniform_int_distribution<> rand100y2(range[j][2], range[j][3]);
        rep(k,sample_size){
            // long long seed = ((long long)i << 32) | (j << 16) | k;
            // unsigned long long hashed = hasher(seed);
            // int x1 = range[i][0] + (hashed % (range[i][1] - range[i][0] + 1));
            // int y1 = range[i][2] + ((hashed >> 10) % (range[i][3] - range[i][2] + 1));
            // int x2 = range[j][0] + ((hashed >> 20) % (range[j][1] - range[j][0] + 1));
            // int y2 = range[j][2] + ((hashed >> 30) % (range[j][3] - range[j][2] + 1));
            int x1 = rand100x1(mt);
            int y1 = rand100y1(mt);
            int x2 = rand100x2(mt);
            int y2 = rand100y2(mt);

            d_sum += sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        }
        dist[i][j] = (int)(d_sum / sample_size);
    }

    // rep(i,n)rep(j,n){
    //     if(i == j) continue;
    //     // average?
    //     int x1 = (range[i][0] + range[i][1]) / 2;
    //     int y1 = (range[i][2] + range[i][3]) / 2;
    //     int x2 = (range[j][0] + range[j][1]) / 2;
    //     int y2 = (range[j][2] + range[j][3]) / 2;
    //     dist[i][j] = (int)sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    // }



    priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq; // (dist, (from, to))
    rep(i,n)for(int j = i; j < n; j++){
        if(i == j) continue;
        pq.push({dist[i][j], {i, j}});
    }

    vb difinited(n, false);
    int g_idx = 0;
    
    while((int)pq.size()){
        if(g[g_idx].first < 2) break;
        auto [d, p] = pq.top();
        pq.pop();
        auto [u, v] = p;
        if(difinited[u] || difinited[v]) continue;

        difinited[u] = true;
        difinited[v] = true;
        c[g[g_idx].second].push_back(u);
        c[g[g_idx].second].push_back(v);
        ab[g[g_idx].second].push_back({u, v});

        vi to_u = dist[u];
        vi to_v = dist[v];
        vector<mytpl> to_uv(n,{INF, INF, INF});

        rep(i,n){
            if(difinited[i]) continue;
            // if(i == u || i == v) continue;
            to_uv[i] = {min(to_u[i], to_v[i]), i, (to_u[i] < to_v[i] ? u : v)};
        }

        sort(to_uv.begin(), to_uv.end());

        int baffa_size = 800;
        vi baffa(baffa_size, get<1>(to_uv[0]));
        int baffa_idx = 0;

        rep(i,g[g_idx].first-2){
            auto [d, w, z] = to_uv[i];
            c[g[g_idx].second].push_back(w);
            int min_u = z;
            int min_dist = d;
            int min_idx = 0;
            rep(j, baffa_size){
                if(min_dist > dist[w][baffa[j]]){
                    min_dist = dist[w][baffa[j]];
                    min_u = baffa[j];
                    min_idx = j;
                }
            }
            baffa[baffa_idx++] = w;
            if(w == min_u){
                min_u = z;
            }
            ab[g[g_idx].second].push_back({w, min_u});
            difinited[w] = true;
        }

        g_idx++;


    }

    int tmp = 0;

    for(int i = g_idx; i < m; i++){
        while(tmp < n && difinited[tmp]) tmp++;
        if(g[i].first != 1){
            cout << "error" << endl;
            return 0;
        }
        c[g[i].second].push_back(tmp);
        difinited[tmp] = true;
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



    // clock_t end = clock();
    // cout << "time: " << (double)(end - start) / CLOCKS_PER_SEC << " sec." << endl;



    return 0;

}