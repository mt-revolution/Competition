#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
    cin >> N >> M;

    vector<int> P(M+1);

    for(int i = 1; i <= M; i++) {
        cin >> P[i];
    }

    vector<long long> A(N), B(N), C(N);

    for(int i = 1; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    // 鉄道ごとの乗る回数
    vector<long long> ride(N+1, 0);

    // いもす法
    for(int i = 1; i < M; i++) {
        ride[min(P[i], P[i+1])] += 1;
        ride[max(P[i], P[i+1])] -= 1;
    }

    for(int i = 1; i <= N; i++) {
        ride[i] += ride[i-1];
    }

    long long answer = 0;

    for(int i = 1; i < N; i++) {
        // 切符を買った方が安い場合
        if(ride[i] * A[i] < ride[i] * B[i] + C[i]) {
            answer += ride[i] * A[i];
            
        // ICカードを買った方が安い場合
        } else {
            answer += ride[i] * B[i] + C[i];
        }
    }

    cout << answer << endl;
	return 0;
}