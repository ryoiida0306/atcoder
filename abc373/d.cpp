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
ll LINF = 1e18;
using mytpl = tuple<ll,int,int>;
int main(){
    int n, m;
    cin >> n >> m;
    vi u(m), v(m), w(m);
    rep(i,m){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
    }
    vector<map<int,int>> mp(n);
    rep(i,m){
        mp[u[i]][v[i]] = w[i];
        mp[v[i]][u[i]] = -w[i];
    }

    vb visited(n, false);
    vl x(n, LINF);

    rep(i,n){
        if(visited[i]) continue;
        visited[i] = true;
        x[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int j = q.front();
            q.pop();
            for(auto p : mp[j]){
                int k = p.first;
                int c = p.second;
                if(visited[k]){
                    x[j] = x[k] - c;
                }
            }

            for(auto p : mp[j]){
                int k = p.first;
                int c = p.second;
                if(visited[k]) continue;
                x[k] = x[j] + c;
                visited[k] = true;
                q.push(k);
            }
        }


        
    }
    rep(i,n){
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}