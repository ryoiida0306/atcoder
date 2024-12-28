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
    ll n, m;
    cin >> n >> m;
    map<ll, map<ll,char>> x, y;

    rep(i,m){
        ll a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;

        x[a][-b] = c;
        y[b][-a] = c;
    }

    // x

    ll xmax = LINF;

    for(auto [key, value] : x){
        int xstate = 0;
        for(auto [key2, value2] : value){
            ll b = -key2;
            char c = value2;
            if(xstate == 0){
                if(c == 'W'){
                    xmax = min(xmax, b-1);
                    continue;
                }else{
                    if(xmax < b){
                        cout << "No" << endl;
                        cerr << "x" << endl;
                        cerr << "a = " << key << " b = " << b << " c = " << c << endl;
                        return 0;
                    }
                    xstate = 1;
                    continue;
                }
            }
            if(xstate == 1){
                if(c == 'B'){
                    continue;
                }else{
                    cout << "No" << endl;
                    cerr << "x" << endl;
                    cerr << "a = " << key << " b = " << b << " c = " << c << endl;
                    return 0;
                }
            }
        }
        
    }

    // y

    ll ymax = LINF;

    for(auto [key, value] : y){
        int ystate = 0;
        for(auto [key2, value2] : value){
            ll a = -key2;
            char c = value2;

            if(ystate == 0){
                if(c == 'W'){
                    ymax = min(ymax, a-1);
                    continue;
                }else{
                    if(ymax < a){
                        cout << "No" << endl;
                        cerr << "y" << endl;
                        cerr << "b = " << key << " a = " << a << " c = " << c << endl;
                        return 0;
                    }
                    ystate = 1;

                    continue;
                }
            }
            if(ystate == 1){
                if(c == 'B'){
                    continue;
                }else{
                    cout << "No" << endl;
                    cerr << "y" << endl;
                    cerr << "b = " << key << " a = " << a << " c = " << c << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
}