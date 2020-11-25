#include<bits/stdc++.h>

using namespace std;

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> prime;
    long long tmp, count;

    tmp = N;

    for (long long a = 2; a * a <= N; a++) {
        if (tmp % a != 0) {
            continue;
        }

        count = 0; // 指数

        // 割れる限り割り続ける
        while (tmp % a == 0) {
            count++;
            tmp /= a;
        }

        // その結果を push
        prime.push_back(make_pair(a, count));
    }

    // 最後に残った数について
    if (tmp != 1) {
        prime.push_back({tmp, 1});
    }
    return prime;
}

int main() {
    long long N;
    cin >> N;

    vector<pair<long long, long long>> prime = prime_factorize(N);

    long long count = 0;
    
    // 素因数とその乗数のペアについて、より小さい素因数、より小さい乗数から割っていきカウントする
    for (auto pair : prime) {
        // より小さい乗数から
        for (int i = 1; ; i++) {
            if (pair.second < i) {
                break;
            }

            pair.second -= i;
            count++;
        }
    }

    cout << count << endl;
	return 0;
}