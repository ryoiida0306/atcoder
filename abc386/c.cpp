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
int main() {
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;

    if(s == t){
        cout << "Yes" << endl;
        cerr << "s == t" << endl;
        return 0;
    }

    int n = s.size(), m = t.size();

    if (abs(n - m) > 1) {
        cout << "No" << endl;
        cerr << "abs(n - m) > 1" << endl;
        return 0;
    }

    //insert
    if (n + 1 == m) {
        string tmp;
        rep(i, n){
            if(s[i] == t[i]){
                tmp += s[i];
                if(i == n-1) tmp += t[i+1];
            }else{
                tmp += t[i];
                tmp += s.substr(i, (int)s.size()-i);
                break;
            }
        }
        if(tmp == t){
            cout << "Yes" << endl;
            cerr << "insert" << endl;
            cerr << tmp << endl;
            return 0;
        }
    }

    //erase
    if (n - 1 == m) {
        string tmp;
        rep(i, m){
            if(s[i] == t[i]){
                tmp += s[i];
            }else{
                tmp += s.substr(i+1, (int)s.size()-i-1);
                break;
            }
        }
        if(tmp == t){
            cout << "Yes" << endl;
            cerr << "erase" << endl;
            return 0;
        }
    }

    if (n == m) {
        int diff_count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) ++diff_count;
            if (diff_count > 1) break;
        }
        if (diff_count == 1) {
            cout << "Yes" << endl;
            cerr << "diff_count == 1" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    cerr << "No" << endl;
    return 0;
}
