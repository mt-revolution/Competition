#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    vector<long long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Aを降順ソート
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    // 可能な最大なの心地よさ
    vector<long long> A_max;

    // 一番大きい値は1回
    A_max.push_back(A[0]);

    // それ以降は高々2回
    for (int i = 1; i < N; i++) {
        A_max.push_back(A[i]);
        A_max.push_back(A[i]);
    }

    long long answer = 0;

    // 答えはA_maxの最初のN-1項の和
    for (int i = 0; i < N-1; i++) {
        answer += A_max[i];
    }

    cout << answer << endl;
	return 0;
}