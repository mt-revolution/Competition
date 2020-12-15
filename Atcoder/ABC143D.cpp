#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N;
    cin >> N;
    
    vector<long long> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    // 昇順ソート
    sort(L.begin(), L.end());

    long long ng;
    long long answer = 0;
    
    // 大きい棒を2つ決めて、三角形の成立条件から最小の棒を二分探索
    for (int i = N-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            auto iter = lower_bound(L.begin(), L.end(), L[i]+L[j]);
            ng = L.end() - iter;
            answer += (N-1 - i) - ng;
        }
    }

    cout << answer << endl;
	return 0;
}