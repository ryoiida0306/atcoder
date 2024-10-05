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

double doublemin(double a, double b){
    return a < b ? a : b;
}

int main(){
    int n;
    double s, t;
    cin >> n >> s >> t;

    vector<vector<pair<double,double>>> v(n);
    rep(i, n){
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i] = {make_pair(a,b), make_pair(c,d)};
    }

    double ans = INF;

    sort(v.begin(), v.end());

    do{
        rep(i, 1 << n){
            vector<vector<pair<double,double>>> now = v;
            rep(j, n){
                if(i >> j & 1){
                    swap(now[j][0], now[j][1]);
                }
            }
            pair<double,double> prev = {0, 0};
            double time = 0;
            rep(j, n){
                pair<double,double> a = now[j][0];
                pair<double,double> b = now[j][1];
                double dist = sqrt((a.first - prev.first) * (a.first - prev.first) + (a.second - prev.second) * (a.second - prev.second));
                time += dist / s;
                dist = sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
                time += dist / t;
                prev = b;
            }
            ans = doublemin(ans, time);
        }

    }while(next_permutation(v.begin(), v.end()));

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}