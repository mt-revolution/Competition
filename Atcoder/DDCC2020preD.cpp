#include<bits/stdc++.h>

using namespace std;

int main() {
    int M;
    cin >> M;

    long long d,c;
    long long sum = 0, digit_count = 0, carry_count, answer;

    // 各桁の数の和と桁数を調べる
    for (int i = 0; i < M; i++) {
        cin >> d >> c;
        sum += d*c;
        digit_count += c;
    }

    // 各桁の数の和の繰り上がりの数を調べる
    if (sum % 9 == 0) {
        carry_count = sum / 9 - 1;
    } else {
        carry_count = sum / 9;
    }

    answer = digit_count - 1 + carry_count;

    cout << answer << endl;
	return 0;
}