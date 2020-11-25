#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
    cin >> N >> M;
    
    vector<long long> H(N);
    vector<long long> W(M);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> W[i];
    }

    // Hを昇順ソートしておく
    sort(H.begin(), H.end());

    vector<long long> H_sum_1((N+1)/2, 0), H_sum_2((N+1)/2, 0);

    // 初項から順番にペアを作った場合の累積和
    for (int i = 1; i < (N+1)/2; i++) {
        H_sum_1[i] = H_sum_1[i-1] + abs(H[2*(i-1)]-H[2*i-1]);
    }
    // 1つずれて順番にペアを作った場合の累積和
    for (int i = 1; i < (N+1)/2; i++) {
        H_sum_2[i] = H_sum_2[i-1] + abs(H[2*i-1]-H[2*i]);
    }

    int index;
    long long answer = 10000000000000;

    for (int i = 0; i < M; i++) {
        // Wの各値が入るところを二分探索して位置を取得
        index = lower_bound(H.begin(), H.end(), W[i]) - H.begin();
    
        // 奇数の場合1ひく
        if (index & 1) {
            index ^= 1;
        }

        // 累積和から値を計算
        answer = min(answer, H_sum_1[index/2] + H_sum_2[(N-1)/2] - H_sum_2[index/2] + abs(H[index] - W[i]));
    }

    cout << answer << endl;
	return 0;
}