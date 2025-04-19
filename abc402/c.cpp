#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> recipe(M);
    vector<int> remain(M);
    vector<vector<int>> usedIn(N);
    for (int i = 0; i < M; ++i) {
        int K;
        cin >> K;
        recipe[i].resize(K);
        remain[i] = K;
        for (int j = 0; j < K; ++j) {
            int a;
            cin >> a;
            a--;
            recipe[i][j] = a;
            usedIn[a].push_back(i);
        }
    }

    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        B[i]--;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int ingredient = B[i];
        for (int dish : usedIn[ingredient]) {
            remain[dish]--;
            if (remain[dish] == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
