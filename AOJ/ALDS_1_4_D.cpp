#include<bits/stdc++.h>

using namespace std;

int n,k;
vector<long long> w;

// 最大積載量がPのときに積載できるか判定
bool load(long long P) {
    int i = 0;
    long long sum = 0;
    
    // k台のトラックに許容量まで荷物を積んでいく
    for (int j = 0; j < k; j++) {
        sum = 0;
        while (sum + w[i] <= P) {
            sum += w[i];
            i++;

            // 最後の荷物を積み終えたとき
            if (i == n) {
                return true;
            }
        }
    }

    // 最後の荷物に到達しなかったとき
    return false;
}

int main() {
    cin >> n >> k;
    
    w.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // 二分探索
    long long left = 0;
    long long right = 10000000000;
    long long mid;

    while (right - left > 1) {
        mid = (left + right)/2;

        if (load(mid) == true) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;
    return 0;
}