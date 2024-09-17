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
    int n, m, T, la, lb;
    cin >> n >> m >> T >> la >> lb;
    vector<set<int>> g(n);
    vector<int> t(T);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    rep(i,T) cin >> t[i];

    vector<vector<pair<int,vector<int>>>> dist(n, vector<pair<int,vector<int>>>(n, {INF, vector<int>({})}));
    rep(i,n) dist[i][i] = {0, {i}};
    rep(i,n) for(int j : g[i]) dist[i][j] = {1, {i, j}};
    rep(k,n) rep(i,n) rep(j,n){
        if(dist[i][j].first > dist[i][k].first + dist[k][j].first){
            dist[i][j].first = dist[i][k].first + dist[k][j].first;
            dist[i][j].second.clear();
            for(int x : dist[i][k].second) dist[i][j].second.push_back(x);
            dist[i][j].second.pop_back();
            for(int x : dist[k][j].second) dist[i][j].second.push_back(x);
        }
    }

    set<int> a_set;

    rep(i,T-1){
        int a = t[i], b = t[i+1];
        for(int x : dist[a][b].second){
            a_set.insert(x);
        }
    }

    vi a_vec(a_set.begin(), a_set.end());
    for(int i = (int)a_vec.size(); i < la; ++i){
        a_vec.push_back(0);
    }

    // sort(a_vec.begin(), a_vec.end());
    // reverse(a_vec.begin(), a_vec.end());
    vector<int> path;
    int v = 0;
    rep(i,T){
        for(int x : dist[v][t[i]].second){
            path.push_back(x);
        }
        v = t[i];
        path.pop_back();
    }
    path.push_back(v);

    // for(int x : path){
    //     cerr << x << " ";
    // }
    // cerr << endl;

    vector<int> counting(n,0);
    for(int x : path){
        counting[x]++;
    }

    priority_queue<pair<int,int>> pq;
    rep(i,n){
        pq.push({counting[i], i});
    }

    for(int x : a_vec){
        cout << x << " ";
    }
    cout << endl;

    vi b_vec(lb,-1);

    // rep(i,lb/2){
    //     auto [cnt1, a1] = pq.top(); pq.pop();
    //     b_vec[i] = a1;
    // }


    // for(int x : b_vec){
    //     cerr << x << " ";
    // }
    // cerr << endl;

    rep(i,(int)path.size()){
        if(i == 0) continue;
        int cnt = count(b_vec.begin(), b_vec.end(), path[i]);
        if(cnt == 0){
            int itr = 0;
            while(itr < la){
                if(a_vec[itr] == path[i]){
                    int l = min(la-itr, lb-lb/2);
                    int pa = itr;
                    int pb = 0;
                    // int pb = lb/2;
                    cout << "s " << l << " " << pa << " " << pb << endl;
                    for(int j = itr; j < itr + l ; ++j){
                        b_vec[j - itr + pb] = a_vec[j];
                    }
                    // for(int j = 0; j < lb; ++j){
                    //     cerr << b_vec[j] << " ";
                    // }
                    // cerr << endl;
                    break;
                }
                itr++;
            }
        }


        cout << "m " << path[i] << endl;

    }

    return 0;


}