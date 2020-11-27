#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<long long> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }

    long long answer = -2000000000;
    // 走査している時点でのR[i]の最小値
    long long min_R = R[0];

    for (int i = 1; i < n; i++) {
        // 答えの更新
        answer = max(answer, R[i] - min_R);
        // R[i]の最小値の更新
        min_R = min(min_R, R[i]);
    }

    cout << answer << endl;
    return 0;
}