#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,M;
    cin >> N >> M;
    
    priority_queue<long long> A;
    long long num;

    for (int i = 0; i < N; i++) {
        cin >> num;
        A.push(num);
    }

    // Mが0になるまで続ける
    while (M != 0) {
        // 一番高い値段を取り出す
        num = A.top();
        A.pop();

        // Mの許す限り、または2番目に高い値段より低くなるまで2で割る
        while (num >= A.top() && M != 0) {
            num /= 2;
            M--;
        }

        // 再度格納
        A.push(num);
    }

    long long answer = 0;

    // キューから値を取り出して足す
    for (int i = 0; i < N; i++) {
        answer += A.top();
        A.pop();
    }

    cout << answer << endl;
	return 0;
}