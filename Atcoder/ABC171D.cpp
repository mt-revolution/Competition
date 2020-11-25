#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    long long A,B,C;
    long long sum = 0;

    // 数列の各数字の数と和をカウント
    vector<int> num_count(100001, 0);
    for (int i = 0; i < N; i++) {
        cin >> A;
        num_count[A] += 1;
        sum += A;
    }

    int Q;
    cin >> Q;

    // Q個のクエリを処理
    for (int i = 0; i < Q; i++) {
        cin >> B >> C;
        sum = sum - B * num_count[B] + C * num_count[B];
        num_count[C] += num_count[B];
        num_count[B] = 0;

        cout << sum << endl;
    }

	return 0;
}